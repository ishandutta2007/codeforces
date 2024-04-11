// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

struct matrix
{
	LL a[70][70];
	void clear(int x=0){for(int i=0;i<70;i++)for(int j=0;j<70;j++)a[i][j]=Linf*((i!=j)||x==0);}
	matrix(int x=0){clear(x);}
};
matrix operator *(const matrix&a,const matrix&b)
{
	matrix c;
	for(int i=0;i<70;i++)for(int j=0;j<70;j++)for(int k=0;k<70;k++)
		c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}

matrix tpw[30];
int id[1<<8],tot,v[70],n,k,q,x,w[10];

#define getcode(i,j) (((i)>>(j))&1)
matrix getpw(int x)
{
	matrix ret(1);
	for(int i=0;i<30;i++)if(getcode(x,i))ret=ret*tpw[i];
	return ret;
}
int main()
{
	get2(x,k);get2(n,q);
	for(int i=0;i<k;i++)get1(w[i]);
	
	vector<pair<int,pii> >vs;
	for(int i=0,x,w;i<q;i++)
	{
		get2(x,w);
		for(int j=1;j<=k;j++)if(x-j>0&&x-j<=n-::x)
			vs.pb(mp(x-j,mp(j-1,w)));
	}
	
	memset(id,-1,sizeof(id));
	for(int i=0;i<(1<<k);i++)if(__builtin_popcount(i)==x)
	{
//		printf("id= %d v= %d\n",tot,i);
		id[i]=tot;
		v[tot++]=i;
	}
	
	matrix&tran=tpw[0];
	for(int i=0;i<tot;i++)
	{
		if(getcode(v[i],0))
		{
			for(int j=0;j<k;j++)if(getcode(v[i]>>1,j)==0)
			{
				tran.a[i][id[(v[i]>>1)|(1<<j)]]=w[j];
			}
		}
		else tran.a[i][id[v[i]>>1]]=0;
	}
	for(int i=1;i<30;i++)tpw[i]=tpw[i-1]*tpw[i-1];
	
	sort(vs.begin(),vs.end());
	int last=0;matrix all(1);
	for(int i=0,nxt=0;i<(int)vs.size();i=nxt)
	{
		matrix now=tran;
		for(;nxt<(int)vs.size()&&vs[nxt].ff==vs[i].ff;nxt++)
		{
			for(int j=0;j<tot;j++)if(getcode(v[j],0)&&getcode(v[j]>>1,vs[nxt].ss.ff)==0)
				now.a[j][id[(v[j]>>1)|(1<<vs[nxt].ss.ff)]]+=vs[nxt].ss.ss;
		}
		all=all*getpw(vs[i].ff-last-1);
		all=all*now;
		last=vs[i].ff;
	}
	all=all*getpw(n-x-last);
	printf("%I64d\n",all.a[id[(1<<x)-1]][id[(1<<x)-1]]);
	return 0;
}
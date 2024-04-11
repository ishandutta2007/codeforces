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
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

struct query_2
{
	int x,y,yy,coef,id,idx,idy;
}qb[3600111];
int ord[3600111];
bool cmp(int x,int y){return qb[x].x<qb[y].x;}
int tot;
void addquery(int x,int xx,int y,int yy,int id,int idx,int idy)
{
	if(x>xx||y>yy)return;
	qb[tot++]={x-1,y,yy,-1,id,idx,idy};
	qb[tot++]={xx,y,yy,1,id,idx,idy};
}
int n,q,a[200111];
struct query
{
	int x,xx,y,yy,d[3][3],id;
	query(){memset(d,0,sizeof(d));}
	void in()
	{
		get2(x,y);get2(xx,yy);
		addquery(1,x-1,1,y-1,id,0,0);
		addquery(1,x-1,y,yy,id,0,1);
		addquery(1,x-1,yy+1,n,id,0,2);
		addquery(x,xx,1,y-1,id,1,0);
		addquery(x,xx,y,yy,id,1,1);
		addquery(x,xx,yy+1,n,id,1,2);
		addquery(xx+1,n,1,y-1,id,2,0);
		addquery(xx+1,n,y,yy,id,2,1);
		addquery(xx+1,n,yy+1,n,id,2,2);
	}
	void getans()
	{
		LL ans=1ll*d[1][1]*(d[1][1]-1);
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int ii=0;ii<3;ii++)for(int jj=0;jj<3;jj++)
		{
			if(i==ii&&i!=1)continue;
			if(j==jj&&j!=1)continue;
			if(i==ii&&j==jj)continue;
//			if(d[i][j]&&d[ii][jj])printf("ok %d %d %d %d\n",i,j,ii,jj);
			ans+=1ll*d[i][j]*d[ii][jj];
		}
		ans>>=1;
		printendl(ans);
	}
}qa[200111];

int bit[200111];
void add(int x){for(;x<200111;x+=x&-x)bit[x]++;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
void solve()
{
	for(int i=0;i<tot;i++)ord[i]=i;
	sort(ord,ord+tot,cmp);
	int cur=1;
	for(int i=0;i<tot;i++)
	{
		query_2 &t=qb[ord[i]];
		while(cur<=t.x)add(a[cur++]);
		qa[t.id].d[t.idx][t.idy]+=t.coef*(query(t.yy)-query(t.y-1));
	}
}
int main()
{
	get2(n,q);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=q;i++){qa[i].id=i;qa[i].in();}
	solve();
	for(int i=1;i<=q;i++)qa[i].getans();
	return 0;
}
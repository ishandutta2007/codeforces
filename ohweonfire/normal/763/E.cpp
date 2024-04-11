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

const int magic=500;
int n,m,K,q,ql[100111],qr[100111],an[100111];
bool cl[100111][6],cr[100111][6];

int tot,px[100111],py[100111],vx[100111],vy[100111];//px:fa   py:sz
int sz[100111],f[100111],cur;
int gf(int x){return x==f[x]?x:gf(f[x]);}
void un(int x,int y)
{
	x=gf(x);
	y=gf(y);
	if(x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	px[tot]=x;py[tot]=y;vx[tot]=f[x];vy[tot]=sz[y];tot++;
	f[x]=y;sz[y]+=sz[x];
	cur--;
}
void back()
{
	tot--;
	f[px[tot]]=vx[tot];sz[py[tot]]=vy[tot];cur++;
}
void clear()
{
	tot=cur=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		sz[i]=1;
	}
}

vector<pii> qry[100111];
int ans[100111];
int main()
{
	get3(n,K,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		if(u>v)swap(u,v);
		cl[v][v-u]=1;
		cr[u][v-u]=1;
	}
	get1(q);
	for(int i=1;i<=q;i++)
	{
		get2(ql[i],qr[i]);
		qry[ql[i]/magic].pb(mp(qr[i],i));
	}
	for(int i=0;i<100111;i++)
	{
		if(qry[i].size()==0)continue;
		clear();
		sort(qry[i].begin(),qry[i].end());
		int curr=i*magic+magic-1,tmp=curr+1;
		for(int j=0;j<(int)qry[i].size();j++)
		{
			int id=qry[i][j].ss;
			if(qr[id]<tmp)
			{
				for(int k=ql[id];k<=qr[id];k++)
				{
					cur++;
					for(int t=1;t<=5;t++)if(cl[k][t]&&k-t>=ql[id])
						un(k,k-t);
				}
				ans[id]=cur;
				while(tot)back();
				cur=0;
			}
			else
			{
				for(int k=curr+1;k<=qr[id];k++)
				{
					cur++;
					for(int t=1;t<=5;t++)if(cl[k][t]&&k-t>=tmp)
						un(k,k-t);
				}
				curr=qr[id];
				int ttot=tot,tcur=cur;
				for(int k=ql[id];k<tmp;k++)
				{
					cur++;
					for(int t=1;t<=5;t++)if(cr[k][t]&&k+t<=qr[id])
						un(k,k+t);
				}
				ans[id]=cur;
				cur-=tmp-ql[id];
				while(tot!=ttot)back();if(tcur!=cur)puts("baojing");
			}
		}
	}
	for(int i=1;i<=q;i++)printendl(ans[i]);
	return 0;
}
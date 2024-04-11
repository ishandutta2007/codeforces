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
const LL Linf=1ll<<62;
const double pi=acos(-1.0);

int n,pa[100111],f1[20][100111],tp[100111],f2[20][100111],f3[20][100111],dep[100111];

int getlca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=19;i>=0;i--)if(dep[u]-dep[v]>>i)u=f3[i][u];
	if(u==v)return u;
	for(int i=19;i>=0;i--)if(f3[i][u]!=f3[i][v])
	{
		u=f3[i][u];
		v=f3[i][v];
	}
	return f3[0][u];
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)
	{
		int&p=pa[i];
		get2(p,tp[i]);
		if(tp[i]==0)f1[0][i]=p;
		else if(tp[i]==1)f2[0][i]=p;
		f3[0][i]=p;
	}
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)
	{
		f1[i][j]=f1[i-1][f1[i-1][j]];
		f2[i][j]=f2[i-1][f2[i-1][j]];
		f3[i][j]=f3[i-1][f3[i-1][j]];
	}
	for(int i=1;i<=n;i++)if(pa[i]!=-1)dep[i]=dep[pa[i]]+1;else dep[i]=1;
	int q,t,u,v;
	get1(q);
	while(q--)
	{
		get3(t,v,u);
		if(t==1)
		{
			if(dep[u]<=dep[v])puts("NO");
			else
			{
				for(int i=0;i<20;i++)if(u&&(dep[u]-dep[v]>>i)&1)u=f1[i][u];
				if(u==v)puts("YES");
				else puts("NO");
			}
		}
		else
		{
			if(u==v)
			{
				puts("NO");
				continue;
			}
			int lca=getlca(u,v);
			if(lca==u)
			{
				puts("NO");
				continue;
			}
			for(int i=19;i>=0;i--)if((dep[u]-dep[lca]>>i))u=f2[i][u];
			for(int i=19;i>=0;i--)if((dep[v]-dep[lca]>>i))v=f1[i][v];
			if(u==lca&&v==lca)puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
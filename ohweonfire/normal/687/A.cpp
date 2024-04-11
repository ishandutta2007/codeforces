//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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

int n,m,mark[100111];
vector<int> g[100111],v1,v2;
void dfs(int x,int c)
{
	mark[x]=c;
	if(c==1)v1.pb(x);else v2.pb(x);
	for(int i=0;i<(int)g[x].size();i++)
		if(mark[g[x][i]]==0)
			dfs(g[x][i],3-c);
		else if(mark[g[x][i]]==c)
		{
			puts("-1");
			exit(0);
		}
}
int main()
{
	get2(n,m);
	for(int i=1,x,y;i<=m;i++)
	{
		get2(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=n;i++)if(!mark[i])dfs(i,1);
	if(v1.size()==0||v2.size()==0)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",v1.size());
	for(int i=0;i<v1.size();i++)printf("%d ",v1[i]);puts("");
	printf("%d\n",v2.size());
	for(int i=0;i<v2.size();i++)printf("%d ",v2[i]);puts("");
	return 0;
}
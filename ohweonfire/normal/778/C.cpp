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

const int maxn=300111;
vector<int>g[maxn],col[maxn];
int n,ans[maxn],ch[maxn<<1][26],sz[maxn],tn;
int join(int x,int y)
{
	if(x==0||y==0)return x+y;
	int id=++tn;sz[id]=1;
	for(int i=0;i<26;i++)
		sz[id]+=sz[ch[id][i]=join(ch[x][i],ch[y][i])];
	return id;
}
void dfs(int x,int d)
{
	sz[x]=1;
	int mx=0;
	for(int i=0;i<(int)g[x].size();i++)
	{
		ch[x][col[x][i]]=g[x][i];
		dfs(g[x][i],d+1);
		sz[x]+=sz[g[x][i]];
		if(sz[mx]<sz[g[x][i]])mx=g[x][i];
	}
	ans[d]+=sz[x];
	tn=n;
	int cur=mx;
	for(int i=0;i<26;i++)if(ch[x][i]!=mx)cur=join(cur,ch[x][i]);
	ans[d]-=max(1,sz[cur]);
}
int main()
{
	get1(n);
	char ttt[5];
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);scanf("%s",ttt);
		g[u].pb(v);
		col[u].pb(ttt[0]-'a');
	}
	dfs(1,1);
	int x=max_element(ans+1,ans+n+1)-ans;
	printf("%d\n%d\n",n-ans[x],x);
	return 0;
}
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

vector<int> g[300111];
int n,v[300111],ch[300111][26],sz[300111],ans[300111];
char s[300111];
int un(int x,int y)
{
	if(x==0||y==0)return x+y;
	sz[x]=1;
	for(int i=0;i<26;i++)
	{
		ch[x][i]=un(ch[x][i],ch[y][i]);
		sz[x]+=sz[ch[x][i]];
	}
	return x;
}
void dfs(int x,int f=0)
{
	sz[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
			ch[x][s[g[x][i]]-'a']=un(ch[x][s[g[x][i]]-'a'],g[x][i]);
		}
	for(int i=0;i<26;i++)sz[x]+=sz[ch[x][i]];
	ans[x]=sz[x];
}
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(v[i]);
	scanf("%s",s+1);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	int mx=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(mx<ans[i]+v[i])
		{
			mx=ans[i]+v[i];
			cnt=1;
		}
		else if(mx==ans[i]+v[i])cnt++;
	}
	printf("%d\n%d\n",mx,cnt);
	return 0;
}
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

vector<int>g[100111];
int id[100111],dep[100111];
set<int> e[100111];
void dfs(int x,int d=0,int f=0,int id=0)
{
	dep[x]=d;::id[x]=id;
	for(auto v:g[x])if(v!=f)dfs(v,d+1,x,id==0?v:id);
}
bool check(int id,int l,int r){if(l==r)return true;return e[id].lower_bound(dep[l]+1)==e[id].upper_bound(dep[r]);}
int eu[100111],ev[100111],n,m;
int main()
{
	get1(n);for(int i=1;i<n;i++){get2(eu[i],ev[i]);g[eu[i]].pb(ev[i]);g[ev[i]].pb(eu[i]);}
	int rt=1;for(int i=1;i<=n;i++)if(g[i].size()>2)rt=i;
	dfs(rt);
	for(int i=1;i<=n;i++)if(dep[eu[i]]>dep[ev[i]])swap(eu[i],ev[i]);
	get1(m);
	for(int i=1,op,u,v;i<=m;i++)
	{
		get2(op,u);
		if(op==1)e[id[ev[u]]].erase(dep[ev[u]]);
		else if(op==2)e[id[ev[u]]].insert(dep[ev[u]]);
		else
		{
			get1(v);if(dep[u]>dep[v])swap(u,v);
			if(id[u]==id[v])
			{
				if(check(id[u],u,v))printf("%d\n",dep[v]-dep[u]);
				else puts("-1");
			}
			else
			{
				if(check(id[u],rt,u)&&check(id[v],rt,v))printf("%d\n",dep[u]+dep[v]);
				else puts("-1");
			}
		}
	}
	return 0;
}
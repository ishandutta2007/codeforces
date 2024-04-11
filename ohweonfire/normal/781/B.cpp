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

vector<int> g[2222],ng[2222];//0:a 1:b
int n,ans[2222];
string a[2222],b[2222],na[2222],nb[2222];
void addedge(int x,int y)
{
	g[x].pb(y);
	ng[y].pb(x);
}
bool use[2222];
vector<int> v;
int cmp[2222];
void dfs(int x)
{
	use[x]=1;
	for(int i=0;i<(int)ng[x].size();i++)
		if(!use[ng[x][i]])
			dfs(ng[x][i]);
	v.pb(x);
}
void dfs2(int x,int t)
{
	use[x]=1;
	cmp[x]=t;
	for(int i=0;i<(int)g[x].size();i++)
		if(!use[g[x][i]])dfs2(g[x][i],t);
}
bool solve()
{
	for(int i=0;i<2222;i++)if(!use[i])dfs(i);
	memset(use,0,sizeof(use));
	int c=0;
	for(int i=(int)v.size()-1;i>=0;i--)
	{
		if(use[v[i]])continue;
		dfs2(v[i],++c);
	}
	for(int i=1;i<=n;i++)
	{
		if(cmp[i]==cmp[i+n])return false;
		ans[i]=(cmp[i]<cmp[i+n]);
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		na[i]=a[i].substr(0,3);
		nb[i]=a[i].substr(0,2)+b[i][0];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(i==j)continue;
		if(na[i]==na[j])
		{
			addedge(i,i+n);
			addedge(j,j+n);
		}
		if(na[i]==nb[j])
		{
			addedge(i,j);
			addedge(j+n,i+n);
		}
		if(nb[i]==nb[j])
		{
			addedge(i+n,j);
			addedge(j+n,i);
		}
	}
	if(solve())
	{
		cout<<"YES\n";
		for(int i=1;i<=n;i++)cout<<(ans[i]?na[i]:nb[i])<<endl;
	}
	else cout<<"NO";
	return 0;
}
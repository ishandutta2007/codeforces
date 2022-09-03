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

vector<int> g[300111];
int n,m,q,stk[300111],a[300111],dep[300111];
void dfs(int x,int d)
{
	stk[d]=x;dep[x]=d;
	for(auto v:g[x])
	{
		if(!dep[v])dfs(v,d+1);
		else if(dep[v]<dep[x]-1)
		{
			int mn=n,mx=0;
			for(int i=dep[v];i<=dep[x];i++)
			{
				mn=min(mn,stk[i]);
				mx=max(mx,stk[i]);
			}
			a[mn]=min(a[mn],mx-1);
		}
	}
}
LL ans[300111];
int ql[300111],qr[300111];
vector<int> p[300111];
struct BIT
{
	LL bit[300111];
	void add(int x,int v){for(;x<300111;x+=x&-x)bit[x]+=v;}
	LL query(int x){LL ret=0;for(;x;x-=x&-x)ret+=bit[x];return ret;}
}bit0,bit1;
int main()
{
	get2(n,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);g[v].pb(u);
	}
	for(int i=1;i<=n;i++)a[i]=n;
	for(int i=1;i<=n;i++)if(!dep[i])dfs(i,1);
	for(int i=n-1;i>=1;i--)a[i]=min(a[i],a[i+1]);
	get1(q);for(int i=1;i<=q;i++){get2(ql[i],qr[i]);p[ql[i]].pb(i);}
	
	for(int i=n;i>=1;i--)
	{
		bit0.add(a[i],1);
		bit1.add(a[i],a[i]);
		for(auto x:p[i])
		{
			ans[x]=1ll*qr[x]*(qr[x]-ql[x]+1-bit0.query(qr[x]))+bit1.query(qr[x]);
			ans[x]-=1ll*(ql[x]+qr[x]-2)*(qr[x]-ql[x]+1)/2;
		}
	}
	for(int i=1;i<=q;i++)printendl(ans[i]);
	return 0;
}
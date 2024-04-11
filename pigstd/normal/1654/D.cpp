#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=2e5+10;
int n,res,a[M],c[M],b[M],f[M],ans;
vector<pair<int,pii>>e[M];
vector<pii>d[M];

int poww(int a,int b=Mod-2)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void init(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!f[i])
		{
			for (int j=i;j<=n;j+=i)
			{
				int tmp=j,w=0;
				while(tmp%i==0)tmp/=i,w++;
				d[j].pb(mp(i,w));
			}
		}
		for (int j=i*2;j<=n;j+=i)f[j]=1;
	}
}

void dfs(int u,int fa)
{
	ans=(ans+a[u])%Mod;
	for (auto v:e[u])
	{
		if (v.x==fa)continue;
		/*
		u / v.x= v.y.x/v.y.y
		x.v=u*v.y.y/v.y.x
		*/
		a[v.x]=a[u]*v.y.y%Mod*poww(v.y.x)%Mod;
		for (auto x:d[v.y.y])b[x.x]-=x.y;
		for (auto x:d[v.y.x])b[x.x]+=x.y,ckmax(c[x.x],b[x.x]);
		dfs(v.x,u);
		for (auto x:d[v.y.y])b[x.x]+=x.y;
		for (auto x:d[v.y.x])b[x.x]-=x.y;
	}
}

void solve()
{
	n=read();a[1]=1;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),x=read(),y=read();
		e[u].pb(mp(v,mp(x,y))),e[v].pb(mp(u,mp(y,x)));
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)ans=ans*poww(i,c[i])%Mod,c[i]=0,e[i].clear();
	cout<<ans<<'\n';ans=0;
}

signed main()
{
	init(2e5);
	WT solve();
	return 0;
}
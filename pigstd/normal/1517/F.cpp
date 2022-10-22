//AFO countdown:10 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int Mod=998244353;
const int M=310;
const int N=300;
int n,dp[M][M*2],tmp[M*2],sum[M],res,X;
vector<int>e[M];
set<int>s[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);}

void dfs(int u,int fa)
{
	dp[u][-1+N]=dp[u][X+N]=1;s[u].insert(-1),s[u].insert(X);
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs(to,u);memset(tmp,0,sizeof(tmp));
		set<int>t;
		for (const int &x:s[to])
			for (const int &y:s[u])
				if (x+y>=0)tmp[max(x-1,y)+N]=(tmp[max(x-1,y)+N]+dp[to][x+N]*dp[u][y+N])%Mod,t.insert(max(x-1,y));
				else if (min(x-1,y)>=-X)
					tmp[min(x-1,y)+N]=(tmp[min(x-1,y)+N]+dp[to][x+N]*dp[u][y+N])%Mod,t.insert(min(x-1,y));
		memset(dp[u],0,sizeof(dp[u]));
		for (const int &x:t)
			dp[u][x+N]=tmp[x+N];
		s[u]=t;
	}
	for (const int &x:s[u])
		sum[u]=(sum[u]+dp[u][x+N])%Mod;
}

int getans(int x)
{
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for (int i=1;i<=n;i++)s[i].clear();
	X=x;dfs(1,0);int res=0;
	for (const int &x:s[1])
		if (x>=0)res=(res+dp[1][x+N])%Mod;
	return res;
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}//res+=poww(2,n)-1;
	for (int i=1;i<n;i++)
		res=(res+poww(2,n)-getans(i)+Mod)%Mod;
//		cout<<getans(i)<<endl;cout<<res<<endl;
	cout<<res*poww(inv(2),n)%Mod;
	return 0;
}
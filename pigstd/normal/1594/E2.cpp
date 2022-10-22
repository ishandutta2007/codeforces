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

const int Mod=1e9+7;
int n,k;string s;
map<int,int>dp[4],vis[4],f,col;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void work(int x)
{
	while(x!=1)
		f[x]=1,x>>=1;
	f[1]=1;
}

int dfs(int u,int c,int dep)
{
	if (vis[c][u])return dp[c][u];vis[c][u]=1;
	if (f[u]==0)
		return dp[c][u]=poww(2,(1ll<<dep)-2);
	if (col[u]!=0&&col[u]!=c)return dp[c][u]=0;
	if (u*2>((1ll<<n)-1))return dp[c][u]=1;
	int lson=u<<1,rson=u<<1|1,res=0;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (i!=c&&j!=c)
				res=(res+dfs(lson,i,dep-1)*dfs(rson,j,dep-1))%Mod;
	return dp[c][u]=res;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=k;i++)
	{
		int x=read();cin>>s;
		if (s=="white"||s=="yellow")col[x]=1;
		if (s=="green"||s=="blue")col[x]=2;
		if (s=="red"||s=="orange")col[x]=3;
		work(x);
	}
//	cout<<dfs(4,1,n-2)<<endl;
	int ans=(dfs(1,1,n)+dfs(1,2,n)+dfs(1,3,n))%Mod;
	ans=ans*poww(2,(1ll<<n)-1-k)%Mod;
	cout<<ans<<endl;
	return 0;
}
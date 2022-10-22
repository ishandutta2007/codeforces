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

const int M=110;
int n,m,k,Mod,C[M][M],fac[M],vis[M][M][M],dp[M][M][M];
int f[M][M],vis2[M][M];
vector<pair<int,int> >v[M]; 

/*int dfs(int n,int m,int k)
{
	if (vis[n][m][k])return dp[n][m][k];
	if (n==0)
	{
		if (k==0)return 1;
		else return 0;
	}
	if (m==1)
	{
		if (k==1)return fac[n];
		else return 0;
	}
	if (k!=0&&calc(k,m)>n)return 0;
	dp[n][m][k]=0;vis[n][m][k]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=k;j++)
			dp[n][m][k]=(dp[n][m][k]+dfs(i,m-1,j)*dfs(n-i-1,m-1,k-j)%Mod*C[n-1][i])%Mod;
//	if (n<k+m-1&&dp[n][m][k]!=0)cout<<n<<' '<<m<<' '<<k<<endl,cout<<"???"<<endl;
	return dp[n][m][k];
}*/

signed main()
{
	n=read(),m=read(),k=read(),Mod=read();fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod;
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
 //   dp[0][1][1]=1,v[1].pb(mp(0,1));
	for (int i=1;i<=n;i++)
		dp[i][1][1]=fac[i],v[1].pb(mp(i,1));
	dp[0][1][0]=1;v[1].pb(mp(0,0));
	for (int i=1;i<m;i++)
	{
		for (int j=0;j<v[i].size();j++)
			for (int w=0;w<v[i].size();w++)
			{
				int nx=v[i][j].x+v[i][w].x+1,nk=v[i][j].y+v[i][w].y;
				if (nx>n||nk>k)continue;
				if (!vis[nx][i+1][nk])
					vis[nx][i+1][nk]=1,v[i+1].pb(mp(nx,nk));
				dp[nx][i+1][nk]=(dp[nx][i+1][nk]+
				C[nx-1][v[i][j].x]*dp[v[i][j].x][i][v[i][j].y]%Mod*
				dp[v[i][w].x][i][v[i][w].y])%Mod;
			}
		dp[0][i+1][0]=1;v[i+1].pb(mp(0,0));
	}
	cout<<dp[n][m][k]<<endl;
	return 0;
}
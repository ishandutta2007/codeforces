#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void add(int &x,int y){x+=y;if (x>=p) x-=p;}
vector<int>e[N];
int dp[N][N][N],tmp[N][N],siz[N],f[N],ans[N];
void dfs(int now,int father)
{
	dp[now][0][0]=siz[now]=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		for (int i=0;i<siz[now];i++)
		for (int j=0;j<siz[now];j++)
		for (int x=0;x<siz[to];x++)
		for (int y=0;y<siz[to];y++)
		{
			add(tmp[i+x][j],1LL*dp[now][i][j]*dp[to][x][y]%p*(y+1)%p);
			add(tmp[i+x+1][j+y+1],1LL*dp[now][i][j]*dp[to][x][y]%p);
		}
		siz[now]+=siz[to];
		for (int i=0;i<siz[now];i++)
		for (int j=0;j<siz[now];j++)
		dp[now][i][j]=tmp[i][j],tmp[i][j]=0;
	}
}
int C[N][N],pw[N];
void GreenDay()
{
	for (int i=C[0][0]=1;i<N;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	int n=read();
	for (int i=pw[0]=1;i<=n;i++) pw[i]=1LL*pw[i-1]*n%p;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
	add(f[i],1LL*dp[1][i][j]*(j+1)%p);
	for (int i=0;i<n-1;i++) f[i]=1LL*f[i]*pw[n-i-2]%p; f[n-1]=1;
	for (int i=0;i<n;i++)
	for (int j=i,fl=1;j<n;j++,fl=(-fl+p)%p)
	add(ans[i],1LL*fl*f[j]%p*C[j][i]%p);
	for (int i=0;i<n;i++) print(ans[i]," \n"[i+1==n]);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int M=610;
int n,m,p,a[M],b[M],cnt1,cnt2,in[M],out[M],A[M][M],vis[M],f[M][M];
vector<int>e[M];

int solve(int n)
{
	int ans=1;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			while(A[i][i])
			{
				int x=A[j][i]/A[i][i];
				for (int k=i;k<=n;k++)
					A[j][k]=(A[j][k]+p-1ll*x*A[i][k]%p)%p;
				ans*=-1;swap(A[i],A[j]);
			}
			swap(A[i],A[j]),ans*=-1;
		}
	for (int i=1;i<=n;i++)
		ans=1ll*ans*A[i][i]%p;
	ans=(ans+p)%p;return ans;
}

void dfs(int u)
{
	if (vis[u])return;vis[u]=1;
	if (out[u]==0){f[u][u]=1;return;}
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		dfs(to);
		for (int j=1;j<=cnt1;j++)
			f[u][b[j]]=(f[u][b[j]]+f[to][b[j]])%p;
	}
}

signed main()
{
	n=read(),m=read(),p=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].pb(v);
		out[u]++,in[v]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (in[i]==0)a[++cnt1]=i;
		if (out[i]==0)b[++cnt2]=i;
	}
	for (int i=1;i<=cnt1;i++)
		dfs(a[i]);
	for (int i=1;i<=cnt1;i++)
		for (int j=1;j<=cnt2;j++)
			A[i][j]=f[a[i]][b[j]];
	cout<<solve(cnt1)<<endl;
	return 0;
}
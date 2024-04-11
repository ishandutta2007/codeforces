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

const int M=610;
int n,m,q,f[M][M],u[M*M],v[M*M],l[M*M],ans,vis[M*M];
int x1[M],x2[M][M];
pair<int,int>a[M][M];

signed main()
{
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;i++)f[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		a[u][v].x=a[v][u].x=f[u][v]=f[v][u]=w;
		a[u][v].y=a[v][u].y=i;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	q=read();
	for (int i=1;i<=q;i++)
	{
		u[i]=read(),v[i]=read(),l[i]=read();
		for (int k=1;k<=n;k++)
//			x1[k]=max(x1[k],l[i]-f[u[i]][k]-f[v[i]][k]),
			x2[k][v[i]]=max(x2[k][v[i]],l[i]-f[u[i]][k]);
	}
//	for (int i=1;i<=n;i++)
//		for (int j=1;j<=n;j++)
//			if (a[i][j].x!=0&&a[i][j].x*2<=x1[i])vis[a[i][j].y]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (a[i][j].x==0)continue;
			for (int k=1;k<=n;k++)
				if (a[i][j].x+f[j][k]<=x2[i][k])vis[a[i][j].y]=1;
		}
	for (int i=1;i<=m;i++)if (vis[i])ans++;
	cout<<ans<<endl;
	return 0;
}
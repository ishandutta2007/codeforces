#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=3e5+10;
int n,fa[M][25],vis[M],a[M],c[M];

signed main()
{
	n=read(),a[1]=read(),c[1]=read();vis[0]=1;
	for (int i=2;i<=n+1;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int p=read()+1;a[i]=read(),c[i]=read();
			fa[i][0]=p;
			for (int j=1;j<=20;j++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		else
		{
			int x=read()+1,v=read();
			int sum1=0,sum2=0;
			while(sum1!=v&&!vis[x])
			{
				int u=x;
				for (int i=20;i>=0;i--)
					if (!vis[fa[u][i]])u=fa[u][i];
				if (a[u]+sum1>v)a[u]-=v-sum1,sum2+=c[u]*(v-sum1),sum1=v;
				else vis[u]=1,sum1+=a[u],sum2+=a[u]*c[u];
			}
			cout<<sum1<<' '<<sum2<<endl;
		}
	}
	return 0;
}
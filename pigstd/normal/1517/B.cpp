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


const int M=110;
int n,m,a[M][M],vis[M][M],ans[M][M];

struct node
{
	int i,j,p;
}b[M*M];

bool cmp(node a,node b){return a.p<b.p;}

signed main()
{
	WT
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				a[i][j]=b[(i-1)*m+j].p=read(),b[(i-1)*m+j].i=i,b[(i-1)*m+j].j=j,
				vis[i][j]=ans[i][j]=0;
		sort(b+1,b+1+n*m,cmp);
		for (int i=1;i<=m;i++)
			ans[b[i].i][i]=b[i].p,vis[b[i].i][b[i].j]=1;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				if (ans[i][j])continue;
				for (int k=1;k<=m;k++)
					if (!vis[i][k])
						{ans[i][j]=a[i][k],vis[i][k]=1;break;}
			}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				cout<<ans[i][j]<<' ';
			puts("");
		}
	}
	return 0;
}
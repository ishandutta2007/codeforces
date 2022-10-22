//AFO countdown:13 Days
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
#define y1 kjahdskhladhs
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1010;
const int N=45;
int n,m,k,f[N][M][M],a[M][M],vis[N];
queue<pair<int,int> >q;
vector<pair<int,int> >v[N];
int fx[]={1,-1,0,0};
int fy[]={0,0,-1,1};

signed main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)a[i][j]=read(),v[a[i][j]].pb(mp(i,j));
	for (int w=1;w<=k;w++)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (a[i][j]==w)f[w][i][j]=1,q.push(mp(i,j));
		for (int i=1;i<=k;i++)vis[i]=0;vis[w]=1;
		while(!q.empty())
		{
			int x=q.front().x,y=q.front().y;q.pop();
			for (int i=0;i<4;i++)
			{
				int tx=fx[i]+x,ty=fy[i]+y;
				if (tx<1||tx>n||ty<1||ty>m)continue;
				if (!f[w][tx][ty])f[w][tx][ty]=f[w][x][y]+1,q.push(mp(tx,ty));
			}
			if (!vis[a[x][y]])
			{
				vis[a[x][y]]=1;
				for (int j=0;j<v[a[x][y]].size();j++)
				{
					int tx=v[a[x][y]][j].x,ty=v[a[x][y]][j].y;
					if (!f[w][tx][ty])f[w][tx][ty]=f[w][x][y]+1,q.push(mp(tx,ty));
				}
			}
		}
	}
	WT
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		int ans=abs(x1-x2)+abs(y1-y2);
		for (int i=1;i<=k;i++)
			ans=min(ans,f[i][x1][y1]+f[i][x2][y2]-1);
		cout<<ans<<endl;
	}
	return 0;
}
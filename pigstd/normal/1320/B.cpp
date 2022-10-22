//AFO countdown:13 Days
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

const int M=2e5+10;
int dis[M],n,m,k,p[M],f[M],cnt[M];
vector<int>e1[M],e2[M];
queue<int>q;

void bfs(int s)
{
	q.push(s);dis[s]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=0;i<e1[u].size();i++)
		{
			int to=e1[u][i];
			if (dis[to]==0)
				dis[to]=dis[u]+1,q.push(to);
		}
	}
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e1[v].pb(u),e2[u].pb(v);
	}
	k=read();
	for (int i=1;i<=k;i++)p[i]=read();
	bfs(p[k]);int ans1=0,ans2=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<e2[i].size();j++)
		{
			int to=e2[i][j];
			if (dis[to]+1==dis[i])cnt[i]++;
		}
//	for (int i=1;i<=n;i++)cout<<dis[i]<<' '<<cnt[i]<<endl;
	for (int i=1;i<k;i++)
	{
		if (dis[p[i]]!=dis[p[i+1]]+1)ans1++;
		else if (cnt[p[i]]!=1)ans2++;
	}
	cout<<ans1<<' '<<ans1+ans2<<endl;
	return 0;
}
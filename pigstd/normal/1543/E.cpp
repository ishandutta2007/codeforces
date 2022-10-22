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

const int M=(1<<16)+10;
int n,p[M],vis1[M],vis2[M],ans[M];
vector<int>e[M];
queue<int>q;

signed main()
{
	WT
	{
		n=read();
		for (int i=0;i<(1<<n);i++)e[i].clear(),vis1[i]=vis2[i]=ans[i]=p[i]=0;
		for (int i=1;i<=n*(1<<(n-1));i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
		}int cnt=0;vis1[0]=vis2[0]=1;
		for (int i=0;i<e[0].size();i++)
			p[e[0][i]]=1<<cnt,cnt++,q.push(e[0][i]);
		while(!q.empty())
		{
			int u=q.front();q.pop();vis1[u]=1;
			for (int i=0;i<e[u].size();i++)
			{
				int to=e[u][i];
				if (!vis1[to])p[to]|=p[u];
				if (!vis2[to])q.push(to),vis2[to]=1;
			}
		}
		for (int i=0;i<(1<<n);i++)
			ans[p[i]]=i;
		for (int i=0;i<(1<<n);i++)
			cout<<ans[i]<<' ',ans[i]=0;puts("");
		int x=log2(n);
		if ((1<<x)!=n){puts("-1");continue;}
		for (int i=0;i<(1<<n);i++)
			for (int j=0;j<n;j++)
				if ((1<<j)&i)ans[i]^=j;
		for (int i=0;i<(1<<n);i++)
			cout<<ans[p[i]]<<' ';puts("");
	}
	return 0;
}
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

const int M=3010;
int n,m,ans[M],cnt;
vector<int>a[M],b[M],e[M<<1];
map<vector<int>,queue<int> >t;
queue<int>q;int in[M],vis[M];

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			a[i].pb(read());
		t[a[i]].push(i);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			b[i].pb(read());
		if (t[b[i]].empty()){puts("-1");return 0;}
		int x=t[b[i]].front();t[b[i]].pop();b[i].pb(x);
	}
	for(int i=1;i<n;i++)
		for(int j=0;j<=m;j++)
			if(b[i][j]>b[i+1][j])e[m+i].pb(j),in[j]++;
			else if(b[i][j]<b[i+1][j])e[j].pb(m+i),in[m+i]++;
	for (int i=0;i<=m;i++)
		if (in[i]==0)
			q.push(i),vis[i]=1;
	while(!q.empty()&&!vis[m])
	{
		int u=q.front();q.pop();
		if(u<=m)
		{
			ans[++cnt]=u+1;
			for (int i=0;i<e[u].size();i++)
				if(!vis[e[u][i]])vis[e[u][i]]=1,q.push(e[u][i]);
		}
		else
		{
			for (int i=0;i<e[u].size();i++)
			{
				in[e[u][i]]--;
				if(!in[e[u][i]])vis[e[u][i]]=1,q.push(e[u][i]);
			}
		}
	}
	if (!vis[m]){puts("-1");return 0;}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
		cout<<ans[cnt-i+1]<<' ';
	return 0;
}
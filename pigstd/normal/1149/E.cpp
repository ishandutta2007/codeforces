#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,m,deg[M],vis[M],a[M],c[M],val[M];
vector<int>e1[M],e2[M],vv[M];
queue<int>q;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e1[u].pb(v),e2[v].pb(u),deg[u]++;
	}
	for (int i=1;i<=n;i++)
		if (!deg[i])q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (auto v:e1[u])vis[c[v]]=1;
		while(vis[c[u]])c[u]++;
		for (auto v:e1[u])vis[c[v]]=0;
		vv[c[u]].pb(u);
		for (auto v:e2[u])
		{
			deg[v]--;
			if (!deg[v])q.push(v);
		}
	}
	int tmp=-1;
	for (int i=0;i<=n;i++)
	{
		for (auto x:vv[i])val[i]^=a[x];
		if (val[i])tmp=i;
	}
	if (tmp==-1)return puts("LOSE"),0;
	puts("WIN");
	for (auto x:vv[tmp])
		if ((a[x]^val[tmp])<a[x])
		{
			a[x]^=val[tmp];
			for (auto y:e1[x])
				if (val[c[y]])a[y]^=val[c[y]],val[c[y]]=0;
			break;
		}
	for (int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}
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
int n,t[M],a[M],b[M],F,vis[M],vis2[M];
vector<int>e[M];

void dfs(int u)
{
	vis[u]=vis2[u]=1;
	for (auto v:e[u])
		if (vis2[v])F=1;
		else if (!vis[v])dfs(v);
	vis2[u]=0;
}

void solve()
{
	n=read();int ans=0,pos=1;F=0;
	for (int i=1;i<=n;i++)t[i]=0,vis[i]=vis2[i]=0;
	for (int i=1;i<=n;i++)t[a[i]=read()]++,e[i].clear();
	for (int i=1;i<=n;i++)b[i]=read();
	for (int i=1;i<=n;i++)
		if (t[i]>t[pos])pos=i; 
	for (int i=1;i<=n;i++)
		if (a[i]!=pos&&b[i]!=pos)
			e[a[i]].pb(b[i]);
	for (int i=1;i<=n;i++)
		if (i!=pos&&!vis[i])dfs(i);
	if (!F)puts("AC");
	else puts("WA");
}

signed main()
{
	WT solve();
	return 0;
}
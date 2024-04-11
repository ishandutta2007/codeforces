// Author: Little09
// Problem: D. Paths on the Tree
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll n,m; 
ll a[N],c[N],d[N];
int fa[N];
int t[N*2],nxt[N*2],cnt,h[N];
ll dp[N][2];
inline void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs1(int x)
{
	for (int i=h[x];i;i=nxt[i])
	{
		c[t[i]]=c[x]/d[x];
		dfs1(t[i]);
	}
}
ll f[N],cntt;
void dfs2(int x)
{
	for (int i=h[x];i;i=nxt[i])
	{
		dfs2(t[i]);
	}
	if (d[x]==0)
	{
		for (int k=0;k<=1;k++)
		{
			ll u=c[x]+k;
			ll v=u/d[x],w=u%d[x];
			dp[x][k]=a[x]*u;
		}	
		return;
	}
	for (int k=0;k<=1;k++)
	{
		ll u=c[x]+k;
		ll v=u/d[x],w=u%d[x];
		cntt=0;
		ll sum=0;
		for (int i=h[x];i;i=nxt[i])
		{
			if (v==c[t[i]]) sum+=dp[t[i]][0];
			else sum+=dp[t[i]][1];
			f[++cntt]=dp[t[i]][1]-dp[t[i]][0];
		}	
		sort(f+1,f+cntt+1);
		for (int i=cntt;i>=cntt-w+1;i--) sum+=f[i];
		dp[x][k]=sum+a[x]*u;
	}
}


void work()
{
	cin >> n >> m;
	cnt=0;
	for (int i=1;i<=n;i++) h[i]=0,c[i]=0,d[i]=0,dp[i][0]=0,dp[i][1]=0;
	for (int i=2;i<=n;i++)
	{
		cin >> fa[i];
		d[fa[i]]++;
		add(fa[i],i);
	}
	for (int i=1;i<=n;i++) cin >> a[i];
	c[1]=m;
	dfs1(1);
	dfs2(1);
	cout << dp[1][0] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}
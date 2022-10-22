// Author: Little09
// Problem: E. Swap and Maximum Block
// Contest: Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=600005;
int n,m; 
int a[N],b[N];
ll f[N],g[N],dp[N],s[N],ans[N];
void push_up(int u)
{
	s[u]=s[u*2]+s[u*2+1];
	f[u]=max(f[u*2],s[u*2]+f[u*2+1]);
	g[u]=max(g[u*2+1],s[u*2+1]+g[u*2]);
	dp[u]=max(max(dp[u*2],dp[u*2+1]),g[u*2]+f[u*2+1]);
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		s[u]=a[l],f[u]=a[l],g[u]=a[l],dp[u]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	push_up(u);
}
void work(int u)
{
	u=n-u-1;
	int l=(1<<u),r=l*2-1;
	for (int i=l;i<=r;i++) 
	{
		swap(s[i*2],s[i*2+1]);
		swap(f[i*2],f[i*2+1]);
		swap(g[i*2],g[i*2+1]);
		swap(dp[i*2],dp[i*2+1]);
		push_up(i);
	}
	for (int i=l-1;i>=1;i--) push_up(i); 
}
void dfs(int x,int y)
{
	if (y==n)
	{
		ans[x]=dp[1];
		return;
	}
	dfs(x,y+1);
	work(y);
	dfs(x+(1<<y),y+1);
	work(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	m=(1<<n);
	for (int i=1;i<=m;i++) cin >> a[i];
	build(1,1,m);
	dfs(0,0);
	int q;
	cin >> q;
	int las=0;
	for (int i=1;i<=q;i++)
	{                   
		int x;
		cin >> x;
		las=(las^(1<<(x)));
		cout << max(0ll,ans[las]) << endl;
	}
	return 0;
}
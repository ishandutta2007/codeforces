// Author: Little09
// Problem: CF868F Yet Another Minimization Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF868F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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

const int N=100005,M=21;
int n,m; 
int a[N];
ll c[N],res,dp[N][M];
int L=1,R;
inline void update(int x,int y)
{
	res-=c[a[x]]*(c[a[x]]-1)/2;
	c[a[x]]+=y;
	res+=c[a[x]]*(c[a[x]]-1)/2;
}
ll calc(int l,int r)
{
	while (L<l) update(L++,-1);
	while (L>l) update(--L,1);
	while (R>r) update(R--,-1);
	while (R<r) update(++R,1);
	return res;
}
void solve(int l,int r,int x,int y,int j)
{
	if (l>r) return;
	int mid=(l+r)>>1;
	int u=min(y,mid-1),v=-1;
	for (int i=x;i<=u;i++)
	{
		if (dp[i][j-1]+calc(i+1,mid)<=dp[mid][j]) dp[mid][j]=dp[i][j-1]+calc(i+1,mid),v=i;
	}
	solve(l,mid-1,x,v,j);
	solve(mid+1,r,v,y,j);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=0;i<=n;i++) 
	{
		for (int j=0;j<=m;j++)
		{
			dp[i][j]=inf;
		}
	}
	dp[0][0]=0;
	for (int j=1;j<=m;j++) solve(1,n,0,n,j);
	cout << dp[n][m] << endl;
	return 0;
}
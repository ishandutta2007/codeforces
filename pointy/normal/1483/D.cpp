// Author: Little09
// Problem: CF1483D Useful Edges
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1483D
// Memory Limit: 500 MB
// Time Limit: 5000 ms
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

const int N=605,M=N*N;
int n,m,q; 
ll a[M][3],f[N][N],dp[N][N];
struct point
{
	ll x,y,z;
};
bool ans[M];
vector<point>t[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	memset(f,63,sizeof(f));
	//memset(dp,-63,sizeof(dp));
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		f[a[i][0]][a[i][1]]=min(f[a[i][0]][a[i][1]],a[i][2]);
		f[a[i][1]][a[i][0]]=min(f[a[i][1]][a[i][0]],a[i][2]);
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	cin >> q;
	for (int i=1;i<=q;i++)
	{
		point u;
		cin >> u.x >> u.y >> u.z;
		t[u.x].push_back(u);
	}
	for (int i=1;i<=n;i++)
	{
		for (point j:t[i])
		{
			for (int u=1;u<=n;u++)
			{
				dp[i][u]=max(dp[i][u],j.z-f[u][j.y]);
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		int u=a[i][0],v=a[i][1];
		for (int j=1;j<=n;j++)
		{
			if (dp[j][u]>=f[j][v]+a[i][2]) ans[i]=1;
		}
		u=a[i][1],v=a[i][0];
		for (int j=1;j<=n;j++)
		{
			if (dp[j][u]>=f[j][v]+a[i][2]) ans[i]=1;
		}
	}
	int tot=0;
	for (int i=1;i<=m;i++) tot+=ans[i];
	cout << tot << endl;
	return 0;
}
// Author: Little09
// Problem: CF605E Intergalaxy Trips
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF605E
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

const double inf=1e9; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1005;
int n; 
double a[N][N];
long double s[N],c[N];
bool vis[N];
inline long double dp(int x)
{
	if (x==n) return 0;
	if (c[x]==1) return inf;
	return (s[x]+1)/(1.0-c[x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
		    int x;
		    cin >> x;
			a[i][j]=x;
			a[i][j]*=0.01;
		}
	}
	for (int i=1;i<=n;i++) c[i]=1;
	for (int i=1;i<=n;i++)
	{
		int u=-1;
		for (int j=1;j<=n;j++) 
		{
			if (vis[j]) continue;
			if (u==-1||dp(j)<dp(u)) u=j;
		}
		vis[u]=1;
		for (int j=1;j<=n;j++)
		{
			if (vis[j]) continue;
			s[j]+=dp(u)*(a[j][u]*c[j]);
			c[j]*=((1.0-a[j][u]));
		}
	}
	cout << fixed << setprecision(15) << dp(1);
	return 0;
}
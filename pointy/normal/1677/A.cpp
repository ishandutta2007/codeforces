// Author: Little09
// Problem: CF1677A Tokitsukaze and Strange Inequality
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1677A
// Memory Limit: 250 MB
// Time Limit: 1500 ms
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

const int N=5005;
int n,m; 
int a[N];
int s[N][N],d[N][N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) s[i][j]=s[i-1][j];
		for (int j=a[i];j<=n;j++) s[i][j]++;
	}
	for (int i=n;i>=1;i--) d[n+1][i]=0;
	for (int i=n;i>=1;i--)
	{
		for (int j=1;j<=n;j++) d[i][j]=d[i+1][j];
		for (int j=a[i];j<=n;j++) d[i][j]++;
	}
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			ans+=1ll*s[i-1][a[j]]*d[j+1][a[i]];
		}
	}
	cout << ans << endl;
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
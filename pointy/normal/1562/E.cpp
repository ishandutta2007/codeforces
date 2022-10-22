// LUOGU_RID: 90592498
// Author: Little09
// Problem: CF1562E Rescue Niwen!
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1562E
// Memory Limit: 500 MB
// Time Limit: 2000 ms
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

const int N=5005;
int n,m; 
char a[N];
int lcp[N][N],dp[N];

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=n;i>=1;i--)
	{
		for (int j=i-1;j>=1;j--)
		{
			if (i==n) lcp[i][j]=(a[i]==a[j]);
			else if (a[i]==a[j]) lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
		}
	}
	for (int i=0;i<=n;i++) dp[i]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=n-i+1;
		for (int j=1;j<i;j++)
		{
			int len=lcp[i][j];
			if (i+len-1>=n||a[i+len]<a[j+len]) continue;
			dp[i]=max(dp[i],dp[j]+n-(i+len-1));
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
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
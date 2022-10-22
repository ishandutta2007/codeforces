// Author: Little09
// Problem: CF1678B2 Tokitsukaze and Good 01-String (hard version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1678B2
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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

const int N=500005;
int n,m; 
char a[N];
int b[N],cnt,ans,c[N],tot,d[N];
int dp[N][2];

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int ans=0;
	for (int i=1;i<=n/2;i++) if (a[i*2]!=a[i*2-1]) ans++;
	for (int i=1;i<=n/2;i++)
	{
		dp[i][0]=N,dp[i][1]=N;
		if (a[i*2]==a[i*2-1]) 
		{
			dp[i][a[i*2]-'0']=min(dp[i][a[i*2]-'0'],dp[i-1][a[i*2]-'0']);
			dp[i][a[i*2]-'0']=min(dp[i][a[i*2]-'0'],dp[i-1]['1'-a[i*2]]+1);
		}
		else
		{
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
			dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
			dp[i][1]=min(dp[i][1],dp[i-1][1]);
			dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
		}
	}
	cout << ans << " " << min(dp[n/2][0],dp[n/2][1])+1 << endl;
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
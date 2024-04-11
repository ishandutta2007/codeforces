// Author: Little09
// Problem: CF1677B Tokitsukaze and Meeting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1677B
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

const int N=1000005;
int n,m; 
int a[N],dp[N],s[N],w[N];


void work()
{
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) 
	{
		char x;
		cin >> x;
		a[i]=x-'0';
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n*m;i++)
	{
		if (i<=m) dp[i]=(s[i]>=1);
		else dp[i]=dp[i-m]+(s[i]-s[i-m]>=1);
	}
	for (int i=1;i<=m;i++) w[i]=0;
	int ans=0;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i])
		{
			int x=(i-1)%m+1;
			if (w[x]>0) ans--;
			w[x]++;
			if (w[x]>0) ans++;	
		}
		cout << dp[i]+ans << " ";
	}
	cout << endl;
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
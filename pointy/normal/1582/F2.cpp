// Author: Little09
// Problem: CF1582F2 Korney Korneevich and XOR (hard version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1582F2
// Memory Limit: 500 MB
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

const int N=1000005,M=8525,L=5100;
int n,m; 
int a[N];
vector<int>b[M],t;
int dp[L][M];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[a[i]].push_back(i);
		m=max(m,a[i]);
	}
	int v=1;
	while (v<=m) v*=2;
	v--;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=m;i++)
	{
		t.clear();
		for (int k:b[i]) t.push_back(k);
		for (int j=0;j<=v;j++)
		{
			if (dp[i-1][j]!=-1) dp[i][j]=dp[i-1][j];
			if (dp[i-1][j^i]==-1) continue;
			auto k=upper_bound(t.begin(),t.end(),dp[i-1][j^i]);
				if (k!=t.end())
				{
					int u=*k;
					if (dp[i][j]==-1) dp[i][j]=u;
					else dp[i][j]=min(dp[i][j],u);
				}
		}
	}
	int cnt=0;
	for (int i=0;i<=v;i++) if (dp[m][i]!=-1) cnt++;
	cout << cnt << endl;
	for (int i=0;i<=v;i++) if (dp[m][i]!=-1) cout << i << " ";
	return 0;
}
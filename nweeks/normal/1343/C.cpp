#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '

typedef	long long ll;

ll solve(int testcase);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	for (int _t(1); _t <= __t; _t++)
		pnl(solve(_t));
}

ll solve(int testcase)
{
	int n;
	cin>>n;
	vector<ll> arr(n);
	FOR(i,0,n) cin >> arr[i];
	vector<pair<int, ll> > dp[2];
	dp[0].resize(n);
	dp[1].resize(n);
	if (arr[0] > 0)
		dp[1][0] = make_pair(1, arr[0]);
	else
		dp[0][0] = make_pair(1, arr[0]);
	for (int i(1); i < n; ++i)
	{
		dp[0][i] = dp[0][i-1];
		dp[1][i] = dp[1][i-1];
		if (arr[i] > 0)
			dp[1][i] = max( dp[1][i], make_pair(dp[0][i-1].F+1, dp[0][i-1].S+arr[i]));
		else
			dp[0][i] = max(dp[0][i], make_pair(dp[1][i-1].F+1, dp[1][i-1].S + arr[i]));
	}
	return max(dp[0][n-1], dp[1][n-1]).S;
}
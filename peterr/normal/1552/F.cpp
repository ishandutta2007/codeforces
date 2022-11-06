#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2E5;
tuple<int, int, int> a[MAXN];
bool active[MAXN];
int dp[MAXN];

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, s;
		cin >> x >> y >> s;
		a[i] = {x, y, s};
	}
	reverse(a, a + n);
	int ans = (get<0>(a[0]) + 1) % MOD;
	int sum = 0;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++)
	{
		int x = get<0>(a[i]);
		int y = get<1>(a[i]);
		while (pq.size() && pq.top().first > x)
		{
			add(sum, MOD - pq.top().second);
			pq.pop();
		}
		dp[i] = (get<2>(a[i]) == 1);
		add(dp[i], sum);
		pq.push({y, dp[i]});
		add(sum, dp[i]);
		int dist = (x - y) % MOD;
		add(ans, (int) ((long long) dp[i] * dist % MOD));
		//cout << "dp " << i << " = " << dp[i] << endl;
	}
	cout << ans << "\n";
	return 0;
}
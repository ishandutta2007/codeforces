#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
ll dp[100005][2];
vector<ll> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	dp[0][0] = abs(a[0] + 1);
	dp[0][1] = abs(a[0] - 1);
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0] + abs(a[i] - 1), dp[i - 1][1] + abs(a[i] + 1));
		dp[i][1] = min(dp[i - 1][1] + abs(a[i] - 1), dp[i - 1][0] + abs(a[i] + 1));
	}
	cout << dp[n - 1][1] << '\n';
}
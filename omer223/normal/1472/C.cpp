#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <queue>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
int a[sz];


void solve() {
	int n;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	vector<ll> dp(n + 1, 0);
	ll ans = 0;
	ford(i, n - 1, 0) {
		dp[i] = dp[min(n, i + a[i])] + a[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish return cout << "NO" << endl, 0
#define all(X) (X).begin(), (X).end()
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, dp[100001];
vector<pair<int, int>> a;

int bs(int v) {
	int lo = 0, hi = n - 1, mid;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (a[mid].first >= v) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(all(a));
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		int at = bs(a[i].first - a[i].second);
		if (at == 0) dp[i] = i;
		else dp[i] = (i - at) + dp[at - 1];
	}

	int ans = 2e9;
	for (int i = 0; i < n; i++)
		ans = min(ans, n - i - 1 + dp[i]);
	cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

ll ans, n;

int main() {
	fast;
	cin >> n;
	vector<ll> a(n), l(1e6 + 3, -1), b(n), dp(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		b[i] = l[a[i]], l[a[i]] = i;
//	for (auto i : b) cout << i << " "; cout << endl;
	dp[0] = 1;
	for (int i = 1; i < n; i++)
		dp[i] = dp[i - 1] + (i - b[i]);
	for (auto i : dp) ans += (ll)i;
	ans = (ans - n) * 2 + n;
	cout.precision(20);
	cout << (ldb)ans / ((ldb)n * (ldb)n) << endl;
}
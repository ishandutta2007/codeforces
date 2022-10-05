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
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m;
ll s = 0, c[100001], ans = 9e18;
vector<ll> a;
vector<int> b[100001];

int main() {
	fast;
	cin >> n >> m;
	if (m < 3) return cout << 0 << endl, 0;
	a.resize(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 1; i < m; i++) s += abs(a[i] - a[i - 1]);
	if (a[0] != a[1]) b[a[0]].push_back(a[1]);
	if (a[m - 1] != a[m - 2]) b[a[m - 1]].push_back(a[m - 2]);
	for (int i = 1; i < m - 1; i++) {
		if (a[i] != a[i - 1]) b[a[i]].push_back(a[i - 1]);
		if (a[i] != a[i + 1]) b[a[i]].push_back(a[i + 1]);
	}

	for (int i = 1; i <= n; i++) {
		c[i] = 0;
		for (auto &j : b[i]) c[i] += abs(i - j);
	}
	for (int i = 1; i <= n; i++) sort(b[i].begin(), b[i].end());

//	for (int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
//	for (int i = 1; i <= n; i++) {
//		for (auto &j : b[i]) cout << j << " "; cout << endl;
//	}

	for (int i = 1, len; i <= n; i++) {
		len = b[i].size();
		ll temp = 0;
		for (auto &j : b[i]) temp += abs(b[i][len / 2] - j);
		ans = min(ans, s - (c[i] - temp));
	}
	cout << ans << endl;
}
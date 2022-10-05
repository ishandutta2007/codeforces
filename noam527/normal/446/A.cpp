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
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a[100000], p = 0, ans = -1;
vector<pair<int, int>> r;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i - 1]) r.push_back({ p, i - 1 }), p = i;
	r.push_back({ p, n - 1 });
	if (r.size() == 1) finish(n);
	for (auto &i : r) ans = max(ans, i.second - i.first + 2);

	for (int i = 0; i < r.size(); i++) {
		if (r[i].first == r[i].second) {
			if ((r[i].first != 0 && r[i].first != n - 1) && a[r[i].first - 1] + 1 < a[r[i].first + 1]) ans = max(ans, r[i + 1].second - r[i - 1].first + 1);
		}
		else {
			if (r[i].first > 0 && r[i].first < n - 1) {
				if (a[r[i].first - 1] + 1 < a[r[i].first + 1]) ans = max(ans, r[i].second - r[i - 1].first + 1);
			}
			if (r[i].second > 0 && r[i].second < n - 1) {
				if (a[r[i].second - 1] + 1 < a[r[i].second + 1]) ans = max(ans, r[i + 1].second - r[i].first + 1);
			}
		}
	}
	cout << ans << endl;

}
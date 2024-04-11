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

int n, k, m, x;
ll ans;
vector<pair<int, int>> a;

int main() {
	fast;
	cin >> n >> k >> m;
	ans = (ll)n * m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (!a.size())
			a.push_back({ x, 1 });
		else {
			if (a.back().first != x) a.push_back({ x, 1 });
			else a.back().second++;
		}
		if (a.size() && a.back().second == k) a.pop_back(), ans -= (ll)m * k;
	}
//	cout << "ans " << ans << endl;
	if (!a.size()) finish(0);
	if (a.size() == 1) finish((ll)a[0].second * m % k);

	vector<pair<int, int>> left;

	bool good = true;
	int p1 = 0, p2 = a.size() - 1;
	while (good && p1 <= p2 && a[p1].first == a[p2].first) {
//		cout << "p1 " << p1 << " p2 " << p2 << endl;
		if (p2 - p1 == 0) {
			good = false;
			ll f = (a[p1].second  * (ll)m / k) * (ll)k;
			if (a[p1].second * (ll)m % k == 0) p1++, p2--;
			ans -= f;
		}
		else {
			if (a[p1].second + a[p2].second > k) {
				good = false;
				ans -= (ll)k * (m - 1);
			}
			else if (a[p1].second + a[p2].second < k) good = false;
			else {
				ans -= (ll)k * (m - 1);
				left.push_back(a[p1]), left.push_back(a[p2]);
				p1++, p2--;
			}
		}
//		cout << "ans " << ans << endl;
	}
	if (p1 > p2) {
		good = true;
		while (good && left.size()) {
			pair<int, int> l = last(left, 2), r = last(left, 1);
			if (l.second + r.second > k)
				good = false, ans -= k;
			else if (l.second + r.second < k) good = false;
			else ans -= k;
			left.pop_back(), left.pop_back();
		}
	}
	cout << ans << endl;

}
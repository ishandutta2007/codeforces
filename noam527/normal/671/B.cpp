#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k, kk, a[500005];
vector<pair<int, int>> b;

int main() {
	fast;
	cin >> n >> k;
	kk = k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (!b.size() || b.back().first != a[i]) b.push_back({ a[i], 1 });
		else b.back().second++;
	}
//	for (auto &i : b) cout << i.first << " " << i.second << endl;

	ll mn = b[0].first, mx = b.back().first, tot = 0;
	for (int i = 0; i < b.size() - 1; i++) {
//		cout << "i " << i << " k " << k << endl;
		if (k > 0) {
			tot += b[i].second;
			mn += (min(tot * (b[i + 1].first - b[i].first), (ll)k) / tot);
			if (tot * (b[i + 1].first - b[i].first) <= k) k -= (tot * (b[i + 1].first - b[i].first));
			else k = 0;
		}
	}
	if (k > 0) mn = b.back().first;
	k = kk;
	tot = 0;
	for (int i = b.size() - 1; i > 0; i--) {
		if (k > 0) {
			tot += b[i].second;
			mx -= (min(tot * (b[i].first - b[i - 1].first), (ll)k) / tot);
			if (tot * (b[i].first - b[i - 1].first) <= k) k -= (tot * (b[i].first - b[i - 1].first));
			else k = 0;
		}
	}
	if (k > 0) mx = b[0].first;

	tot = 0;
	for (int i = 0; i < n; i++) tot += a[i];
//	cout << "mx " << mx << " mn " << mn << endl;
	cout << max((ll)(tot % n == 0 ? 0 : 1), mx - mn) << endl;
}
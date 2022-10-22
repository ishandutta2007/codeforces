#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define ull unsigned long long
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
struct point {
	int a, type;
};
bool cmp(point a, point b) {
	if (a.a != b.a) return a.a < b.a;
	return a.type > b.type;
}
bool cmp2(pair <int, int> a, pair <int, int> b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second > b.second;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		vector <point> a;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			a.push_back({ x, 1 });
			a.push_back({ x + k, -1 });
		}
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
		}
		map <int, int> cnt, cntml, cntmr;
		sort(a.begin(), a.end(), cmp);
		int balance = 0;
		for (auto x : a) {
			balance += x.type;
			if (cnt.find(x.a) != cnt.end())
				cnt[x.a] = max(cnt[x.a], balance);
			else
				cnt[x.a] = balance;
		}
		vector <pair <int, int>> cur1, cur2, cur3;
		for (auto x : cnt) {
			cur1.push_back(x);
			cur2.push_back(x);
			cur3.push_back(x);
		}
		for (int i = 1; i < cur1.size(); ++i) {
			if (cur1[i - 1].second > cur1[i].second) {
				cur1[i].second = cur1[i - 1].second;
			}
			cntml[-cur1[i].first] = cur1[i].second;
		}
		for (int i = cur2.size() - 2; i >= 0; --i) {
			if (cur2[i + 1].second > cur2[i].second) {
				cur2[i].second = cur2[i + 1].second;
			}
			cntmr[cur2[i].first] = cur2[i].second;
		}
		int ans = 0;
		for (auto x : cur3) {
			int res = x.second, v1 = 0, v2 = 0;
			auto it1 = cntmr.upper_bound(x.first + k);
			auto it2 = cntml.upper_bound(-x.first + k);
			if (it1 != cntmr.end()) v1 = (*it1).second;
			if (it2 != cntml.end()) v2 = (*it2).second;
			ans = max(res + max(v1, v2), ans);
		}
		cout << ans << '\n';
	}

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
set <int> dels;
void dfs(int x, int i, vector <pair <int, int>>& ok) {
	if (i == ok.size()) {
		dels.insert(x);
		return;
	}
	int cur = 1;
	for (int j = 0; j <= ok[i].second; ++j) {
		dfs(x * cur, i + 1, ok);
		cur *= ok[i].first;
	}
}
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		dels.clear();
		map <int, int> pows;
		for (int i = 2; i * i <= n; ++i) {
			while (n % i == 0) {
				pows[i]++;
				n /= i;
			}
		}
		if (n > 1) pows[n]++;
		vector <pair <int, int>> ok;
		for (auto x : pows)
			ok.push_back(x);
		if (ok.size() == 1) {
			int cur = ok[0].first, cnt = 1;
			while (cnt <= ok[0].second) {
				++cnt;
				cout << cur << ' ';
				cur *= ok[0].first;
			}
			cout << '\n';
			cout << "0\n";
			continue;
		}
		vector <int> ans = { ok[0].first * ok.back().first };
		if (pows.size() == 2) {
			ans.pop_back();
			if (ok[0].second == 1 and ok[1].second == 1) {
				cout << ok[0].first << ' ' << ok[1].first << ' ' << ok[0].first * ok[1].first << '\n';
				cout << "1\n";
				continue;
			}
			ans = { 1 };
			ans[0] *= ok[0].first * ok[1].first;
			if (ok[0].second > 1) ans[0] *= ok[0].first;
			else ans[0] *= ok[1].first;
			for (int i = 0; i < ok.size(); ++i) {
				ok[i].second--;
				dfs(1, i, ok);
				for (auto x : dels) {
					if (i < ok.size() - 1)
						if (x == ok[i + 1].first) continue;
					if (x * ok[i].first == ans[0]) continue;
					ans.push_back(x * ok[i].first);
				}
				if (i < ok.size() - 1)
					ans.push_back(ok[i].first * ok[i + 1].first);
				dels.clear();
			}
			for (auto x : ans) cout << x << ' ';
			cout << "\n0\n";
			continue;
		}
		for (int i = 0; i < ok.size(); ++i) {
			ok[i].second--;
			dfs(1, i, ok);
			for (auto x : dels) {
				if (i < ok.size() - 1)
					if (x == ok[i + 1].first) continue;
				if (i == 0 and x == ok.back().first) continue;
				ans.push_back(x * ok[i].first);
			}
			if (i < ok.size() - 1)
				ans.push_back(ok[i].first * ok[i + 1].first);
			dels.clear();
		}
		int cnt = 0;
		for (int i = 0; i < ans.size(); ++i) {
			cnt += (gcd(ans[i], ans[(i + 1) % ans.size()]) == 1);
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
		cout << cnt << '\n';

	}

	return 0;
}
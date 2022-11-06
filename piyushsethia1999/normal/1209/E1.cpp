#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define vpii vector<pii>
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int a[10000][4];
int pos[10000];

std::map<pii, vpii> mp;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	mp[{0, 1}] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
	mp[{1, 2}] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
	mp[{2, 3}] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
	mp[{3, 0}] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

	mp[{0, 2}] = {{0, 2}, {1, 3}};
	mp[{1, 3}] = {{0, 2}, {1, 3}};

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int m; cin >> m;
		if (n < 4) {
			std::vector<int> v;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					int x; cin >> x;
					v.pb(x);
				}
			}
			sort(v.begin(), v.end());
			int su = 0;
			for (int i = 0; i < n; ++i) {
				su += v.back();
				v.pop_back();
			}
			cout << su << "\n";
			continue;
		}
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j)
				cin >> a[j][i];
		int mx = -1;
		for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < m; ++j)
				for (auto& pp : mp)
					for (auto& p2 : pp.se)
						mx = max(mx, a[i][pp.fi.fi] + a[i][pp.fi.se] + a[j][p2.fi] + a[j][p2.se]);
		for (int i = 0; i < m; ++i)
			sort(a[i], a[i] + 4, greater<int>());
		int su = 0;
		bool ok = true;
		for (int i = 0; i < m; ++i) {
			su += a[i][pos[i]++];
			for (int j = i; j < m; ++j) {
				su += a[j][pos[j]++];
				for (int k = j; k < m; ++k) {
					su += a[k][pos[k]++];
					for (int l = k; l < m; ++l) {
						if (i == j && j != k && l == k) continue;
						mx = max(mx, su + a[l][pos[l]]);
					}
					su -= a[k][--pos[k]];
				}
				su -= a[j][--pos[j]];
			}
			su -= a[i][--pos[i]];
		}
		cout << mx << "\n";
	}
}
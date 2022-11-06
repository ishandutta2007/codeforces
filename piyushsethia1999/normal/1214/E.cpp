#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i) cin >> v[i];
	std::vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		d[i] = (i + 1) * 2 - 1;
	}
	sort(d.begin(), d.end(), [&](auto a, auto b){
		return v[(a + 1) / 2] > v[(b + 1) / 2];
	});
	std::vector<pair<int, int> > ed;
	for (int i = 0; i < n - 1; ++i) {
		ed.pb({d[i], d[i + 1]});
	}
	print(ed);
	// print(d);
	// print(v);
	int si = n;
	for (int i = 0; i < n; ++i) {
		int id = d[i];
		if (v[(id + 1) / 2] + i < si) {
		
		} else {
			d.pb(id + 1);
			si++;
		}
		ed.pb({d[v[(id + 1) / 2] + i - 1], id + 1});
		// print(ed);
		// print(d);
	}
	print(ed);
	for (auto i : ed) {
		cout << i.fi << " " << i.se << "\n";
	}
}
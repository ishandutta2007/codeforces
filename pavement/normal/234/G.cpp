#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N;
vector<vector<int> > tt;

main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 30; i++) {
		vector<int> f, s;
		for (int j = 1; j <= N; j++)
			if (j & (1<<i)) f.pb(j);
		if (f.empty()) break;
		tt.pb(f);
	}
	if (__builtin_popcount(N) == 1) tt.ppb();
	cout << tt.size() << '\n';
	for (auto i : tt) {
		cout << i.size() << ' ';
		for (int j : i) cout << j << ' ';
		cout << '\n';
	}
}
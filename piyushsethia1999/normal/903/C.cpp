#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	std::map<int, int> m;
	int y = 0;
	for (int i = 0; i < n; ++i) {
		m[a[i]]++;
		y = max(m[a[i]], y);
	}
	cout << y;
}
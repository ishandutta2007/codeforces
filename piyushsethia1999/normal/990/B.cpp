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
	int k; cin >> k;
	std::vector<int> b(n);
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; b[o] = -a[o];}
	sort(a.begin(), a.end());
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (lower_bound(a.begin(), a.end(), a[i] + 1) != a.end()) {
			int mi = *lower_bound(a.begin(), a.end(), a[i] + 1);
			if (mi <= a[i] + k) {
				c++;
			}
		} 
	}
	cout << n - c;
}
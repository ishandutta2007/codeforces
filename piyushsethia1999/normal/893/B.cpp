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
	int ma = 1;
	std::vector<int> v;
	for (int i = 0; i < 13; ++i) {
		v.pb((1 << i) * ((1 << (i + 1)) - 1));
	}
	for (int i = v.size() - 1; i >= 0; --i) {
		if (n % v[i] == 0) {
			cout << v[i] << "\n";
			exit(0);
		}
	}
}
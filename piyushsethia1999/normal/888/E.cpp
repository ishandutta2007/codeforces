#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	set<int> m, m1;
	m.insert(0);
	m1.insert(0);
	int n; cin >> n;
	int mod; cin >> mod;
	for (int i = 0; i < (n + 1) / 2; ++i) {
		std::vector<int> v;
		int u; cin >> u; 
		for (int i : m)
			if (m.find((i + u) % mod) == m.end()) 
				v.pb((i + u) % mod);
		for (int y : v) 
			m.insert(y);
	}
	for (int i = (n + 1) / 2; i < n; ++i) {
		std::vector<int> v;
		int u; cin >> u; 
		for (int i : m1)
			if (m1.find((i + u) % mod) == m1.end()) 
				v.pb((i + u) % mod);
		for (int y : v) 
			m1.insert(y);
	}
	
	
	std::vector<int> v1(m.begin(), m.end());
	std::vector<int> v2(m1.begin(), m1.end());
	for (auto& v : v2) v = -v;
	sort(v2.begin(), v2.end());
	int ma = 0;
	for (int v : v1) {
		ma = max(v - *(lower_bound(v2.begin(), v2.end(), -(mod - v - 1))), ma);
		
	}
	cout << ma;
}
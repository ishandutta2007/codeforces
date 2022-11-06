#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }
 
int a[8000];
int b[8000];
bool vis[8000];
 
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	// int yy = ((1ll << 63) - 1);
	// print(yy);
	for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int o = 0; o < n; o++) { cin >> b[o]; }
	std::map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		mp[a[i]]++;
	}
	int an = 0;
	// for (int i = 0; i < n; ++i) an = max(an, b[i]);
	for (auto p : mp) {
		if (p.se > 1) {
			for (int i = 0; i < n; ++i) {
				if ((a[i] & p.fi) == a[i]) {
					vis[i] = 1;
				} 
			}
		} 
	}
	for (int i = 0; i < n; ++i) an += (vis[i] ? b[i] : 0);
	cout << an << "\n";
}
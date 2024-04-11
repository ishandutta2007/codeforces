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
	int n;
	cin >> n;
	string s; cin >> s;
	int a[n], b[n];
	int tt[6000] = {};
	for (int j = 0; j < n; ++j) {
		cin >> a[j] >> b[j];
		for (int i = 0; i < 6000; ++i) {
			if (max(0, (i - b[j] + a[j]) / a[j]) & 1) {
				if (s[j] == '0') {
					// print(i, j);
					tt[i]++;
				} 
			} else {
				if (s[j] == '1') {
					// print(i, j);
					tt[i]++;
				}
			}
		}
	}
	int cn = 0;
	for (int i = 0; i < 6000; ++i) {
		cn = max(cn, tt[i]);
	}
	cout << cn;
}
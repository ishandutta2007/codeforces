#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define int long long
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	string s; cin >> s;
	int cn[26] = {};
	for (auto& c : s) {
		c -= 'a';
	} 
	for (int i = 0; i < s.size(); ++i) {
		bool ok = false;
		for (int j = 0; j < s[i]; ++j) {
			if (cn[j]) {
				cout << "Ann\n";
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << "Mike\n";
		}
		cn[s[i]]++;
	}
}
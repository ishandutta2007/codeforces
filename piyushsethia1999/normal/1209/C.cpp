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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		for (auto& c : s) c -= '0';
		int dd = -1;
		for (int d = 0; d < 10; ++d) {
			bool ok = true;
			int id = 0, jd = d;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] >= jd) {
					jd = s[i];
				} else if (s[i] < id) {
					ok = false;
					break;
				} else if (s[i] == id) {

				} else if (s[i] > id && s[i] <= d) {
					id = s[i];
				} else {
					ok = false;
					break;
				}
			}
			if (ok) {
				dd = d;
				break;
			}
		}
		if (dd != -1) {
			int id = 0, jd = dd;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] >= jd) {
					jd = s[i];
					s[i] = '2';
				} else {
					id = s[i];
					s[i] = '1';
				}
			}
			cout << s << "\n";
		} else {
			cout << "-\n";
		}
	}
}
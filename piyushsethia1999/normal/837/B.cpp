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
	int m; cin >> m;
	string s[n];
	for (int i = 0; i < n; ++i) cin >> s[i];
	bool ok = false;
	if (n % 3 == 0) {
		int z[256] = {};
		bool kkk = false;
		for (int i = 0; i < 3; ++i) {
			char ch = s[(n / 3) * i][0];
			z[ch]++;
			bool kk = false;
			for (int j = i * (n / 3); j < ((i + 1) * (n / 3)); ++j) {
				for (int k = 0; k < m; ++k) {
					if (s[j][k] != ch) {
						kk = true;
						break;
					}
				}
				if (kk) 
					break;
			}
			if (kk) {
				kkk = true;
				break;
			}
		}
		if (!kkk && z['R'] && z['G'] && z['B']) { ok = true;}
	}
	if (m % 3 == 0) {
		int z[256] = {};
		bool kkk = false;
		for (int i = 0; i < 3; ++i) {
			char ch = s[0][(m / 3) * i];
			z[ch]++;
			bool kk = false;
			for (int j = i * (m / 3); j < ((i + 1) * (m / 3)); ++j) {
				for (int k = 0; k < n; ++k) {
					if (s[k][j] != ch) {
						kk = true;
						break;
					}
				}
				if (kk) 
					break;
			}
			if (kk) {
				kkk = true;
				break;
			}
		}
		if ((!kkk) && z['R'] && z['G'] && z['B']) { ok = true;}
	}
	if (ok) cout << "YES";
	else cout << "NO"; 
}
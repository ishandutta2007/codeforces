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
	string s; cin >> s;
	int to = 0;
	for (int i = 0; i < n; ++i) {
		to += max(abs(s[i] - 'a'), abs('z' - s[i]));
	}
	if (to >= k) {
		string s1 = "";
		for (int i = 0; i < n; ++i) {
			if (s[i] - 'a' > 'z' - s[i]) {
				if ((s[i] - 'a') > k) {
					s1 += string(1, char(s[i] - k));
					k = 0;
				} else {
					s1 += string(1, 'a');
					k -= (s[i] - 'a');
				}
			} else {
				if (('z' - s[i]) > k) {
					s1 += string(1, char(s[i] + k));
					k = 0;
				} else {
					s1 += string(1, 'z');
					k -= ('z' - s[i]);
				}
			}
		}
		cout << s1;
	} else {
		cout << -1;
	}
}
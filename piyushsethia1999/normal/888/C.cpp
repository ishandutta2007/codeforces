#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

string s;
int n;
std::vector<int> pr[100001];

bool check(int l) {
	for (int i = 0; i < 26; ++i) {
		bool ok = true;
		for (int j = 1; j <= n + 1 - l; ++j) {
			if (!(pr[j + l - 1][i] - pr[j - 1][i])) {
				ok = false;
				break;
			} 
		}
		if (ok) return true;
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> s;
	n = s.size();
	pr[0].resize(26, 0);
	for (int i = 1; i <= n; ++i) {
		pr[i] = pr[i - 1];
		pr[i][s[i - 1] - 'a']++;
	}
	int s = 1, e = n;
	while (s < e) {
		int m = (s + e) >> 1;
		if (check(m)) {
			e = m;
		} else {
			s = m + 1;
		}
	}
	cout << s;
}
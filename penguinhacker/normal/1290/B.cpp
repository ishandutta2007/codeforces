#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> q, n = s.size();
	vector<vector<int>> ps(n + 1, vector<int>(26));
	for (int i = 0; i < n; ++i) {
		ps[i + 1] = ps[i];
		++ps[i + 1][s[i] - 'a'];
	}
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		if (l == r) {
			cout << "Yes\n";
			continue;
		}
		int dif = 0; //number of different characters in the substring
		for (int j = 0; j < 26; ++j) dif += ps[l][j] != ps[r + 1][j];
		if (dif < 2 || (dif == 2 && s[l] == s[r])) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
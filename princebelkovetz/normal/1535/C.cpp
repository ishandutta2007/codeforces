#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
vector <vector <vector <int>>> cnt;
bool check(int l, int r) {
	if (cnt[r + 1][1][l & 1 ^ 1] - cnt[l][1][l & 1 ^ 1] == 0)
		if (cnt[r + 1][0][l & 1] - cnt[l][0][l & 1] == 0)
			return true;
	if (cnt[r + 1][1][l & 1] - cnt[l][1][l & 1] == 0)
		if (cnt[r + 1][0][l & 1 ^ 1] - cnt[l][0][l & 1 ^ 1] == 0)
			return true;
	return false;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) {
		string s; cin >> s;
		int n = s.size();
		cnt.assign(n + 1, vector <vector <int>>(2, vector <int>(2)));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					cnt[i + 1][j][k] = cnt[i][j][k];
					if ((int)(s[i] - '0') == j and i % 2 == k)
						cnt[i + 1][j][k]++;
				}
			}
		}
		int r = 0;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			while (r < n) {
				if (check(i, r)) r++;
				else break;
			}
			ans += r - i;
		}
		cout << ans << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
int n, m, pre[mxN], suf[mxN];
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0, j = 0; i < n && j < m; ++i) {
		if (s[i] == t[j]) {
			pre[j] = i;
			++j;
		}
	}
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
		if (s[i] == t[j]) {
			suf[j] = i;
			--j;
		}
	}
	int ans = 0;
	for (int i = 0; i + 1 < m; ++i) {
		ans = max(ans, suf[i + 1] - pre[i]);
	}
	cout << ans;
	return 0;
}
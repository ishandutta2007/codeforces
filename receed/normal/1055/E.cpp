#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s, m, k;
	cin >> n >> s >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<pair<int, int>> se(s);
	for (int i = 0; i < s; i++) {
		cin >> se[i].first >> se[i].second;
		se[i].first--;
		se[i].second--;
	}
	sort(se.begin(), se.end());
	vector<int> sa = a;
	sort(sa.begin(), sa.end());
	int cl = -1, cr = n;
	while (cr - cl > 1) {
		int cm = (cl + cr) / 2;
		vector<int> ps(n + 1);
		int cmx = -1;
		for (int i = 0; i < n; i++) {
			ps[i + 1] = ps[i] + (a[i] <= sa[cm] ? 1 : 0);
			//cout << ps[i + 1] << ' ';
		}
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		int cpos = -1, ca = 0;
		for (int i = 0; i < n; i++) {
			while (cpos + 1 < s && se[cpos + 1].first <= i) {
				cpos++;
				cmx = max(cmx, se[cpos].second);
			}
			//cout << i << ' ' << cpos << ' ' << cmx << ' ' << ps[cmx + 1] - ps[i] << '\n';
			for (int j = 0; j < m; j++) {
				ca = max(ca, dp[i][j]);
				dp[cmx + 1][j + 1] = max(dp[cmx + 1][j + 1], dp[i][j] + ps[cmx + 1] - ps[i]);
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
			ca = max(ca, dp[i][m]);
		}
		for (int i = 0; i <= m; i++)
			ca = max(ca, dp[n][i]);
		if (ca >= k) {
			cr = cm;
		}
		else
			cl = cm;
	}
	if (cr < n)
		cr = sa[cr];
	else
		cr = -1;
	cout << cr;
}
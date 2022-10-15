#include <bits/stdc++.h>
using namespace std;
const int maxlen = 105;
double dp[maxlen][maxlen][maxlen];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int R, S, P; cin >> R >> S >> P;
	dp[R][S][P] = 1;
	for (int r(R); r >= 0; --r)
		for (int s(S); s >= 0; --s)
			for (int p(P); p >= 0; --p) {
				if (r + s + p == max(r, max(s, p))) continue;
				int sum(r*s + s*p + p*r);
				if (r) dp[r - 1][s][p] += double(dp[r][s][p]) * (p*r) / (sum);
				if (s) dp[r][s - 1][p] += double(dp[r][s][p]) * (r*s) / (sum);
				if (p) dp[r][s][p - 1] += double(dp[r][s][p]) * (s*p) / (sum);
			}
	double ansp(0), anss(0), ansr(0);
	for (int i(1); i <= R; ++i) ansr += dp[i][0][0];
	for (int i(1); i <= S; ++i) anss += dp[0][i][0];
	for (int i(1); i <= P; ++i) ansp += dp[0][0][i];
	cout.precision(9);
	cout << fixed << setprecision(10) << ansr << ' ' << anss << ' ' << ansp;
}
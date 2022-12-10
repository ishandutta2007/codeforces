//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 500;
int dp[maxn][maxn];
int a[maxn],
	s[maxn],
	n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], s[i + 1] = s[i] + a[i];
	int ans = 0;
	int ansi, ansj;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = 1;
			for (int ii = j - 1; ii >= 0; ii--)
				for (int jj = 0; jj <= ii; jj++)
					if (s[i + 1] - s[j] == s[ii + 1] - s[jj])
						smax(dp[i][j], dp[ii][jj] + 1);
			if (dp[i][j] > ans) {
				ans = dp[i][j];
				ansi = i;
				ansj = j;
			}
		}
	}
	cout << ans << endl;
	while (dp[ansi][ansj] > 1) {
		cout << ansj + 1 << ' ' << ansi + 1 << '\n';
		for (int ii = ansj - 1; ii >= 0; ii--)
			for (int jj = 0; jj <= ii; jj++)
				if (s[ansi + 1] - s[ansj] == s[ii + 1] - s[jj] and dp[ansi][ansj] == dp[ii][jj] + 1) {
					ansi = ii, ansj = jj;
					goto end;
				}
end:;
	}
	cout << ansj + 1 << ' ' << ansi + 1 << '\n';
	return 0;
}
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

const int maxn = 2e5 + 10;
int dp[3][maxn];
int c[3][maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k[3];
	int n = 0;
	for (int i = 0; i < 3; i++)
		cin >> k[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < k[i]; j++) {
			int x;
			cin >> x;
			c[i][x] = 1;
		}
		n += k[i];
	}
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++) {
			if (i == 0)
				dp[i][j] = dp[i][j - 1] + !c[i][j];
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + !c[i][j]);
		}
	cout << dp[2][n] << endl;
	return 0;
}
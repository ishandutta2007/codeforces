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
char ch[] = "RGB";
int chpos[256];
int dp[maxn][3];
int par[maxn][3];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	chpos['R'] = 0;
	chpos['G'] = 1;
	chpos['B'] = 2;
	int n;
	cin >> n >> s;
	memset(dp, 63, sizeof dp);
	for (int j = 0; j < 3; j++)
		dp[0][j] = 1;
	dp[0][chpos[s[0]]] = 0;
	for (int i = 1; i < sz(s); i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				if (j ^ k)
					if (dp[i - 1][k] + (ch[j] != s[i]) < dp[i][j]) {
						dp[i][j] = dp[i - 1][k] + (ch[j] != s[i]);
						par[i][j] = k;
					}
	int cur = min_element(dp[n - 1], dp[n - 1] + 3) - dp[n - 1];
	cout << dp[n - 1][cur] << '\n';
	for (int i = n - 1; i >= 0; i--) {
		s[i] = ch[cur];
		cur = par[i][cur];
	}
	cout << s << '\n';
	return 0;
}
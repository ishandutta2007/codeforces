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

const int maxn = 1000 + 10,
	  maxm = 50 + 10;
short int dp[maxn][maxm][maxm];
int sgo[maxm][26],
	tgo[maxm][26],
	sf[maxm],
	tf[maxm];
string pass, s, t;

void fail(string &s, int f[], int go[][26]) {
	int match = 0;
	for (int i = 2; i <= sz(s); i++) {
		while (match and s[match] != s[i - 1]) {
			match = f[match];
		}
		match += s[match] == s[i - 1];
		f[i] = match;
	}
	for (int i = 0; i < sz(s); i++) {
		for (int c = 0; c < 26; c++) {
			if (s[i] == 'a' + c)
				go[i][c] = i + 1;
			else
				go[i][c] = go[f[i]][c];
			if (go[i][c] == sz(s))
				go[i][c] = f[sz(s)];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> pass
		>> s
		>> t;
	fail(s, sf, sgo);
	fail(t, tf, tgo);
	for (int i = 0; i <= sz(pass); i++)
		for (int j = 0; j < sz(s); j++)
			for (int k = 0; k < sz(t); k++)
				dp[i][j][k] = -2000;
	dp[0][0][0] = 0;
	for (int i = 0; i < sz(pass); i++)
		for (int j = 0; j < sz(s); j++)
			for (int k = 0; k < sz(t); k++) {
				if (pass[i] == '*')
					for (int c = 0; c < 26; c++) {
						short int addition = (s.back() == c + 'a' and j == sz(s) - 1) - (t.back() == c + 'a' and k == sz(t) - 1);
						smax(dp[i + 1][sgo[j][c]][tgo[k][c]], short(dp[i][j][k] + addition));
					}
				else {
					int c = pass[i] - 'a';
					short int addition = (s.back() == c + 'a' and j == sz(s) - 1) - (t.back() == c + 'a' and k == sz(t) - 1);
					smax(dp[i + 1][sgo[j][c]][tgo[k][c]], short(dp[i][j][k] + addition));
				}
			}
	int ans = -1e8;
	for (int j = 0; j < sz(s); j++)
		for (int k = 0; k < sz(t); k++)
			smax(ans, (int)dp[sz(pass)][j][k]);
	cout << ans << endl;
	return 0;
}
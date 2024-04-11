#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s, t;
const int sz = 405;
int jump[sz][26], cur[26], dp[sz][sz];

void initJump() {
	int slen = s.length();
	for (int i = 0; i < 26; i++)cur[i] = 1e7;
	for (int i = slen; i >= 0; i--) {
		for (int j = 0; j < 26; j++)jump[i][j] = cur[j];
		if (i)cur[s[i - 1] - 'a'] = i;
	}
}

void fillDp(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)dp[i][j] = 1e7;//???
	}
}

bool solve() {
	cin >> s >> t;
	initJump();
	int slen = s.length(), tlen = t.length(), m;
	if (tlen == 1)return (jump[0][t[0] - 'a'] <= slen);
	for (int n = 1; n < tlen; n++) {
		m = tlen - n;
		fillDp(n, m);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (not i and not j) {
					dp[i][j] = 0; continue;
				}
				if (i and dp[i - 1][j] <= slen)dp[i][j] = min(dp[i][j], jump[dp[i - 1][j]][t[i - 1] - 'a']);
				if (j and dp[i][j - 1] <= slen)dp[i][j] = min(dp[i][j], jump[dp[i][j - 1]][t[n + j - 1] - 'a']);
			}
		}
		if (dp[n][m] <= slen)return true;
	}
	return false;
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)cout << (solve() ? "YES\n" : "NO\n");
	return 0;
}
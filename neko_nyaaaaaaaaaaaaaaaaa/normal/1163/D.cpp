#include <bits/stdc++.h>
using namespace std;

int n;
string cc, s, t;
int pis[60][256];
int nxts[60][256];
int pit[60][256];
int nxtt[60][256];

int dp[2024][102][102];
 
void init() {
	n = cc.size();
	int m = s.size();
	vector<int> pref(m+2); 
	string tt;
	tt.push_back(s[0]);
	for (int i = 1; i <= m; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			tt.push_back(c);
 
			int j = pref[i-1];
			while (j > 0 && tt[i] != tt[j]) j = pref[j-1];
			if (tt[i] == tt[j]) j++;
			pref[i] = pis[i][c] = j;
 
			tt.pop_back();
		}
 
		if (i == m) break;
		tt.push_back(s[i]);
 
		pref[i] = pis[i][s[i]];
	}
 
	for (int i = 0; i <= m; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			if (i < m && s[i] == c) nxts[i][c] = i+1;
			else nxts[i][c] = pis[i][c];
		}
	}

	swap(s, t);

	m = s.size();
	pref = vector<int>(m+2, 0);
	tt.clear();
	tt.push_back(s[0]);
	for (int i = 1; i <= m; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			tt.push_back(c);
 
			int j = pref[i-1];
			while (j > 0 && tt[i] != tt[j]) j = pref[j-1];
			if (tt[i] == tt[j]) j++;
			pref[i] = pit[i][c] = j;
 
			tt.pop_back();
		}
 
		if (i == m) break;
		tt.push_back(s[i]);
 
		pref[i] = pit[i][s[i]];
	}
 
	for (int i = 0; i <= m; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			if (i < m && s[i] == c) nxtt[i][c] = i+1;
			else nxtt[i][c] = pit[i][c];
		}
	}

	swap(s, t);
}

int solve(int i, int js, int jt) {
	if (dp[i][js][jt] != -12374489) return dp[i][js][jt];
	int k = 0;
	if (js == s.size()) {
		k++;
	}
	if (jt == t.size()) {
		k--;
	}

	if (i == n) return dp[i][js][jt] = k;

	int ans = -10000000;
	if (cc[i] == '*') {
		for (char c = 'a'; c <= 'z'; c++) {
			ans = max(ans, k + solve(i+1, nxts[js][c], nxtt[jt][c]));
		}
	} else {
		char c = cc[i];
		ans = max(ans, k + solve(i+1, nxts[js][c], nxtt[jt][c]));
	}
	return dp[i][js][jt] = ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> cc >> s >> t;
	init();
	for (int i = 0; i <= 1023; i++) {
		for (int j = 0; j <= 56; j++) {
			for (int k = 0; k <= 56; k++) {
				dp[i][j][k] = -12374489;
			}
		}
	}
	cout << solve(0, 0, 0);

	return 0;
}
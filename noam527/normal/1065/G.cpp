#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#define toend cin.ignore(); cin.get(); return 0
#define finish(X) cout << (X) << '\n', toend
#define CHECK cout << "ok\n"
typedef long long ll;
typedef long double ldb;
const int OO = 1;
const int inf = 2e9 + 7;
using namespace std;

string F[14];

int count(int i, string &s) {
	int rtn = 0;
	for (int st = 0; st + s.size() <= F[i].size(); st++) {
		bool found = true;
		for (int j = 0; found && j < s.size(); j++)
			if (s[j] != F[i][st + j]) found = false;
		if (found) rtn++;
	}
	return rtn;
}
vector<int> pref(int i, string &s) {
	vector<int> rtn;
	for (int en = 1; en <= s.size(); en++) {
		bool found = true;
		for (int sub = 1; found && en - sub >= 0; sub++)
			if (s[s.size() - sub] != F[i][en - sub]) found = false;
		if (found) rtn.push_back(en);
	}
	return rtn;
}
vector<int> suf(int i, string &s) {
	vector<int> rtn;
	for (int len = 1; len <= s.size(); len++) {
		bool found = true;
		for (int j = 0; found && j < len; j++)
			if (s[j] != F[i][F[i].size() - len + j]) found = false;
		if (found) rtn.push_back(len);
	}
	return rtn;
}

int n, m;
ll k;

ll C[202];
bool P[202][202];
bool S[202][202];

void calc(string &s) {
	vector<int> tmp;

	for (int len = 0; len <= s.size(); len++) P[12][len] = S[12][len] = 0;
	C[12] = count(12, s);
	tmp = pref(12, s);
	for (const auto &i : tmp) P[12][i] = 1;
	tmp = suf(12, s);
	for (const auto &i : tmp) S[12][i] = 1;

	for (int len = 0; len <= s.size(); len++) P[13][len] = S[13][len] = 0;
	C[13] = count(13, s);
	tmp = pref(13, s);
	for (const auto &i : tmp) P[13][i] = 1;
	tmp = suf(13, s);
	for (const auto &i : tmp) S[13][i] = 1;

	for (int i = 14; i <= n; i++) {
		C[i] = C[i - 2] + C[i - 1];
		for (int len = 1; len < s.size(); len++)
			if (S[i - 2][len] && P[i - 1][s.size() - len]) C[i]++;
		C[i] = min(C[i], k);

		for (int len = 0; len <= s.size(); len++)
			P[i][len] = P[i - 2][len];
		for (int len = 0; len <= s.size(); len++)
			S[i][len] = S[i - 1][len];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	F[0] = "0";
	F[1] = "1";
	for (int i = 2; i < 14; i++)
		F[i] = F[i - 2] + F[i - 1];
	cin >> n >> k >> m;

	if (n < 14) {
		string ans = "", t0, t1;
		int c0, c1, cs0, cs1, len = 0;

		while (len < m) {
			len++;
			t0 = ans + '0';
			t1 = ans + '1';
			c0 = count(n, t0);
			c1 = count(n, t1);
			
			bool found;
			found = true;
			for (int i = 0; i < len; i++)
				if (t0[i] != F[n][F[n].size() - len + i]) found = false;
			cs0 = (found ? 1 : 0);
			found = true;
			for (int i = 0; i < len; i++)
				if (t1[i] != F[n][F[n].size() - len + i]) found = false;
			cs1 = (found ? 1 : 0);

			if (k <= cs0) {
				finish(t0);
			}
			else {
				k -= cs0;
				if (k <= c0)
					ans = t0;
				else {
					k -= c0;
					if (k <= cs1) {
						finish(t1);
					}
					else {
						k -= cs1;
						ans = t1;
					}
				}
			}
		}
		finish(ans);
	}

	// no edge cases from here

	string ans = "", t0, t1;
	ll c0, c1, cs0, cs1, len = 0;

	while (len < m) {
		len++;
		t0 = ans + '0';
		t1 = ans + '1';

		calc(t0);
		c0 = C[n];
		cs0 = S[n][len];
		calc(t1);
		c1 = C[n];
		cs1 = S[n][len];

		if (k <= cs0) {
			finish(t0);
		}
		else {
			k -= cs0;
			if (k <= c0)
				ans = t0;
			else {
				k -= c0;
				if (k <= cs1) {
					finish(t1);
				}
				else {
					k -= cs1;
					ans = t1;
				}
			}
		}
	}
	cout << ans << '\n';
	toend;
}
#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int L = 62;

int n;
vector<string> s;
int M[256];
ll A[L][L], B[L][L][L];

const int F[5] = { 1,1,2,6,24 };

ll orders(int C[4]) {
	int cnt = 1;
	ll rtn = 24;
	for (int i = 1; i < 4; i++) {
		if (C[i - 1] == C[i]) cnt++;
		else {
			rtn /= F[cnt];
			cnt = 1;
		}
	}
	rtn /= F[cnt];
	return rtn;
}

ll work() {
	for (int i = 0; i < L; i++) for (int j = i; j < L; j++) for (int k = j; k < L; k++) {
		B[i][j][k] = 0;
		for (int x = 0; x < L; x++)
			B[i][j][k] = (B[i][j][k] + A[i][x] * A[j][x] % md * A[k][x]) % md;
	}
	ll rtn = 0;
	int C[4];
	for (int i = 0; i < L; i++) for (int j = i; j < L; j++) for (int k = j; k < L; k++) for (int p = k; p < L; p++) {
		C[0] = i, C[1] = j, C[2] = k, C[3] = p;
		rtn = (rtn + B[i][j][k] * B[i][j][p] % md * B[i][k][p] % md * B[j][k][p] % md * orders(C) % md) % md;
	}
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	/*
	for (int i = 0; i < 26; i++)
		M['a' + i] = i,
		M['A' + i] = i + 26;
	for (int i = 0; i < 10; i++)
		M['0' + i] = 52 + i;
		*/
	int nxti = 0;
	for (char i = 'a'; i <= 'p'; i++) M[i] = nxti++;
	for (char i = 'A'; i <= 'P'; i++) M[i] = nxti++;
	for (char i = 'q'; i <= 'z'; i++) M[i] = nxti++;
	for (char i = 'Q'; i <= 'Z'; i++) M[i] = nxti++;
	for (char i = '0'; i <= '9'; i++) M[i] = nxti++;
	cin >> n;
	s.resize(n);
	for (auto &i : s) cin >> i;
	sort(s.begin(), s.end(), [](const string &aa, const string &bb) {
		return aa.size() < bb.size();
	});
	ll ans = 0;
	set<string> exist;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i - 1].size() < s[i].size()) {
			ans = (ans + work()) % md;
			for (int j = 0; j < L; j++) for (int k = 0; k < L; k++) A[j][k] = 0;
			exist.clear();
		}
		if (exist.count(s[i])) continue;
		exist.insert(s[i]);
		string tmp = s[i];
		reverse(tmp.begin(), tmp.end());
		exist.insert(tmp);
		if (s[i] != tmp) {
			A[M[s[i][0]]][M[s[i].back()]]++;
			A[M[s[i].back()]][M[s[i][0]]]++;
		}
		else {
			A[M[s[i][0]]][M[s[i].back()]]++;
		}
	}
	ans = (ans + work()) % md;
	cout << ans << '\n';
}
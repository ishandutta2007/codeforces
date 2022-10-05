#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

const string ST = "ACGT";

char toc(int x) {
	if (x == 0) return 'A';
	if (x == 1) return 'C';
	if (x == 2) return 'G';
	return 'T';
}

int n, m;
string s[300003], t[300003];
int c[300003][2][4] = {};

void preprocess() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (s[i][j] == 'A') {
			c[j][i & 1][0]++;
		}
		else if (s[i][j] == 'C') {
			c[j][i & 1][1]++;
		}
		else if (s[i][j] == 'G') {
			c[j][i & 1][2]++;
		}
		else {
			c[j][i & 1][3]++;
		}
	}
//	cout << "some " << c[0][0][0] << " " << c[0][0][1] << " " << c[0][0][2] << " " << c[0][0][3] << endl;
}

// tile with A, B
int dist(string &s, int ind, char A, char B) {
	int rtn = 1000000, cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i & 1) {
			if (s[i] != A) cnt++;
		}
		else {
			if (s[i] != B) cnt++;
		}
	}
	rtn = min(rtn, cnt);
	cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i & 1) {
			if (s[i] != B) cnt++;
		}
		else {
			if (s[i] != A) cnt++;
		}
	}

	if (rtn < cnt) {
		for (int j = 0; j < m; j++)
			if (j & 1) {
				t[ind][j] = A;
			}
			else {
				t[ind][j] = B;
			}
	}
	else {
		for (int j = 0; j < m; j++)
			if (j & 1) {
				t[ind][j] = B;
			}
			else {
				t[ind][j] = A;
			}
	}
	return min(rtn, cnt);
}

int calc1(string x) {
	int rtn = 0;
	for (int i = 0; i < n; i++)
		if (i & 1)
			rtn += dist(s[i], i, x[0], x[1]);
		else
			rtn += dist(s[i], i, x[2], x[3]);
	return rtn;
}
int calc2(vector<int> x) {
//	cout << "trying ";
//	for (auto &i : x) cout << toc(i) << " "; cout << endl;
	int rtn = 0;
	int mn, at;
	for (int j = 0; j < m; j++) {
		mn = inf, at = -1;
		if (j & 1) {
			for (int i = 0; i < 4; i += 2) {
				if (n - c[j][0][x[i]] - c[j][1][x[2 ^ i]] < mn) {
					mn = n - c[j][0][x[i]] - c[j][1][x[2 ^ i]];
					at = i;
				}
			}
		}
		else {
			for (int i = 1; i < 4; i += 2) {
				if (n - c[j][0][x[i]] - c[j][1][x[2 ^ i]] < mn) {
					mn = n - c[j][0][x[i]] - c[j][1][x[2 ^ i]];
					at = i;
				}
			}
		}
		rtn += mn;
//		cout << "for column " << j << " it is " << at << " dist " << mn << '\n';
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				t[i][j] = toc(x[at]);
			else
				t[i][j] = toc(x[2 ^ at]);
		}
	}
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i], t[i].resize(m);

	preprocess();

	int mn = 1000000, at = -1, tmp, ind = 1;
	string per = ST;
	tmp = calc1(per);
	if (tmp < mn) {
		mn = tmp;
		at = 0;
	}

	while (next_permutation(per.begin(), per.end())) {
		tmp = calc1(per);
		if (tmp < mn) {
			mn = tmp;
			at = ind;
		}
		ind++;
	}

	vector<int> x = { 0,1,2,3 };
	ind = 0;
	int at2 = 0, mn2 = 1000000;
	tmp = calc2(x);
	if (tmp < mn2) {
		mn2 = tmp;
		at2 = ind;
	}
	ind++;
	while (next_permutation(x.begin(), x.end())) {
		tmp = calc2(x);
//		cout << "ind " << ind << '\n';
		if (tmp < mn2) {
			mn2 = tmp;
			at2 = ind;
		}
		ind++;
	}
	if (mn2 < mn) {
		x = { 0, 1, 2, 3 };
		while (at2--) {
			next_permutation(x.begin(), x.end());
		}
		calc2(x);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << t[i][j]; cout << '\n';
		}
		return 0;
	}
	per = ST;
	while (at) {
		next_permutation(per.begin(), per.end());
		at--;
	}
	calc1(per);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << t[i][j]; cout << '\n';
	}
	return 0;
}
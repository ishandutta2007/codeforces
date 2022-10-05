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

const int O = 500001;

int n;
vector<int> A[1000100];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	string s;
	int sum, mn;
	for (int i = 0; i < n; i++) {
		cin >> s;
		sum = 0, mn = 0;
		for (auto &j : s) {
			if (j == '(') sum++;
			else sum--;
			mn = min(mn, sum);
		}
		if (mn >= 0 || -sum + mn >= 0)
			A[sum + O].push_back(mn);
	}
	int ans = 0;
	for (int i = 0; i <= 2 * O; i++) {
		int j = 2 * O - i;
		int c[2] = {}, d[2] = {};
		if (i < j && A[i].size() && A[j].size()) {
			for (auto &k : A[i])
				if (k < 0) c[0]++;
				else
					c[1]++;
			for (auto &k : A[j])
				if (k < 0) d[0]++;
				else
					d[1]++;
			int M;
			M = min(c[0], d[1]);
			c[0] -= M, d[1] -= M, ans += M;
			M = min(c[1], d[0]);
			c[1] -= M, d[0] -= M, ans += M;
			M = min(d[0], d[1]);
			d[0] -= M, d[1] -= M, ans += M;
//			debug("i, j, ans", i, j, ans);
		}
	}
	ans += (int)A[O].size() / 2;
	finish(ans);
}
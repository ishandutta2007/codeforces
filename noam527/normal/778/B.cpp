#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, pcnt, curr, nextkey = 1;
vector<vector<int>> a;
map<string, int> k;
string p[4];

int get() {
	cin >> p[0] >> p[1] >> p[1];
	if (p[1][0] == '0' || p[1][0] == '1') return 3;
	cin >> p[2] >> p[3];
	return 5;
}

void xorb(int r, vector<int> &u, vector<int> &v) {
	for (int i = 0; i < m; i++) a[r][i] = u[i] ^ v[i];
}
void andb(int r, vector<int> &u, vector<int> &v) {
	for (int i = 0; i < m; i++) {
		if ((u[i] ^ v[i]) < 2)
			a[r][i] = u[i] & v[i] & 1;
		else if (u[i] && v[i]) a[r][i] = max(u[i], v[i]);
		else a[r][i] = 0;
	}
}
void orb(int r, vector<int> &u, vector<int> &v) {
	for (int i = 0; i < m; i++) {
		if (!u[i] || !v[i]) a[r][i] = max(u[i], v[i]);
		else if (u[i] < 2 || v[i] < 2) a[r][i] = 1;
		else if (u[i] == v[i]) a[r][i] = u[i];
		else a[r][i] = 1;
	}
}

int main() {
	fast;
	cin >> n >> m;
	a.resize(n + 1, vector<int>(m, 2));
	k["?"] = 0;
	for (int someparameter = 0; someparameter < n; someparameter++) {
		pcnt = get();
		if (!k.count(p[0])) k[p[0]] = curr = nextkey++;
		else curr = k[p[0]];
		if (pcnt == 3) {
			if (p[1][0] == '?') for (int i = 0; i < m; i++) a[curr][i] = 2;
			else for (int i = 0; i < m; i++) a[curr][i] = in(p[1][i]);
		}
		else {
			if (p[2][0] == 'X') xorb(curr, a[k[p[1]]], a[k[p[3]]]);
			if (p[2][0] == 'A') andb(curr, a[k[p[1]]], a[k[p[3]]]);
			if (p[2][0] == 'O') orb(curr, a[k[p[1]]], a[k[p[3]]]);
		}
	}

	string ans[2];
	for (int j = 0, c2 = 0, c3 = 0; j < m; j++, c2 = 0, c3 = 0) {
		for (int i = 1; i < nextkey; i++) {
			if (a[i][j] == 2) c2++;
			if (a[i][j] == 3) c3++;
		}
		if (c2 == c3) ans[0].push_back('0'), ans[1].push_back('0');
		if (c2 > c3) ans[0].push_back('0'), ans[1].push_back('1');
		if (c2 < c3) ans[0].push_back('1'), ans[1].push_back('0');
	}
	cout << ans[0] << endl << ans[1] << endl;
}
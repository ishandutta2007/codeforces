#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, q;
vector<int> pos[256];
int dp[252][252][252];
bool known[252][252][252] = {};
string t[3];

int nxt(char c, int ind) {
	if (ind == md) return md;
	auto it = upper_bound(pos[c].begin(), pos[c].end(), ind);
	if (it == pos[c].end()) return md;
	return *it;
}
int prv(char c, int ind) {
	auto it = lower_bound(pos[c].begin(), pos[c].end(), ind);
	if (it == pos[c].begin()) return -1;
	it--;
	return *it;
}

int calc(int i, int j, int k) {
	if (known[i][j][k]) return dp[i][j][k];
	known[i][j][k] = 1;
	if (i == 0 && j == 0 && k == 0) return dp[i][j][k] = -1;
	dp[i][j][k] = md;
	if (i > 0)
		dp[i][j][k] = min(dp[i][j][k], nxt(t[0][i - 1], calc(i - 1, j, k)));
	if (j > 0)
		dp[i][j][k] = min(dp[i][j][k], nxt(t[1][j - 1], calc(i, j - 1, k)));
	if (k > 0)
		dp[i][j][k] = min(dp[i][j][k], nxt(t[2][k - 1], calc(i, j, k - 1)));
	return dp[i][j][k];
}

/*
bool cmp(const vector<int> &aa, const vector<int> &bb) {
	for (int i = 0; i < aa.size() && i < bb.size(); i++)
		if (aa[i] != bb[i]) return aa[i] < bb[i];
	return aa.size() >= bb.size();
}

bool check() {
	int p[3] = { 0, 0, 0 }, nx[3];
	vector<int> spe[3];
	int ind = -1;
	while (p[0] < t[0].size() || p[1] < t[1].size() || p[2] < t[2].size()) {
		for (int i = 0; i < 3; i++) {
			spe[i].clear();
			if (p[i] < t[i].size()) {
				spe[i].reserve((int)t[i].size() - p[i]);
				int cur = n;
				for (int j = (int)t[i].size() - 1; j >= p[i]; j--) {
					spe[i].push_back(prv(t[i][j], cur));
					cur = spe[i].back();
					if (cur <= ind) {
						if (OO) {
							cout << "failed on " << ind << " " << p[i] << " " << j << '\n';
						}
						return false;
					}
				}
				reverse(spe[i].begin(), spe[i].end());
			}
			else spe[i] = { md };
		}
		for (int i = 0; i < 3; i++) {
			if (cmp(spe[i], spe[(i + 1) % 3]) && cmp(spe[i], spe[(i + 2) % 3])) {
				if (OO) cout << "satisfying string " << i << " index " << p[i] << " with " << spe[i][0] << '\n';
				ind = spe[i][0];
				p[i]++;
				break;
			}
		}
	}
	return true;
}
*/

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		pos[c].push_back(i);
	}
	t[0] = t[1] = t[2] = "";
	while (q--) {
		char op, c;
		int i;
		cin >> op >> i;
		if (op == '+') {
			cin >> c;
			t[i - 1].push_back(c);
			if (i == 1) {
				for (int x = 0; x <= t[1].size(); x++) for (int y = 0; y <= t[2].size(); y++)
					known[t[0].size()][x][y] = false;
			}
			else if (i == 2) {
				for (int x = 0; x <= t[0].size(); x++) for (int y = 0; y <= t[2].size(); y++)
					known[x][t[1].size()][y] = false;
			}
			else {
				for (int x = 0; x <= t[0].size(); x++) for (int y = 0; y <= t[1].size(); y++)
					known[x][y][t[2].size()] = false;
			}
		}
		else
			t[i - 1].pop_back();
		cout << (calc(t[0].size(), t[1].size(), t[2].size()) == md ? "NO\n" : "YES\n");
	}
}
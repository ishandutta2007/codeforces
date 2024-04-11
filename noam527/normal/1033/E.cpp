#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int ask(vector<int> &a) {
	if (a.size() <= 1) return 0;
	cout << "? " << a.size() << endl;
	for (const auto &i : a) cout << i + 1 << " "; cout << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

int acount(int v, vector<int> &sus, int lim = inf) {
	int rtn = 0;
	vector<int> tmp;
	for (int i = 0; i < sus.size() && i <= lim; i++)
		if (sus[i]) tmp.push_back(i);
	if (tmp.size() == 0) return 0;
	tmp.push_back(v);
	rtn += ask(tmp);
	tmp.pop_back();
	rtn -= ask(tmp);
	return rtn;
}

int acount2(int v, vector<int> &sus) {
	int rtn = 0;
	sus.push_back(v);
	rtn += ask(sus);
	sus.pop_back();
	rtn -= ask(sus);
	return rtn;
}

// safe is sorted
int findless(int v, vector<int> &safe) {
	vector<int> sus;
	int p = 0;
	for (int i = 0; i < v; i++) {
		if (p == safe.size() || i < safe[p]) sus.push_back(i);
		else p++;
	}
	return acount(v, sus, inf);
}

int lowerbound(int v, vector<int> &sus, int val) {
	int lo = 0, hi = v - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (acount(v, sus, mid) < val) lo = mid + 1;
		else hi = mid;
	}
	return lo;
}

int n;
vector<vector<int>> g;
vector<int> col;

void mark(int v, int prev, vector<int> &sus) {
	sus[v] = 0;
	for (auto &i : g[v])
		if (i != prev)
			mark(i, v, sus);
}

void color(int v, int c = 0) {
	if (col[v] != -1) return;
	col[v] = c;
	for (const auto &i : g[v])
		color(i, 1 ^ c);
}

bool makepath(int v, int en, int prev, vector<int> &rtn) {
	rtn.push_back(v);
	if (v == en) return true;
	for (auto &i : g[v])
		if (i != prev) {
			if (makepath(i, en, v, rtn)) return true;
		}
	rtn.pop_back();
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	col.resize(n, -1);
	vector<int> sus;
	for (int i = 1, x; i < n; i++) {
		sus.push_back(0);
		for (auto &j : sus) j = 1;
		int tot = acount(i, sus);
		while (tot > 0) {
			x = lowerbound(i, sus, 1);
			mark(x, -1, sus);
			g[i].push_back(x);
			g[x].push_back(i);
			tot = acount(i, sus);
		}
	}
	color(0);

	vector<int> side[2];
	for (int i = 0; i < n; i++)
		side[col[i]].push_back(i);
	vector<int> tmp, t2, answer;
	for (int i = 0; i < 2; i++) {
		tmp.clear();
		for (int j = 1; j < side[i].size(); j++) {
			tmp.push_back(side[i][j - 1]);
			if (acount2(side[i][j], tmp)) {
				for (auto &x : tmp) {
					t2 = { side[i][j], x };
					if (ask(t2)) {
						makepath(side[i][j], x, -1, answer);
						cout << "N " << answer.size() << endl;
						for (const auto &aaa : answer) cout << 1 + aaa << " ";
						cout << endl;
						fflush(stdout);
						return 0;
					}
				}
			}
		}
	}
	cout << "Y " << side[0].size() << endl;
	for (const auto &i : side[0]) cout << 1 + i << " "; cout << endl;
	fflush(stdout);
	return 0;
}
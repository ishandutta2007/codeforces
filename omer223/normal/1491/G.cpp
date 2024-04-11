#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5 + 5;
int n, a[sz], pos[sz], cycid[sz];
vector<vector<int>> cycs;
vector<pii> ret;
queue<int> q;

void cpos(int i, int j) {
	swap(a[i], a[j]);
	swap(pos[a[i]], pos[a[j]]);
	ret.pb({ i, j });
}

void cval(int i, int j) {
	swap(a[pos[i]], a[pos[j]]);
	swap(pos[i], pos[j]);
	ret.pb({ pos[i], pos[j] });
}

void input() {
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i];
		pos[--a[i]] = i;
		cycid[i] = -1;
	}
}

void getCycles() {
	foru(i, 0, n) {
		if (cycid[i] == -1) {
			int curid = cycs.size();
			vector<int> v;
			int iter = i;
			do {
				v.pb(iter);
				cycid[iter] = curid;
				iter = a[iter];
			} while (iter != i);
			cycs.pb(v);
			if (v.size() != 1)
				q.push(curid);
		}
	}
}

void solveTwoCycles(int x, int y) {
	vector<int> vx = cycs[x], vy = cycs[y];
	int xsz = vx.size(), ysz = vy.size();
	foru(i, 0, ysz)
		cpos(vx[0], vy[i]);
	foru(i, 0, xsz)
		cpos(vx[(i + 1) % xsz], vy[0]);
}

void solveOneCycle(int x) {
	if (cycs[x].size() != n) {
		foru(i, 0, n) {
			if (pos[i] == i) {
				cycs.pb({ i });
				solveTwoCycles(x, cycs.size() - 1);
				return;
			}
		}
	}
	else {
		int xsz = cycs[x].size();
		foru(i, 1, xsz - 1)
			cpos(cycs[x][0], cycs[x][i]);
		cpos(cycs[x][1], cycs[x][xsz - 1]);
		cpos(cycs[x][0], cycs[x][xsz - 1]);
		cpos(cycs[x][0], cycs[x][1]);
	}
}

int main() {
	fast;
	input();
	getCycles();
	while (q.size() >= 2) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		solveTwoCycles(x, y);
	}
	if (!q.empty())
		solveOneCycle(q.front());
	cout << ret.size() << '\n';
	for (pii ii : ret)
		cout << ii.ff + 1 << ' ' << ii.ss + 1 << '\n';
	return 0;
}
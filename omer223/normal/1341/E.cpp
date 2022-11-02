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
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e4 + 5, gsz = 1e3 + 5;;
int n, m, g, r;
int d[sz], rea[sz][gsz];
bool vis[sz][gsz];


void input() {
	cin >> n >> m;
	foru(i, 0, m)cin >> d[i];
	sort(d, d + m);
	cin >> g >> r;
}

void bfs() {
	deque<pii> dq;
	rea[0][g] = 0;
	dq.push_front({ 0,g });
	while (!dq.empty()) {
		pii ii = dq.front(); dq.pop_front();
		int i = ii.first, ti = ii.second;
		if (vis[i][ti])continue;
		vis[i][ti] = 1;
		if (ti != 0) {
			if (i != 0 && d[i] - d[i - 1] <= ti && rea[i - 1][ti - (d[i] - d[i - 1])] > rea[i][ti]) {
				rea[i - 1][ti - (d[i] - d[i - 1])] = rea[i][ti];
				dq.push_front({ i - 1,ti - (d[i] - d[i - 1]) });
			}
			if (i != m - 1 && d[i + 1] - d[i] <= ti && rea[i + 1][ti - (d[i + 1] - d[i])] > rea[i][ti]) {
				rea[i + 1][ti - (d[i + 1] - d[i])] = rea[i][ti];
				dq.push_front({ i + 1,ti - (d[i + 1] - d[i]) });
			}
		}
		else {
			if (rea[i][g] == 1e9) {
				rea[i][g] = rea[i][ti] + 1;
				dq.push_back({ i,g });
			}
		}
	}
}

int main() {
	fast;
	input();
	foru(i, 0, m) {
		foru(t, 0, g + 1)rea[i][t] = 1e9;
	}
	bfs();
	vector<int> bst;
	for (int t = g; t >= 0; t--) {
		if (rea[m - 1][t] != 1e9) {
			bst.pb((r+g)*rea[m - 1][t] + (g - t));
		}
	}
	sort(bst.begin(), bst.end());
	if (bst.empty())cout << -1 << '\n';
	else cout << bst[0] << '\n';
	return 0;
}
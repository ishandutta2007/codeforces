#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 200002, L = 19;
int p[N], rp[N], a[N], pos[N];
int up[L][N], ans[N];


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, n) {
		cin >> p[i];
		p[i]--;
		rp[p[i]] = i;
	}
	rep(i, m) {
		cin >> a[i];
		a[i] = rp[a[i] - 1];
	}
	for (int i = m - 1; i >= 0; i--) {
		int x = (a[i] + 1) % n;
		if (pos[x] == 0)
			up[0][i] = m;
		else
			up[0][i] = pos[x];
		pos[a[i]] = i;
	}
	up[0][m] = m;
	rep(i, L - 1)
		rep(j, m + 1)
			up[i + 1][j] = up[i][up[i][j]];
	for (int i = m - 1; i >= 0; i--) {
		int v = i;
		rep(j, L)
			if ((n - 1) & (1 << j))
				v = up[j][v];
		ans[i] = v;
		if (i < m - 1)
			ans[i] = min(ans[i], ans[i + 1]);
	}
	int l, r;
	rep(i, q) {
		cin >> l >> r;
		l--;
		cout << (ans[l] < r ? 1 : 0);
	}

}
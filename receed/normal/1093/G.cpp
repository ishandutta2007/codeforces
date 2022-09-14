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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1 << 18, M = 5, B = 32, INF = 1e9;
int a[N][M];
int tr[B][N * 2];
int ans[B];
int n, k;


void add(int v) {
	rep(i, 1 << k) {
		int x = 0;
		for (int j = 0; j < k; j++)
			x += a[v][j] * ((i & (1 << j)) ? 1 : -1);
		tr[i][N + v] = x;
		for (int j = (N + v) / 2; j; j /= 2)
			tr[i][j] = max(tr[i][j * 2], tr[i][j * 2 + 1]);
	}
}


void getmx(int cl, int cr, int v=1, int l=0, int r=N) {
	if (cr <= l || r <= cl)
		return;
	if (cl <= l && r <= cr) {
		rep(i, 1 << k)
			ans[i] = max(ans[i], tr[i][v]);
		return;
	}
	getmx(cl, cr, v * 2, l, (l + r) / 2);
	getmx(cl, cr, v * 2 + 1, (l + r) / 2, r);
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, t, w;
	cin >> n >> k;
	rep(i, n) {
		rep(j, k)
			cin >> a[i][j];
		add(i);
	}
	cin >> q;
	rep(z, q) {
		cin >> t;
		if (t == 1) {
			cin >> w;
			w--;
			rep(i, k)
				cin >> a[w][i];
			add(w);
		}
		else {
			int an = 0, cl, cr;
			cin >> cl >> cr;
			rep(i, 1 << k)
			ans[i] = -INF;
			getmx(cl - 1, cr);
			for (int i = 0; i < (1 << (k - 1)); i++) {
				int ni = ((1 << k) - 1) ^ i;
				an = max(an, ans[i] + ans[ni]);
			}
			cout << an << '\n';
		}
	}
}
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MAXN = (1 << 18);

int fr[MAXN];
int par[MAXN], sz[MAXN];

struct DSU {
	inline void init() {
		for(int i = 0; i < MAXN; i++) {
			par[i] = -1, sz[i] = 1;
		}
	}
	int root(int x) {
		return (par[x] == -1 ? x : par[x] = root(par[x]));
	}
	inline int join(int x, int y) {
		x = root(x), y = root(y);
		if(x == y) return 0;
		if(sz[x] > sz[y]) {
			swap(x, y);
		}
		int ans = (sz[x] == 1 ? fr[x] : 1) + (sz[y] == 1 ? fr[y] : 1) - 1;
		if(x != y) {
			par[x] = y;
			sz[y] += sz[x];
		}
		return ans;
	}
};

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	//ifstream cin(".in");
	//ofstream cout(".out");
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	ll ans = 0;
	for(i = 1; i <= n; i++) {
		int a; cin >> a;
		fr[a]++;
		ans -= a;
	}
	fr[0]++;
	DSU dsu; dsu.init();
	for(int mask = MAXN - 1; mask > 0; mask--) {
		for(int a = mask; a > 0; a = (mask & (a - 1))) {
			int b = (mask ^ a);
			if(fr[a] && fr[b]) {
				ans += 1LL * mask * dsu.join(a, b);
			}
		}
	}
	cout << ans;

	return 0;
}
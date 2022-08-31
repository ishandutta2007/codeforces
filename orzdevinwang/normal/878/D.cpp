#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 1e5 + 7;
const int lim = 4096;
int n, k, m, now, a[13][N];
bitset< lim > s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k >> m, now = k;
	L(i, 1, k) {
		L(j, 1, n) cin >> a[i][j];
		L(j, 0, lim - 1) if(j >> (i - 1) & 1) s[i].set(j);
	}
	while(m--) {
		int opt, x, y; cin >> opt >> x >> y;
		if(opt == 1) ++now, s[now] = (s[x] | s[y]);
		if(opt == 2) ++now, s[now] = (s[x] & s[y]);
		if(opt == 3) {
			int ans = 0;
			L(i, 1, k) {
				int tmp = 0;
				L(j, 1, k) if(a[j][y] >= a[i][y]) tmp |= 1 << (j - 1);
				if(s[x][tmp]) ans = max(ans, a[i][y]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
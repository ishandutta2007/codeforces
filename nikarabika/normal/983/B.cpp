//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 5e3 + 10,
	  maxl = 2;
int f[maxl][maxn][maxn],
	ans[maxn][maxn],
	a[maxn],
	n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cur = 0,
		prv = 1;
	for (int t = 15; t >= 0; t--) {
		int dis = 1 << t;
		for (int l = 0; l < n; ++l) {
			int len = 1;
			for (int r = l; r < n; r += dis, ++len) {
				if (len == 1)
					f[cur][l][r] = a[l];
				else if (len & 1)
					f[cur][l][r] = f[prv][l][r];
				else
					f[cur][l][r] = f[prv][l][r - dis] ^ f[prv][l + dis][r];
			}
		}
		swap(cur, prv);
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; j++) {
			if (i < j)
				ans[i][j] = max(f[prv][i][j], max(ans[i + 1][j], ans[i][j - 1]));
			else
				ans[i][j] = f[prv][i][j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		cout << ans[fi][se] << '\n';
	}
	return 0;
}
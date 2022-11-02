#include <bits/stdc++.h>
#define chmin(x, y) (x) = min((x), (y))
using namespace std;

int a[500010], b[500010], p[500010];
vector <int> all[500010];
vector <long long> dp[500010];

struct Segment_tree {
	long long T[2000010];
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now] = p[l];
			return ;
		}
		int mid = l + r >> 1; 
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = T[now << 1] + T[now << 1 | 1];
//		cout << "        range:" << l << " " << r << " " << T[now] << endl;
	}
	void Update(int now, int l, int r, int pos, int x) {
		if (l == r) {
			T[now] = min(T[now], 1ll * x);
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	long long Query(int now, int l, int r, int L, int R) {
		if (L > R) return 0;
//		cout << "             Query:" << now << " " << l << " " << r << " " << L << " " << R << endl;
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}seg;

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		all[a[i]].push_back(i);
		dp[a[i]].push_back(1000000000000000000ll);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	seg.Build(1, 1, n);
	long long ans = 1000000000000000000ll;
	for (int i = 0; i < m; i++) {
//		cout << "     i:" << i << endl;
		int x = b[i];
//		cout << "         x:" << x << endl;
		if (i == 0) {
			for (int j = 0; j < all[x].size(); j++) {
				dp[x][j] = seg.Query(1, 1, n, 1, all[x][j] - 1);
			}
		} else {
			for (int j = 0; j < all[x].size(); j++) {
				if (j) chmin(dp[x][j], dp[x][j - 1] + seg.Query(1, 1, n, all[x][j - 1], all[x][j] - 1));
			}
		}
		for (int ii = i == 0 ? 1 : b[i - 1]; ii < x; ii++) {
			for (int j = 0; j < all[ii].size(); j++) {
				int x = all[ii][j];
				seg.Update(1, 1, n, x, 0);
			}
		}
//		for (int j = 0; j < all[x].size(); j++) {
//			cout << "                  dp:" << all[x][j] << " " << dp[x][j] << endl;
//		}
		for (int k = 0; k < all[x].size(); k++) {
			seg.Update(1, 1, n, all[x][k], 0);
		}
		if (i == m - 1) {
			for (int j = 0; j < all[x].size(); j++) {
				ans = min(ans, dp[x][j] + seg.Query(1, 1, n, all[x][j] + 1, n));
			}
			break;
		}
		int y = b[i + 1];
		for (int j = 0; j < all[x].size(); j++) {
			int pos = lower_bound(all[y].begin(), all[y].end(), all[x][j]) - all[y].begin();
			if (pos != all[y].size()) {
//				cout << "                          (" << x << ", " << all[x][j] << ")->(" << y << ", " << all[y][pos] << ")" << endl;
//				cout << "        dp:" << dp[x][j] << " " << seg.Query(1, 1, n, all[x][j] + 1, all[y][pos] - 1) << endl;
				chmin(dp[y][pos], dp[x][j] + seg.Query(1, 1, n, all[x][j] + 1, all[y][pos] - 1));
			}
		}
	}
	if (ans >= 10000000000000000ll) printf("NO\n");
	else printf("YES\n%I64d\n", ans);
	return 0;
}
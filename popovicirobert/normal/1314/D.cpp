#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int INF = 1e9;
const int MAXN = 80;

int vis[MAXN + 1], cst[MAXN + 1][MAXN + 1];
pair <int, int> dp[MAXN + 1][MAXN + 1][MAXN + 1];
int n;

inline int get(int a, int b) {
	for(int x = 1; x <= n; x++) {
		if(vis[dp[a][b][x].second] == 0) {
			return dp[a][b][x].first;
		}
	}
	return INF;
}

int odd[20];
int ans = INF;

void bkt(int pos, int k) {
	if(pos == (k + 1) / 2) {
		int cur = 0;
		for(int i = 0; i < pos; i++) {
			cur += get(odd[i], odd[(i + 1) % pos]);
			cur = min(cur, INF);
		}
		ans = min(ans, cur);
	}
	else {
		if(pos == 0) {
			vis[1] = odd[pos] = 1;
			bkt(pos + 1, k);
		}
		else {
			for(int i = 1; i <= n; i++) {
				vis[i]++;
				odd[pos] = i;
				bkt(pos + 1, k);
				vis[i]--;
			}
		}
	}
}

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	//ifstream cin(".in");
	//ofstream cout(".out");
	int i, j, k;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			cin >> cst[i][j];
		}
		cst[i][i] = INF;
	}
	for(int a = 1; a <= n; a++) {
		for(int b = 1; b <= n; b++) {
			for(int x = 1; x <= n; x++) {
				dp[a][b][x] = {cst[a][x] + cst[x][b], x};
			}
			sort(dp[a][b] + 1, dp[a][b] + n + 1);
		}
	}

	bkt(0, k);

	cout << ans;

	return 0;
}
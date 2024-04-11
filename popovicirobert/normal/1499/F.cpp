#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int MOD = 998244353;
constexpr int MAXN = 5000;

vector<int> g[MAXN + 1];
int sz[MAXN + 1];

inline void add(int& x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int dp[MAXN + 1][MAXN + 1];
int temp[MAXN + 1];

void dfs(int nod, int par, int k) {
	dp[nod][0] = 1;

	for (auto it : g[nod]) {
		if (it == par)
			continue;

		dfs(it, nod, k);

		for (int i = 0; i <= sz[nod]; i++) {
			if (dp[nod][i] == 0)
				continue;

			for (int j = 0; j <= sz[it]; j++) {
				if (dp[it][j] == 0)
					continue;
				
				int coef = (1LL * dp[nod][i] * dp[it][j]) % MOD;

				add(temp[i], coef);
				if (i + j + 1 <= k) {
					add(temp[max(i, j + 1)], coef);
				}
			}
		}

		sz[nod] += sz[it];

		for (int i = 0; i <= sz[nod]; i++) {
			dp[nod][i] = temp[i];
			temp[i] = 0;
		}
	}

	sz[nod]++;
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);	

    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    dfs(1, 0, k);

    int ans = 0;
    for (int i = 0; i <= k; i++) {
    	add(ans, dp[1][i]);
    }
    cout << ans;


    return 0;
}
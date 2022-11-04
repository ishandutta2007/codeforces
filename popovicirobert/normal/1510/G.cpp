#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

// dp[nod][k][2] = costul min. daca vizitezi k chestii;
// 			 [0] = te intorci in nodul nod
//			 [1] = nu te intorci

const int INF = 1e9;
const int MAXN = 100;

vector<int> g[MAXN + 1];
int dp[MAXN + 1][MAXN + 1][MAXN + 1][2];
pair<int, int> from[MAXN + 1][MAXN + 1][MAXN + 1][2];
int sz[MAXN + 1];

void dfs(int nod, int n) {
	for (int j = 0; j <= (int)g[nod].size(); j++) {
		for (int i = 0; i <= n; i++) {
			dp[nod][j][i][0] = dp[nod][j][i][1] = INF;
		}
	}

	dp[nod][0][0][0] = dp[nod][0][0][1] = 0;
	dp[nod][0][1][0] = dp[nod][0][1][1] = 0;
	sz[nod] = 1;

	for (int pos = 0; pos < (int)g[nod].size(); pos++) {
		int it = g[nod][pos];
		dfs(it, n);
		
		for (int i = sz[nod]; i >= 0; i--) {
			for (int j = sz[it]; j >= 0; j--) {

				auto Update = [&](int pos, int k, int t, int old_k, int old_t, int val) {
					if (dp[nod][pos][k][t] > val) {
						dp[nod][pos][k][t] = val;
						from[nod][pos][k][t] = {old_k, old_t};
					}
				};

				int s = (int)g[it].size();
				Update(pos + 1, i + j, 0, i + j, 0, dp[nod][pos][i + j][0]);
				Update(pos + 1, i + j, 0, i, 0, dp[nod][pos][i][0] + dp[it][s][j][0] + 2);

				Update(pos + 1, i + j, 1, i + j, 1, dp[nod][pos][i + j][1]);
				Update(pos + 1, i + j, 1, i, 0, dp[nod][pos][i][0] + dp[it][s][j][1] + 1);
				Update(pos + 1, i + j, 1, i, 1, dp[nod][pos][i][1] + dp[it][s][j][0] + 2);

				// dp[nod][pos + 1][i + j][0] = min(dp[nod][pos + 1][i + j][0],
				// 								 dp[nod][pos][i][0] + dp[it][pos][j][0] + 2);

				// dp[nod][pos + 1][i + j][1] = min(dp[nod][i + j][1],
				// 								 min(dp[nod][i][0] + dp[it][pos][j][1] + 1,
				// 									 dp[nod][i][1] + dp[it][pos][j][0] + 2));
			}
		}
		sz[nod] += sz[it];
	}
}

void findPath(int nod, int k, int t, vector<int>& sol) {
	vector<int> tmp;

	sol.push_back(nod);
	for (int pos = g[nod].size(); pos > 0; pos--) {
		int it = g[nod][pos - 1];
		pair<int, int> cur = from[nod][pos][k][t];

		if (k > cur.first) {
			if (t > cur.second) {
				findPath(it, k - cur.first, t - cur.second, tmp);
			} else {
				findPath(it, k - cur.first, t - cur.second, sol);
				sol.push_back(nod);
			}
		}

		tie(k, t) = cur;
	}

	for (auto it : tmp) {
		sol.push_back(it);
	}
}


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	for (int i = 1; i <= n; i++) {
    		g[i].clear();
    	}
    	for (int i = 2; i <= n; i++) {
    		int par;
    		cin >> par;
    		g[par].push_back(i);
    	}

    	dfs(1, n);

    	vector<int> sol;
    	findPath(1, k, 1, sol);

    	cout << (int)sol.size() - 1 << "\n";
    	for (auto it : sol) {
    		cout << it << " ";
    	}
    	cout << "\n";
    }

    return 0;
}
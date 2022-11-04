#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int INF = 1e9;
const int MAXM = 10000;
const int MAXR = 1000;

vector<pair<int, int>> g[MAXM];

int dp[MAXM][MAXR + 1];
bool vis[MAXM][MAXR + 1];

struct Node {
	int nod, rem;
};

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n >> m;
   	vector<int> x(m);
   	for(i = 0; i < m; i++) {
   		cin >> x[i];
   	}
   	sort(x.begin(), x.end());

   	int R, G;
   	cin >> G >> R;

   	for(i = 0; i < m; i++) {
   		for(j = 0; j <= G; j++) {
   			dp[i][j] = INF;
   		}
   	}

   	deque<Node> pq;

   	pq.push_back({0, 0});
   	dp[0][0] = 0;

   	while(pq.size()) {
   		int nod, rem;
   		nod = pq.front().nod;
   		rem = pq.front().rem;
   		pq.pop_front();

   		if(vis[nod][rem] == true)
   			continue;

   		vis[nod][rem] = true;

   		if(rem == G) {
   			if(dp[nod][0] > dp[nod][rem] + 1) {
   				dp[nod][0] = dp[nod][rem] + 1;
   				pq.push_back({nod, 0});
   			}
   		}

   		if(nod > 0 && rem + x[nod] - x[nod - 1] <= G) {
   			int new_rem = rem + x[nod] - x[nod - 1];
   			if(dp[nod - 1][new_rem] > dp[nod][rem]) {
   				dp[nod - 1][new_rem] = dp[nod][rem];
   				pq.push_front({nod - 1, new_rem});
   			}
   		}
   		if(nod + 1 < m && rem + x[nod + 1] - x[nod] <= G) {
   			int new_rem = rem + x[nod + 1] - x[nod];
   			if(dp[nod + 1][new_rem] > dp[nod][rem]) {
   				dp[nod + 1][new_rem] = dp[nod][rem];
   				pq.push_front({nod + 1, new_rem});
   			}
   		}
   	}

   	int ans = INF;
   	for(j = 0; j <= G; j++) {
   		ll cur = 1LL * (R + G) * dp[m - 1][j] + j;
   		if(cur < INF) {
   			ans = min(ans, (int)cur);
   		}
   	}

   	if(ans == INF) {
   		ans = -1;
   	}
   	cout << ans;
    
    return 0;
}
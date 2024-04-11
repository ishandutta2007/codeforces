//============================================================================
// Name        : 548C.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
// bad, good

struct p{
	int v, c;
};

const ll MOD = 1000000007;
const int MAX = 100001, MK = 101;
int n, k, ba, bb, bc,
	parv[MAX], parcs[MAX];
ll dp[2][MAX], dp2[2][MAX][MK];
vector<p> matrix[MAX];
vector<int> order, rorder;

void dfs(int cur, int par){
	rorder.push_back(cur);
	parv[cur] = par;

	for(p adj : matrix[cur]){
		if(adj.v ^ par){
			parcs[adj.v] = adj.c;
			dfs(adj.v, cur);
		}
	}

	order.push_back(cur);
}

inline void dpa(){
	for(int cur : order){
		int par = parv[cur];
		dp[0][cur] = 1;

			for(p adj : matrix[cur]){
				if(adj.v ^ par){
					dp[1][cur] += dp[1][adj.v];
					if(adj.c)
						dp[1][cur] += dp[0][adj.v];
					else
						dp[0][cur] += dp[0][adj.v];
				}
			}

			dp[0][cur] %= MOD;
			dp[1][cur] %= MOD;

			if(dp[0][cur] < 0) dp[0][cur] += MOD;
			if(dp[1][cur] < 0) dp[1][cur] += MOD;
	}
}

inline void dpb(){
	for(int cur : rorder){
		int par = parv[cur], parc = parcs[cur];
		if(par != -1){
				dp[1][cur] += dp[1][par] - dp[1][cur];
				if(parc)
					dp[1][cur] += dp[0][par] - dp[0][cur];
				else
					dp[0][cur] += dp[0][par] - dp[0][cur];

				dp[0][cur] %= MOD;
				dp[1][cur] %= MOD;

				if(dp[0][cur] < 0) dp[0][cur] += MOD;
				if(dp[1][cur] < 0) dp[1][cur] += MOD;
			}
	}
}

inline void dpc(int ck){
	for(int cur : order){
		int par = parv[cur];
		dp2[0][cur][ck] = dp2[0][cur][ck - 1];
			dp2[1][cur][ck] = dp2[1][cur][ck - 1];

			for(p adj : matrix[cur]){
				if(adj.v ^ par){
					dp2[1][cur][ck] += dp2[1][adj.v][ck];
					if(adj.c)
						dp2[1][cur][ck] += dp2[0][adj.v][ck];
					else
						dp2[0][cur][ck] += dp2[0][adj.v][ck];
				}
			}

			dp2[0][cur][ck] %= MOD;
			dp2[1][cur][ck] %= MOD;

			if(dp2[0][cur][ck] < 0) dp2[0][cur][ck] += MOD;
			if(dp2[1][cur][ck] < 0) dp2[1][cur][ck] += MOD;
	}
}

inline void dpd(int ck){
	for(int cur : rorder){
		int par = parv[cur], parc = parcs[cur];
		if(par != -1){
				dp2[1][cur][ck] += dp2[1][par][ck] - dp2[1][cur][ck];
				if(parc)
					dp2[1][cur][ck] += dp2[0][par][ck] - dp2[0][cur][ck];
				else
					dp2[0][cur][ck] += dp2[0][par][ck] - dp2[0][cur][ck];

				dp2[0][cur][ck] %= MOD;
				dp2[1][cur][ck] %= MOD;

				if(dp2[0][cur][ck] < 0) dp2[0][cur][ck] += MOD;
				if(dp2[1][cur][ck] < 0) dp2[1][cur][ck] += MOD;
			}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i < n; ++i) {
		cin >> ba >> bb >> bc;
		matrix[ba].push_back({bb, bc});
		matrix[bb].push_back({ba, bc});
	}

	dfs(1, -1);
	dpa();
	dpb();

	for (int i = 1; i <= n; i++){
		dp2[0][i][0] = dp[0][i];
		dp2[1][i][0] = dp[1][i];
	}

	for (int i = 1; i < k - 1; ++i) {
		dpc(i);
		dpd(i);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp2[1][i][k - 2]) % MOD;

	cout << ans << endl;
}
#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5 + 10;
int dp[maxn], dp2[maxn], pd[maxn], dpin[maxn];
bool she[maxn];
vector<int> adj[maxn];
int n, m, k;

void DP(int v, int p){
	for(int i = 0; i < adj[v].size(); i++) if(adj[v][i] != p){
		int u = adj[v][i];
		DP(u, v);
		int dpu = dp[u];
		if(dpu == -2){
			if(she[u])
				dpu = 0;
			else
				continue;
		}
		dpu++;
		if(dpu > dp[v])
			dp2[v] = dp[v], dp[v] = dpu, dpin[v] = u;
		else if(dpu > dp2[v])
			dp2[v] = dpu;
	}
}

void PD(int v, int p){
	int pdp = pd[p];
	if(pd[p] == -2 and she[p])
		pdp = 0;
	if(pdp != -2 and pdp + 1 > pd[v])
		pd[v] = pdp + 1;
	if(p == 0)
		goto children;
	if(dpin[p] == v){
		if(dp2[p] != -2) pd[v] = max(pd[v], dp2[p] + 1);
	}
	else if(dp[p] != -2)
		pd[v] = max(pd[v], dp[p] + 1);
children:
	for(int i = 0; i < adj[v].size(); i++) if(adj[v][i] != p)
		PD(adj[v][i], v);
	//cerr << v << ": " << pd[v] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	for(int i = 0; i < maxn; i++)
		dp[i] = -2, pd[i] = -2, dp2[i] = -2;
	cin >> n >> m >> k;
	while(m--){
		int fi;
		cin >> fi;
		she[fi] = true;
	}
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	DP(1, 0);
	PD(1, 0);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(max(dp[i], pd[i]) <= k)
			ans++;
	/*if(n == 50){
		cout << 9 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		cout << dp[i] << ' ';
	cout << endl;
	for(int i = 1; i <= n; i++)
		cout << pd[i] << ' ';
	cout << endl;*/
	cout << ans << endl;
	return 0;
}
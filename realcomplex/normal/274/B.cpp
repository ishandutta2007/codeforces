#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];
ll x[N];

ll dp[N][2];

void dfs(int u, int par){
	ll dop = 0;
	ll iop = 0;
	for(auto x : T[u]){
		if(x == par)
			continue;
		dfs(x, u);
		iop = max(iop, dp[x][0]);
		dop = max(dop, dp[x][1]);
	}
	ll sum = iop - dop;
	if(sum < x[u])
		iop += x[u] - sum;
	else
		dop += sum - x[u];
	dp[u][0] = iop;
	dp[u][1] = dop;
}

int main(){
	fastIO;
	int n;
	int a, b;
	cin >> n;
	for(int i = 0 ; i < n - 1; i ++ ){
		cin >> a >> b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	for(int i = 1; i <= n; i ++ ){
		cin >> x[i];
	}
	dfs(1, -1);
	cout << dp[1][0] + dp[1][1];
	return 0;
}
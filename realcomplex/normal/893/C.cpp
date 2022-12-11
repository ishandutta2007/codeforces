#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100007;
vector<int>G[N];
bool has[N];
int cost[N];

ll ans = 0;
int ct = INT_MAX;

void dfs(int t){
	ct = min(ct,cost[t]);
	has[t] = true;
	for(auto x : G[t]){
		if(!has[x])
			dfs(x);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int a,b;
	for(int i = 1;i<=n;i++)
		cin >> cost[i];
	for(int i = 1;i<=m;i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(has[i])
			continue;
		ct = INT_MAX;
		dfs(i);
		ans += ct;
	}
	cout << ans << "\n";
	return 0;
}
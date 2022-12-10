#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e3 + 10;
vector<int> adj[maxn];
int n, k;
int a[maxn], dp[maxn];
bool m[maxn][maxn];

void DP(int x){
	if(adj[x].size() == 0)
		dp[x] = 1;
	for(int i = 0; i < adj[x].size(); i++){
		if(dp[adj[x][i]] == 0)
			DP(adj[x][i]);
		if(dp[adj[x][i]] + 1 > dp[x])
			dp[x] = dp[adj[x][i]] + 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < i; j++)
			m[a[j]][a[i]] = 1;
	}
	for(int asghar = 1; asghar < k; asghar++){
		for(int i = 0; i < n; i++){
			cin >> a[i];
			for(int j = 0; j < i; j++)
				m[a[i]][a[j]] = 0;
		}
	}
	vector<int> source;
	for(int i = 1; i <= n; i++){
		bool x = true;
		for(int j = 1; j <= n; j++)
			if(m[j][i]){
				x = false;
				adj[j].PB(i);
			}
		if(x)
			source.PB(i);
	}
	int ans = 0;
	for(int i = 0; i < source.size(); i++){
		DP(source[i]);
		if(dp[source[i]] > ans)
			ans = dp[source[i]];
	}
	cout << ans << endl;
	return 0;
}
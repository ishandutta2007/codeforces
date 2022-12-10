//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100;
vector<int> adj[maxn];
LD dp[2][maxn];
int dis[2][maxn],
	n, m;
bool mark[maxn];

void bfs(int source, int d[], LD cnt[]){
	memset(mark, false, sizeof mark);
	queue<int> Q;
	Q.push(source);
	mark[source] = true;
	cnt[source] = 1;
	while(sz(Q)){
		int v = Q.front();
		Q.pop();
		for(auto u : adj[v]){
			if(!mark[u]){
				d[u] = d[v] + 1;
				mark[u] = true;
				Q.push(u);
			}
			if(d[u] == d[v] + 1)
				cnt[u] += cnt[v];
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	bfs(0 + 0, dis[0], dp[0]);
	bfs(n - 1, dis[1], dp[1]);
	LD ans = 1;
	for(int i = 1; i < n - 1; i++)
		if(dis[0][i] + dis[1][i] == dis[1][0])
			smax(ans, dp[0][i] * dp[1][i] * 2 / dp[1][0]);
	cout.precision(15);
	cout << fixed << ans << endl;
	return 0;
}
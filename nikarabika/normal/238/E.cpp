//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 100 + 10;
bool mark[maxn],
	 cut[maxn][maxn];
int dis[maxn][maxn],
	ans[maxn],
	frm[maxn],
	too[maxn],
	n, m, so, sy;
queue<int> q;
vector<int> adj[maxn],
	dag[maxn][maxn];

void bfs(int so){
	dis[so][so] = 0;
	q.push(so);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if(dis[so][u] + 1 < dis[so][v]){
				dis[so][v] = dis[so][u] + 1;
				q.push(v);
			}
			if(dis[so][u] + 1 == dis[so][v])
				dag[so][u].PB(v);
		}
	}
	return;
}

void dfs(int u, int com, int mx){
	mark[u] = true;
	for(auto v : dag[com][u])
		if(!mark[v] and (ans[v] >= mx or ans[v] == -1))
			dfs(v, com, mx);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> so >> sy, so--, sy--;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
	}
	memset(dis, 63, sizeof dis);
	for(int i = 0; i < n; i++)
		bfs(i);
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> frm[i] >> too[i];
		frm[i]--, too[i]--;
		if(dis[frm[i]][too[i]] > 1000){
			i--, k--;
			continue;
		}
		for(int d = 0; d < 100; d++){
			int cnt = 0,
				ver = -1;
			for(int u = 0; u < n; u++)
				if(dis[frm[i]][u] == d and d + dis[u][too[i]] == dis[frm[i]][too[i]])
					cnt++, ver = u;
			if(cnt == 1)
				cut[ver][i] = true;
		}
	}
	memset(ans, -1, sizeof ans);
	ans[sy] = 0;
	for(int i = 1; i <= k; i++){
		int upd = 0;
		for(int u = 0; u < n; u++){
			if(ans[u] == -1){
				for(int j = 0; j < k; j++)
					if(cut[u][j]){
						memset(mark, false, sizeof mark);
						dfs(u, frm[j], i);
						if(!mark[too[j]]){
							ans[u] = i;
							upd++;
							break;
						}
					}
			}
		}
		if(!upd) break;
	}
	//for(int i = 0; i < n; i++)
	cout << (ans[so] > 1000 ? -1 : ans[so]) << '\n';
	return 0;
}
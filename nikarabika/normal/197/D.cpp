//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1500 + 1,
	  maxn4 = maxn * 4,
	  maxnn = maxn * maxn;
vector<piii> adj[maxn4];
pii dis[maxn4],
	initpos;
int comp[maxn][maxn],
	dx[4] = {-1, 0, 0, +1},
	dy[4] = {0, -1, +1, 0},
	n, m, compcnt;
char maz[maxn][maxn];
bool mark[maxn][maxn],
	 mark2[maxn4];

pii operator+(pii x, pii y){
	return MP(x.L + y.L, x.R + y.R);
}

bool ok(int x, int y){
	return x >= 0 and x < n
		and y >= 0 and y < m
		and maz[x][y] != '#';
}

void dfs_table(int x, int y){
	if(mark[x][y])
		return;
	comp[x][y] = compcnt;
	mark[x][y] = true;
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i],
			yy = y + dy[i];
		if(ok(xx, yy))
			dfs_table(xx, yy);
	}
	return;
}

void an(int i, int j){
	if(ok(i, j)){
		dfs_table(i, j);
		compcnt++;
	}
	return;
}

void dfs(int v, pii dist){
	if(mark2[v]){
		if(dist == dis[v])
			return;
		cout << "Yes";
		exit(0);
	}
	mark2[v] = true;
	dis[v] = dist;
	for(auto e : adj[v])
		dfs(e.L, dist + e.R);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> maz[i][j];
			if(maz[i][j] == 'S')
				initpos = MP(i, j);
		}
	if(min(n, m) == 1)
		return cout << "Yes", 0;
	memset(comp, -1, sizeof comp);
	for(int i = 0; i < n; i++){
		an(i, 0);
		an(i, m - 1);
	}
	for(int j = 0; j < m; j++){
		an(0, j);
		an(n - 1, j);
	}
	for(int i = 0; i < n; i++){
		if(~comp[i][0] and ~comp[i][m - 1]){
			adj[comp[i][0]].PB(MP(comp[i][m - 1], MP(0, -1)));
			adj[comp[i][m - 1]].PB(MP(comp[i][0], MP(0, +1)));
		}
	}
	for(int j = 0; j < m; j++){
		if(~comp[0][j] and ~comp[n - 1][j]){
			adj[comp[0][j]].PB(MP(comp[n - 1][j], MP(+1, 0)));
			adj[comp[n - 1][j]].PB(MP(comp[0][j], MP(-1, 0)));
		}
	}
	dfs(comp[initpos.L][initpos.R], MP(0, 0));
	cout << "No";
	return 0;
}
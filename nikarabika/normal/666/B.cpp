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

const int maxn = 3000 + 85 - 69;
int dis[maxn][maxn];
bool mark[maxn];
int Max[maxn][3],
	Max2[maxn][3];
vector<int> adj[maxn];
int n, m;

void bfs(int v, int d[]){
	queue<int> q;
	memset(mark, false, sizeof mark);
	q.push(v);
	d[v] = 0;
	mark[v] = true;
	while(sz(q)){
		int v = q.front();
		q.pop();
		for(auto u : adj[v])
			if(!mark[u]){
				mark[u] = true;
				d[u] = d[v] + 1;
				q.push(u);
			}
	}
	return;
}

void add(int v, int u){
	for(int i = 0; i < 3; i++){
		if(Max[v][i] == -1 or dis[v][u] > dis[v][Max[v][i]]){
			for(int j = 2; j > i; j--)
				Max[v][j] = Max[v][j - 1];
			Max[v][i] = u;
			break;
		}
	}
	return;
}

void add2(int v, int u){
	for(int i = 0; i < 3; i++){
		if(Max2[u][i] == -1 or dis[v][u] > dis[Max2[u][i]][u]){
			for(int j = 2; j > i; j--)
				Max2[u][j] = Max2[u][j - 1];
			Max2[u][i] = v;
			break;
		}
	}
	return;
}

void make_apsp(void){
	for(int i = 0; i < n; i++){
		bfs(i, dis[i]);
		for(int j = 0; j < n; j++)
			if(i != j and dis[i][j] != -1)
				add(i, j), add2(i, j);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dis, -1, sizeof dis);
	memset(Max, -1, sizeof Max);
	memset(Max2, -1, sizeof Max2);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
	}
	make_apsp();
	int ans = -1;
	pair<pii, pii> out;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) if(i != j and dis[i][j] != -1){
			for(int ii = 0; ii < 3; ii++)
				for(int jj = 0; jj < 3; jj++){
					int v = Max2[i][ii],
						u = Max[j][jj];
					if(v == -1 or u == -1 or i == u or v == u or j == v)
						continue;
					if(dis[v][i] + dis[i][j] + dis[j][u] > ans){
						ans = dis[v][i] + dis[i][j] + dis[j][u];
						out = {{v, i}, {j, u}};
					}
				}
		}
	}
	cout << out.L.L + 1 << ' ' << out.L.R+1 << ' ' << out.R.L+1 << ' ' << out.R.R+1 << '\n';
	return 0;
}
//sobskdrbhvk
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

const int maxn = 301,
	  maxnn = maxn * maxn;
int dis[maxnn];
int a[maxn][maxn];
vector<int> vec[maxnn];
int n, m, p;
int sou;
vector<int> adj[maxnn],
	colvec[maxn];
int ptr[maxn];
int row[maxnn], col[maxnn];

int dist(int v, int u){
	return abs(row[v] - row[u]) + abs(col[v] - col[u]);
}

void relax(int v, int u){
	if(dis[v] + dist(v, u) < dis[u])
		dis[u] = dis[v] + dist(v, u);
	return;
}

void dijkstra(void){
	memset(dis, 63, sizeof dis);
	dis[sou] = 0;
	for(int val = p; val > 1; val--){
		for(int j = 0; j < m; j++)
			colvec[j].clear(), ptr[j] = 0;
		for(auto pos : vec[val])
			colvec[col[pos]].PB(row[pos]);
		for(auto pos : vec[val - 1]){
			int x = row[pos];
			for(int j = 0; j < m; j++){
				while(ptr[j] < sz(colvec[j]) and colvec[j][ptr[j]] < x) ptr[j]++;
				if(ptr[j] < sz(colvec[j])) relax(colvec[j][ptr[j]] * m + j, pos);
				if(ptr[j] > 0) relax(colvec[j][ptr[j] - 1] * m + j, pos);
			}
		}
	}
	return;
}

int main(){
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			row[i * m + j] = i, col[i * m + j] = j;
			scanf("%d", a[i] + j);
			vec[a[i][j]].PB(i * m + j);
			if(a[i][j] == p)
				sou = i * m + j;
		}
	dijkstra();
	int ans = 1e9;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == 1)
				smin(ans, dis[i * m + j] + i + j);
	printf("%d\n", ans);
	return 0;
}
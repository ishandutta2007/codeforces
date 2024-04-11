#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<int, int> pie;

const int maxn = 2e3 + 10, maxl = 15;
int n, visited, V;
vector<pair<int, pie> > a;
int d[maxn][maxn];
vector<pie> adj[maxn];
pie parr[maxn];
bool mark[maxn], dmark[maxn];

void dfs(int x, int p = -1, LL co = 0){
	dmark[x] = true;
	visited++;
	if(co != d[V][x]){
		cout << "NO" << endl;
		exit(0);
	}
	for(int i = 0; i < adj[x].size(); i++){
		if(!dmark[adj[x][i].L]){
			dfs(adj[x][i].L, x, co + adj[x][i].R);
		}
		else if(adj[x][i].L != p){
			cout << "NO" << endl;
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &d[i][j]);
			a.PB(MP(d[i][j], MP(i, j)));
			if((i != j and d[i][j] == 0) or (j < i and d[i][j] != d[j][i])){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(d[i][i] != 0){
			cout << "NO" << endl;
			return 0;
		}
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for(int p = 0; p < a.size(); p++){
		if(mark[a[p].R.L] or mark[a[p].R.R])
			continue;
		int v = a[p].R.L, u = a[p].R.R;
		if(v == u)
			continue;
		if(!mark[v]){
			mark[v] = true;
			int Min = 1e9 + 10, Mini = 0;
			for(int i = 1; i <= n; i++)
				if(!mark[i] and d[v][i] < Min)
					Min = d[v][i], Mini = i;
			int c = 0;
			for(int i = 1; i <= n; i++)
				if(!mark[i])
					if(d[v][i] == Min)
						c++;
			if(c > 1){
				cout << "NO" << endl;
				return 0;
			}
			if(Mini != 0)
				parr[v] = MP(Mini, Min);
		}
		if(!mark[u]){
			mark[u] = true;
			int Min = 1e9 + 10, Mini = 0;
			for(int i = 1; i <= n; i++)
				if(!mark[i] and d[u][i] < Min)
					Min = d[u][i], Mini = i;
			int c = 0;
			for(int i = 1; i <= n; i++)
				if(!mark[i])
					if(d[u][i] == Min)
						c++;
			if(c > 1){
				cout << "NO" << endl;
				return 0;
			}
			if(Mini != 0)
				parr[u] = MP(Mini, Min);
		}
	}
	for(int i = 1; i <= n; i++) if(parr[i] != MP(0, 0)){
		adj[parr[i].L].PB(MP(i, parr[i].R));
		adj[i].PB(MP(parr[i].L, parr[i].R));
	}
	for(int i = 1; i <= n; i++){
		memset(dmark, false, sizeof dmark);
		visited = 0;
		V = i;
		dfs(i);
		if(visited != n){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 110;
vector<pii> adj[maxn];
int col[maxn];
bool mark[maxn];
int n, m;

void dfs(int v, int c = 0){
	mark[v] = true;
	col[v] = c;
	for(auto u : adj[v]){
		if(!mark[u.L])
			dfs(u.L, (u.R ? c : 1 - c));
		else if(col[u.L] != (u.R ? c : 1 - c)){
			cout << "Impossible\n";
			exit(0);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i);
	cout << count(col, col + n, 1) << endl;
	for(int i = 0; i < n; i++)
		if(col[i] == 1)
			cout << i + 1 << ' ';
	cout << endl;
	return 0;
}
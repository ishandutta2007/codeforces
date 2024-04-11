#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 405;

bool adj[N][N];

int n;
int dd[N];

int bfs(int u, bool ok){
	for(int i = 1;i <= n;i ++ )
		dd[i] = (int)1e9 + 9;
	queue<int> ki;
	ki.push(u);
	dd[u] = 0;
	while(!ki.empty()){
		u = ki.front();
		ki.pop();
		for(int i = 1; i <= n; i ++ ){
			if(i == u)
				continue;
			if(adj[u][i] != ok)
				continue;
			if(dd[u] + 1 < dd[i]){
				dd[i] = dd[u] + 1;
				ki.push(i);
			}
		}
	}
	return dd[n];
}

int main(){
	fastIO;
	int m;
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; i ++ ){
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
	}
	int ans = -1;
	if(adj[1][n]){
		ans = bfs(1, false);
	}
	else{
		ans = bfs(1, true);
	}
	if(ans == (int)1e9 + 9)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}
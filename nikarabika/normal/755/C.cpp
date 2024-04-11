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

const int maxn = 1e5 + 10;
bool mark[maxn];
vector<int> adj[maxn];
int n;

void dfs(int u){
	mark[u] = true;
	for(auto v : adj[u])
		if(!mark[v])
			dfs(v);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x, x--;
		adj[i].PB(x);
		adj[x].PB(i);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i), cnt++;
	cout << cnt << endl;
	return 0;
}
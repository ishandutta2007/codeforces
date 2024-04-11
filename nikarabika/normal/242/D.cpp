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

const int maxn = 1e5 + 85 - 69;
int a[maxn],
	b[maxn];
bool mark[maxn];
vector<int> adj[maxn],
	fri[maxn],
	ans;
queue<int> q;
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
		fri[fi].PB(se);
		fri[se].PB(fi);
	}
	for(int i = 0; i < n; i++)
		cin >> a[i], adj[i].PB(i), fri[i].PB(i);
	for(int i = 0; i < n; i++)
		if(a[i] == b[i])
			q.push(i);
	while(sz(q)){
		int v = q.front();
		q.pop();
		if(a[v] != b[v]) continue;
		while(mark[fri[v].back()])
			fri[v].pop_back();
		int u = fri[v].back();
		fri[v].pop_back();
		mark[u] = true;
		for(auto uu : adj[u]){
			b[uu]++;
			if(a[uu] == b[uu])
				q.push(uu);
		}
	}
	for(int i = 0; i < n; i++)
		if(mark[i])
			ans.PB(i+1);
	cout << sz(ans) << '\n';
	for(auto v : ans)
		cout << v << ' ';
	cout << '\n';
	return 0;
}
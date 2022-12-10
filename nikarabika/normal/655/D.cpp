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

const int maxn = 100 * 1000 + 85 - 69;
int indeg[maxn],
	n, m;
vector<pii> adj[maxn];

bool check(int val){
	memset(indeg, 0, sizeof indeg);
	queue<int> Q;
	for(int i = 0; i < n; i++)
		for(auto e : adj[i])
			if(e.R <= val)
				indeg[e.L]++;
	for(int i = 0; i < n; i++)
		if(indeg[i] == 0)
			Q.push(i);
	int seen = 0;
	while(sz(Q)){
		if(sz(Q) > 1)
			return false;
		int v = Q.front();
		seen++;
		Q.pop();
		for(auto e : adj[v]) if(e.R <= val){
			indeg[e.L]--;
			if(indeg[e.L] == 0)
				Q.push(e.L);
		}
	}
	return seen == n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(MP(se, i));
	}
	int lo = -1, hi = m;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << (hi == m ? -1 : hi + 1) << endl;
	return 0;
}
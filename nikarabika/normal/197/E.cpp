//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LL> Point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1500 + 85 - 69;
vector<int> adj[maxn];
Point P[maxn];
int vec[maxn][maxn],
	vecsz[maxn],
	down[maxn],
	ans[maxn],
	n, cmpvert;

inline LL cross(Point x, Point y){
	return x.real() * y.imag() - x.imag() * y.real();
}

bool cmp(int i, int j){
	return cross(P[i] - P[cmpvert], P[j] - P[cmpvert]) > 0;
}

int rightmost(int id){
	int ret = vec[id][0];
	for(int i = 0; i < vecsz[id]; i++){
		int val = vec[id][i];
		if(P[val].real() > P[ret].real())
			ret = val;
	}
	return ret;
}

int dfs_preprocess(int v, int p = -1){
	down[v] = 1;
	for(auto u : adj[v])
		if(u != p)
			down[v] += dfs_preprocess(u, v);
	return down[v];
}

void dfs(int v, int vecid, int p = -1){
	int fv = rightmost(vecid);
	ans[fv] = v;
	int idtmp = find(vec[vecid], vec[vecid] + vecsz[vecid], fv) - vec[vecid];
	swap(vec[vecid][idtmp], vec[vecid][vecsz[vecid] - 1]);
	vecsz[vecid]--;
	cmpvert = fv;
	sort(vec[vecid], vec[vecid] + vecsz[vecid], cmp);
	int ptr = 0;
	for(int i = 0; i < sz(adj[v]); i++) if(adj[v][i] != p){
		int u = adj[v][i];
		for(int j = ptr; j < ptr + down[u]; j++)
			vec[vecid + 1][j - ptr] = vec[vecid][j];
		vecsz[vecid + 1] = down[u];
		ptr += down[u];
		dfs(u, vecid + 1, v);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < n; i++){
		LL xx, yy;
		cin >> xx >> yy;
		P[i] = Point(xx, yy);
		vec[0][vecsz[0]++] = i;
	}
	dfs_preprocess(0);
	dfs(0, 0);
	for(int i = 0; i < n; i++)
		cout << ans[i] + 1 << ' ';
	cout << '\n';
	return 0;
}
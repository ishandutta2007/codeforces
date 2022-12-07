#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

struct dsu{
	int lab[N];

	void rezero(){
		memset(lab, -1, sizeof lab);
		/// actually -1 :)))
	}

	int par(int u){
		if(lab[u] < 0) return u;
		return (lab[u] = par(lab[u]));
	}

	bool join(int u, int v){
		u = par(u); v = par(v);
		if(u == v) return false;
		if(lab[u] > lab[v]) swap(u, v);
		lab[u] += lab[v];
		lab[v] = u;
	}

	int comp(int x){
		return -lab[par(x)];
	}
}dsu;

int n;
int a[N];
int app[N];
vector < int > g[N];

bool cmp(int u, int v){
	return a[u] < a[v];
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	vector < int > perm;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		perm.push_back(i);
	}

	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	sort(perm.begin(), perm.end(), cmp);

	long long ans = 0;

	dsu.rezero();

	for(int x : perm){
		app[x] = 1;

		int tot = 1;

		for(int y : g[x]){
			if(!app[y]) continue;
			
			ans += 1LL * a[x] * 1LL * tot * dsu.comp(y);
			tot += dsu.comp(y);
			dsu.join(x, y);
		}
	}

	memset(app, 0, sizeof app);

	reverse(perm.begin(), perm.end());

	dsu.rezero();

	for(int x : perm){
		app[x] = 1;

		int tot = 1;

		for(int y : g[x]){
			if(!app[y]) continue;
			
			ans -= 1LL * a[x] * 1LL * tot * dsu.comp(y);
			tot += dsu.comp(y);
			dsu.join(x, y);
		}
	}

	cout << ans;
	return 0;
}
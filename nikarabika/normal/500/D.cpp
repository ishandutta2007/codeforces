//in the name of "God"
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef long double LD;
typedef pair<int, LD> pid;
typedef pair<int, int> pie;

const int maxn = 1e5 + 85 - 85 + 1;
vector<pid> v[maxn];
vector<pie> E;
LL n, q, f[maxn], h[maxn];
LD ans, g[maxn];
LL down[maxn], up[maxn];
pid par[maxn];

void dfs(int x, int p = -1, LD w = 0){
	par[x] = MP(p, w);
	down[x] = 1;
	for(auto adj : v[x]){
		int y = adj.L;
		LD ww = adj.R;
		if(y == p)
			continue;
		h[y] = h[x] + 1;
		dfs(y, x, ww);
		down[x] += down[y];
	}
}

void UP(int x){
	if(up[x] != -1)
		return;
	int p = par[x].L;
	UP(p);
	up[x] = up[p] + down[p] - down[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		LD th;
		cin >> fi >> se >> th;
		E.PB(MP(fi, se));
		v[fi].PB(MP(se, th));
		v[se].PB(MP(fi, th));
	}
	dfs(1);
	memset(up, -1, sizeof up);
	up[1] = 0;
	for(int i = 2; i <= n; i++){
		UP(i);
		f[i] = up[i] * down[i] * (down[i] - 1) / 2 + down[i] * up[i] * (up[i] - 1) / 2;
		g[i] = f[i] * 12 / LD(n * (n - 1) * (n - 2));
		ans += g[i] * par[i].R;
	}
	cout.precision(10);
	cin >> q;
	while(q--){
		int fi;
		LD se;
		cin >> fi >> se;
		fi--;
		if(h[E[fi].L] < h[E[fi].R])
			swap(E[fi].L, E[fi].R);
		int x = E[fi].L;
		ans -= g[x] * par[x].R;
		par[x].R = se;
		ans += g[x] * par[x].R;
		cout << fixed << ans << '\n';
	}
	return 0;
}
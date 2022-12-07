#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct vertex{
	int fr, to, comp;
	int l[11];
	int r[11];
};

int lab[N * 10];  
int n, m, q;
int a[11][N];
vertex it[N * 4];

vertex dead(){
	vertex ans;
	ans.to = 0;
	return ans;
}

int par(int u){
	if(lab[u] == 0){
		return u;
	}
	return lab[u] = par(lab[u]);
}

vector < int > change;

bool join(int u, int v){
	u = par(u); v = par(v);
	if(u == v) return false;
	change.push_back(v);
	lab[v] = u;
	return true;
}

vertex Merge(vertex v, vertex u){
	if(v.to == 0) return u;
	if(u.to == 0) return v;

	vertex ans;
	ans.comp = u.comp + v.comp;

	for(int i = 1; i <= n; ++i){
		if(a[i][v.to] == a[i][v.to + 1]){
			ans.comp -= join(v.r[i], u.l[i]);
		}
	}

	ans.to = u.to;
	ans.fr = v.fr;

	for(int i = 1; i <= n; ++i){
		ans.r[i] = par(u.r[i]);
		ans.l[i] = par(v.l[i]);
	}

	for(int x : change){
		lab[x] = 0;
	}
	change.clear();
	return ans;
}

#define ii (i << 1)
#define mid ((l + r) >> 1)

int cnt = 0;

void build(int i, int l, int r){
	it[i].fr = l; it[i].to = r;
	if(l == r){
		for(int j = 1; j <= n; ++j){
			if(a[j][r] == a[j - 1][r]){
				it[i].l[j] = it[i].r[j] = it[i].r[j - 1];
			}
			else{
				++it[i].comp;
				it[i].l[j] = it[i].r[j] = ++cnt;
			}
		}
		return;
	}
	build(ii, l, mid);
	build(ii + 1, mid + 1, r);
	it[i] = Merge(it[ii], it[ii + 1]);

}

vertex query(int i, int l, int r, int x, int y){
	if(l >= x && r <= y) return it[i];
	if(l > y || r < x) return dead();
	return Merge(query(ii, l, mid, x, y), query(ii + 1, mid + 1, r, x, y));
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &m, &q);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
		}
	}

	build(1, 1, m);

	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(1, 1, m, l, r).comp);
	}

	return 0;
}
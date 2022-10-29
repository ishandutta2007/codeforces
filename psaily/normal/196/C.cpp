#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

typedef long long LL;

const int N = 1510;

int X, Y;

struct node{
	int x, y;
	int id;
	friend bool operator < (const node &a, const node &b){
		return (LL)(a.y - Y) * (b.x - X) < (LL)(b.y - Y) * (a.x - X);
	}
} p[N];

vector <int> v[N];
int sz[N], ans[N];
int n;

void dfs(int x, int fa){
	sz[x] = 1;
	for (auto u : v[x]){
		if (u == fa) continue;
		dfs(u, x);
		sz[x] += sz[u];
	}
}

void calc(int x, int fa, int l, int r){
	int t = l;
	rep(i, l + 1, r){
		if (p[i].y < p[t].y || (p[t].y == p[i].y && p[i].x < p[t].x))
			t = i;
	}

	if (t != l) swap(p[l], p[t]);
	ans[p[l].id] = x;
	X = p[l].x, Y = p[l].y;
	sort(p + l + 1, p + r + 1);
	int pos = l + 1;

	for (auto u : v[x]){
		if (u == fa) continue;
		calc(u, x, pos, pos + sz[u] - 1);
		pos += sz[u];
	}
}

int main(){

	scanf("%d", &n);
	rep(i, 1, n - 1){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	rep(i, 1, n){
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = {x, y, i};
	}

	dfs(1, 0);
	calc(1, 0, 1, n);
	rep(i, 1, n) printf("%d\n", ans[i]);

	return 0;
}
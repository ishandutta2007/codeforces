#include <bits/stdc++.h>
#define VAL (l <= lca && lca <= r ? val[lca] : 0)
#define LSON (l <= lca && lca <= mid ? val[lca] : 0)
using namespace std;

typedef unsigned long long ull;

ull seed = 584738295847381095;

ull myrand() {
	seed ^= seed << 13, seed ^= seed >> 17, seed ^= seed << 5;
	return seed;
}

ull val[300010];
int dep[300010];

struct Node {
	ull sum;
	Node *lson, *rson;
	void pushup() {sum = lson->sum ^ rson->sum;}
	Node() {sum = 0, lson = rson = NULL;}
}pool[7000000], *CUR = pool, *rt[300010];

Node *Build(int l, int r) {
	if (l == r) return CUR++;
	int mid = l + r >> 1;
	Node *T = CUR++;
	T->lson = Build(l, mid), T->rson = Build(mid + 1, r);
	return T;
}

Node *Update(Node *T, int l, int r, int pos, ull x) {
	Node *nT = CUR++; nT->sum = T->sum, nT->lson = T->lson, nT->rson = T->rson; 
	if (l == r) {
		nT->sum ^= x;
		return nT;
	}
	int mid = l + r >> 1;
	if (pos <= mid) nT->lson = Update(T->lson, l, mid, pos, x);
	else nT->rson = Update(T->rson, mid + 1, r, pos, x);
	nT->pushup();
	return nT;
}

int n;
vector <int> from[300010];
int a[300010];
int fa[300010][19];

void dfs(int x, int last) {
	fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, rt[v] = Update(rt[x], 1, n, a[v], val[a[v]]), dfs(v, x);
	}
}

int Query(Node *T1, Node *T2, int l, int r, int L, int R, int lca) {
	if (l == L && r == R) {
		if (T1->sum == (T2->sum ^ VAL)) return -1;
		if (l == r) return l;
		int mid = l + r >> 1;
		if (T1->lson->sum != (T2->lson->sum ^ LSON)) return Query(T1->lson, T2->lson, l, mid, l, mid, lca);
		return Query(T1->rson, T2->rson, mid + 1, r, mid + 1, r, lca);
	}
	int mid = l + r >> 1;
	if (R <= mid) return Query(T1->lson, T2->lson, l, mid, L, R, lca);
	if (L > mid) return Query(T1->rson, T2->rson, mid + 1, r, L, R, lca);
	return max(Query(T1->lson, T2->lson, l, mid, L, mid, lca), 
			   Query(T1->rson, T2->rson, mid + 1, r, mid + 1, R, lca));
}

int get_lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 18; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int main () {
	int q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		val[i] = myrand();
	}
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	rt[1] = Update(Build(1, n), 1, n, a[1], val[a[1]]), dfs(1, 1);
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	while (q--) {
		int x, y, l, r; scanf("%d%d%d%d", &x, &y, &l, &r);
		int lca = get_lca(x, y);
		printf("%d\n", Query(rt[x], rt[y], 1, n, l, r, a[lca]));
	}
	return 0;
}
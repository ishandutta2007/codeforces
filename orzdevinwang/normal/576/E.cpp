#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
struct UFS {
	stack< pii > stk;
	int fa[N << 1], siz[N << 1]; // George1123  siz
	int find(int x) { return fa[x] == x ? x : find(fa[x]); }
	void init(int x) {
		L(i, 1, x) fa[i] = i, siz[i] = 1;
	}
	bool Merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return 0;
		if(siz[x] > siz[y]) swap(x, y);
		stk.push(mkp(x, siz[x]));
		siz[y] += siz[x], fa[x] = y;
		return 1;
	} 
	void revoke() {
		int x = stk.top().first;
		siz[fa[x]] -= stk.top().second, fa[x] = x, stk.pop();
	}
} ufs[51];
int n, m, q, k, las[N], U[N], V[N], col[N];
struct node {
	int Eid, col; 
} ask[N]; 
vector< int > ve[N << 2];
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ve[id].push_back(val), void();
	int mid = (L + R) / 2;
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
}
int Ans[N];
void dfs(int id, int L, int R) {
	int Cnt[51] = {};
	L(i, 1, 50) Cnt[i] = 0;
	for(int x : ve[id]) if(ask[x].col) 
		Cnt[ask[x].col] += ufs[ask[x].col].Merge(U[ask[x].Eid], V[ask[x].Eid] + n), 
		Cnt[ask[x].col] += ufs[ask[x].col].Merge(V[ask[x].Eid], U[ask[x].Eid] + n), 
		assert(U[ask[x].Eid] != V[ask[x].Eid]);
	if(L == R) {
		if(ufs[ask[L].col].find(U[ask[L].Eid]) != ufs[ask[L].col].find(V[ask[L].Eid])) printf("YES\n"), col[ask[L].Eid] = ask[L].col;
		else printf("NO\n"), ask[L].col = col[ask[L].Eid];
	}
	else {
		int mid = (L + R) / 2;
		dfs(id << 1, L, mid), dfs(id << 1 | 1, mid + 1, R);		 
	}
	L(i, 1, k) while(Cnt[i]--) ufs[i].revoke();
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	L(i, 1, m) scanf("%d%d", &U[i], &V[i]);
	L(i, 1, q) scanf("%d%d", &ask[i].Eid, &ask[i].col);
	L(i, 1, m) las[i] = q + 1; 
	R(i, q, 1) {
		int l = i + 1, r = las[ask[i].Eid] - 1;
		if(l <= r) add(1, 1, q, l, r, i);
		las[ask[i].Eid] = i;
	}
	L(i, 1, k) ufs[i].init(2 * n);
	dfs(1, 1, q);
	return 0;
}
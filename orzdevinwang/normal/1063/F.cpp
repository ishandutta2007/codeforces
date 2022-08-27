#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pil pair<int, lonf long>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int fa[N], ch[N][26], len[N], tot = 1, las = 1;
void copy(int x, int y) { L(i, 0, 25) ch[y][i] = ch[x][i]; fa[y] = fa[x], len[y] = len[x]; }
void ins(int x) {
	int p = las, now = las = ++tot;
	len[now] = len[p] + 1;
	for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
	if(!p) fa[now] = 1;
	else {
		int pto = ch[p][x];
		if(len[pto] == len[p] + 1) fa[now] = pto;
		else {
			int sp = ++tot; copy(pto, sp), len[sp] = len[p] + 1;
			fa[now] = fa[pto] = sp;
			for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp; 
		}
	}
}
int seg[N << 2];
void add(int id, int L, int R, int wz, int val) {
	if(L == R) return seg[id] = val, void();
	int mid = (L + R) / 2;
	if(wz <= mid) add(id << 1, L, mid, wz, val);
	else add(id << 1 | 1, mid + 1, R, wz, val);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return seg[id];
	int mid = (L + R) / 2, res = 0;
	if(l <= mid) res = max(res, query(id << 1, L, mid, l, r));
	if(r > mid) res = max(res, query(id << 1 | 1, mid + 1, R, l, r));
	return res;
} 
int n, m;
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int id[N], siz[N], idtot;
void dfs(int x) {
	id[x] = ++idtot, siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) dfs(e[i].to), siz[x] += siz[e[i].to];
} 
int pos[N], up[20][N];
int get(int now, int Len) {
	R(i, 19, 0) if(len[up[i][now]] >= Len) now = up[i][now];
	return now;
}
int dp[N], ans;
bool can(int wz, int val) {
	int now;
	now	= get(pos[wz], val); if(query(1, 1, tot, id[now], id[now] + siz[now] - 1) >= val) return 1;
	now = get(pos[wz - 1], val); if(query(1, 1, tot, id[now], id[now] + siz[now] - 1) >= val) return 1;
	return 0;
}
char s[N];
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1), reverse(s + 1, s + n + 1);
	L(i, 1, n) ins(s[i] - 'a'), pos[i] = las;
	L(i, 1, tot) up[0][i] = fa[i], add_edge(fa[i], i); 
	dfs(1); 
	L(i, 1, 19) L(j, 1, tot) up[i][j] = up[i - 1][up[i - 1][j]];
	L(i, 1, n) {
		dp[i] = dp[i - 1] + 1;
		while(dp[i] > 1 && !can(i, dp[i] - 1)) {
			dp[i] --; int wz = i - dp[i];
			add(1, 1, tot, id[get(pos[wz], dp[wz])], dp[wz]);
		} 
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 2e5 + 7;
const int M = 8e6 + 7;
int n; ll ans = 2;
int posa[N], posb[N];
struct SuffixAutoMaton {
	int head[N], fa[N], ch[N][26], len[N], las = 1, tot = 1;
	void copy(int x, int y) {
		L(i, 0, 25) ch[y][i] = ch[x][i];
		fa[y] = fa[x], len[y] = len[x];
	}
	void ins(int x) {
		int p = las, now = las = ++tot;
		len[now] = len[p] + 1;
        for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
		if(!p) fa[now] = 1;
		else {
			int pto = ch[p][x];
			if(len[pto] == len[p] + 1) fa[now] = pto;
			else {
				int sp = ++tot;
				copy(pto, sp), len[sp] = len[p] + 1;
				fa[now] = fa[pto] = sp;
				for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
			} 
		}
	}
} sama, samb;
int hd[N], nxt[N], with[N], id[N], dep[N], jp[20][N], totid;
void add_edge(int u, int v) { nxt[v] = hd[u], hd[u] = v; }
void DFS(int x) {
	id[x] = ++totid, with[totid] = x;
	for(int i = hd[x]; i; i = nxt[i]) dep[i] = dep[x] + 1, jp[0][i] = x, DFS(i);
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	int dx = x, dy = y;
	R(i, 18, 0) if((dep[x] - dep[y]) >= (1 << i)) x = jp[i][x];
	if(x == y) return x;
	R(i, 18, 0) if(jp[i][x] != jp[i][y]) x = jp[i][x], y = jp[i][y];
	return jp[0][x];
}
struct Segmenttree {
	int maxl[M], maxr[M], ch[M][2], tot; ll sum[M];
	void upd(int x) {
		maxl[x] = (ch[x][0] ? maxl[ch[x][0]] : maxl[ch[x][1]]);
		maxr[x] = (ch[x][1] ? maxr[ch[x][1]] : maxr[ch[x][0]]);
		sum[x] = sum[ch[x][0]] + sum[ch[x][1]];
		if(!ch[x][0] || !ch[x][1]) return;
		sum[x] -= samb.len[lca(with[maxr[ch[x][0]]], with[maxl[ch[x][1]]])];
	}
 	void ins(int &x, int L, int R, int wz) {
		if(!x) x = ++tot;
		if(L == R) return maxl[x] = maxr[x] = wz, sum[x] = samb.len[with[wz]], void();
		int mid = (L + R) / 2;
		if(wz <= mid) ins(ch[x][0], L, mid, wz);
		else ins(ch[x][1], mid + 1, R, wz);
		upd(x);
	} 
	int merge(int x, int y) {
		if(!x || !y) return x | y;
		int nd = ++tot;
		ch[nd][0] = merge(ch[x][0], ch[y][0]);
		ch[nd][1] = merge(ch[x][1], ch[y][1]);
		upd(nd);
		return nd;
	}
} seg;
int c[N], q[N];
void work() {
    L(i, 1, sama.tot) c[sama.len[i]]++;
    L(i, 1, sama.tot) c[i] += c[i - 1];
    L(i, 1, sama.tot) q[c[sama.len[i]]--] = i;
    R(i, sama.tot, 1) sama.head[sama.fa[q[i]]] = seg.merge(sama.head[sama.fa[q[i]]], sama.head[q[i]]);
    L(i, 1, sama.tot) ans += 1ll * (sama.len[i] - sama.len[sama.fa[i]]) * seg.sum[sama.head[i]];
}
char s[N];
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	L(i, 1, n) sama.ins(s[i] - 'a'), posa[i] = sama.las, ans += sama.len[sama.las] - sama.len[sama.fa[sama.las]], 
                                                         (i != n) && (ans += sama.len[sama.las] - sama.len[sama.fa[sama.las]]);
	R(i, n, 1) samb.ins(s[i] - 'a'), posb[i] = samb.las, (i != 1) && (ans += samb.len[samb.las] - samb.len[samb.fa[samb.las]]);
    L(i, 2, samb.tot) add_edge(samb.fa[i], i);
	dep[1] = 0, DFS(1);
	L(i, 1, 18) L(j, 1, samb.tot) jp[i][j] = jp[i - 1][jp[i - 1][j]];
	L(i, 1, n - 2) seg.ins(sama.head[posa[i]], 1, totid, id[posb[i + 2]]);
    work();
    printf("%lld\n", ans);
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
using namespace std;
const int N = 2e5 + 6;
const int SN = 4e6;
const int cN = 26;
int n, pn, m;
struct Merge_Segment {
	int ch[SN][2], sum[SN], tot;
	int merge(int x, int y) {
		if(!x || !y) return x + y;
		int George = ++tot;
		ch[George][0] = merge(ch[x][0], ch[y][0]);
		ch[George][1] = merge(ch[x][1], ch[y][1]);
		sum[George] = (sum[ch[George][0]] | sum[ch[George][1]]);
		return George;
	}
	void add(int &id, int L, int R, int wz) {
		if(!id) id = ++tot;
		sum[id] = true;
		if(L == R) return;
		int mid = (L + R) / 2;
		if(wz <= mid) add(ch[id][0], L, mid, wz);
		else add(ch[id][1], mid + 1, R, wz);
	}
	bool query(int id, int L, int R, int l, int r) {
		if(id == 0) return 0;
		if(l <= L && R <= r) return sum[id];
		int mid = (L + R) / 2, res = 0;
		if(l <= mid) res |= query(ch[id][0], L, mid, l, r);
		if(r > mid) res |= query(ch[id][1], mid + 1, R, l, r);
		return res;
	}
} seg;
struct sam {
	int ch[N][cN], head[N], fa[N], len[N], las = 1, tot = 1;
	void copy(int x, int y) {
		L(i, 0, cN - 1) ch[y][i] = ch[x][i];
		fa[y] = fa[x], len[y] = len[x];
	}
	void ins(int x, int y) {
		int p = las, now = las = ++tot;
		len[now] = len[p] + 1, seg.add(head[now], 1, n, y);
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
} t;
int q[N], c[N];
void work() {
	L(i, 1, t.tot) c[t.len[i]] ++;
	L(i, 1, t.tot) c[i] += c[i - 1];
	L(i, 1, t.tot) q[c[t.len[i]]--] = i;
	R(i, t.tot, 1) t.head[t.fa[q[i]]] = seg.merge(t.head[t.fa[q[i]]], t.head[q[i]]);
}
int l, r, tot;
char s[N], g[N];
bool dfs(int now, int x) {
	if(x == pn) {
		L(i, 0, cN - 1) if(t.ch[now][i] && seg.query(t.head[t.ch[now][i]], 1, n, l + x, r)) return g[++tot] = i + 'a', 1;
		return 0;
	}
	if(t.ch[now][s[x] - 'a'] && dfs(t.ch[now][s[x] - 'a'], x + 1)) return g[++tot] = s[x], 1;
	L(i, s[x] - 'a' + 1, cN - 1) if(t.ch[now][i] && seg.query(t.head[t.ch[now][i]], 1, n, l + x, r)) return g[++tot] = i + 'a', 1;
	return 0;
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int i = 1; i <= n; i++) t.ins(s[i] - 'a', i);
	work();
	scanf("%d", &m);
	while(m--) {
		tot = 0;
		scanf("%d%d", &l, &r);
		scanf("%s", s), pn = strlen(s);
		if(!dfs(1, 0)) printf("-1");
		else for(int i = tot; i >= 1; i--) putchar(g[i]);
		puts("");
	}
	return 0;
}
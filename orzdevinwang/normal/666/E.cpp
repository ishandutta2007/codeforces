#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 1e5 + 7;
const int tN = 5e5 + 7;
const int cN = 26;
const int M = 1e7;
int n, tn, m, Q, ls[tN], Lx[tN];
int jp[N][22];
struct Max {
	int maxn, maxid;
};
bool operator < (Max aa, Max bb) { return aa.maxn < bb.maxn ? 1 : (aa.maxn == bb.maxn && aa.maxid > bb.maxid); }
struct SegmentTree {
	int sum[M], ch[M][2], tot;
	Max maxn[M];
	void add(int &id, int L, int R, int wz) {
		if(!id) id = ++tot;
		sum[id]++;
		if(L == R) return (void)(maxn[id].maxid = L, maxn[id].maxn = sum[id]);
		int mid = (L + R) / 2;
		if(wz <= mid) add(ch[id][0], L, mid, wz);
		else add(ch[id][1], mid + 1, R, wz);
		maxn[id] = max(maxn[ch[id][0]], maxn[ch[id][1]]);
	}
	int merge(int x, int y, int L, int R) { // sto Rainbow_sjy orz
		if(!x || !y) return x | y;
		int Rainbow_sjy = ++tot, mid = (L + R) / 2;
		sum[Rainbow_sjy] = sum[x] + sum[y];
		if(L == R) {
			maxn[Rainbow_sjy].maxid = L, maxn[Rainbow_sjy].maxn = sum[Rainbow_sjy];
			return Rainbow_sjy;
		}
		ch[Rainbow_sjy][0] = merge(ch[x][0], ch[y][0], L, mid);
		ch[Rainbow_sjy][1] = merge(ch[x][1], ch[y][1], mid + 1, R);
		maxn[Rainbow_sjy] = max(maxn[ch[Rainbow_sjy][0]], maxn[ch[Rainbow_sjy][1]]);
		return Rainbow_sjy;
	}
	Max query(int id, int L, int R, int l, int r) {
		if(id == 0) return maxn[id];
		if(l == L && R == r) return maxn[id];
		int mid = (L + R) / 2;
		if(r <= mid) return query(ch[id][0], L, mid, l, r);
		if(l > mid) return query(ch[id][1], mid + 1, R, l, r);
		return max(query(ch[id][0], L, mid, l, mid), query(ch[id][1], mid + 1, R, mid + 1, r));
	}
} seg;
struct SAM {
	int head[N], fa[N], len[N], ch[N][cN], las = 1, tot = 1;
	void copy(int x, int y) {
		L(i, 0, cN - 1) ch[y][i] = ch[x][i];
		len[y] = len[x], fa[y] = fa[x];
	}
	void ins(int x, int y) {
		if(ch[las][x] && len[ch[las][x]] == len[las] + 1) {
			las = ch[las][x];
			seg.add(head[las], 1, m, y);//, cout << "nederlandakioi!/qq\n";
			return;
		}
		int p = las, now = las = ++tot;
		len[now] = len[p] + 1;
		seg.add(head[now], 1, m, y);//, cout << "George1123akioi!/qq\n";
		for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
		if(!p) fa[now] = 1;
		else {
			int pto = ch[p][x];
			if(len[pto] == len[p] + 1) fa[now] = pto;
			else {
				int sp = ++tot;
				copy(pto, sp), len[sp] = len[p] + 1;
				fa[pto] = fa[now] = sp;
				for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
			}
		}
	}
} sam;
int c[N], q[N];
void work() {
	L(i, 1, sam.tot) c[sam.len[i]]++;
	L(i, 1, sam.tot) c[i] += c[i - 1];
	L(i, 1, sam.tot) q[c[sam.len[i]]--] = i;
	R(i, sam.tot, 1) sam.head[sam.fa[q[i]]] = seg.merge(sam.head[sam.fa[q[i]]], sam.head[q[i]], 1, m);
}
void getans(int x, int len, int L, int R) {
	if(Lx[x] < len) return (void)(printf("%d 0\n", L));
	x = ls[x];
	R(i, 20, 0) if(sam.len[jp[x][i]] >= len) x = jp[x][i];
	Max gg = seg.query(sam.head[x], 1, m, L, R);
	if(gg.maxn) printf("%d %d\n", gg.maxid, gg.maxn);
	else printf("%d 0\n", L);
}
char s[N], ss[tN];
int main() {
	scanf("%s", ss + 1), scanf("%d", &m);
	L(t, 1, m) {
		sam.las = 1;
		scanf("%s", s), n = strlen(s);
		L(i, 0, n - 1) sam.ins(s[i] - 'a', t);
	}
	work();
	int now = 1, L = 1;
	n = strlen(ss + 1);
	L(i, 1, n) {
		while(now > 1 && !sam.ch[now][ss[i] - 'a']) now = sam.fa[now], L = sam.len[now];
		if(sam.ch[now][ss[i] - 'a']) now = sam.ch[now][ss[i] - 'a'], ++L;
		ls[i] = now, Lx[i] = L;
	}
	L(i, 1, sam.tot) jp[i][0] = sam.fa[i];
	L(j, 1, 20) L(i, 1, sam.tot) jp[i][j] = jp[jp[i][j - 1]][j - 1];
	scanf("%d", &Q);
	while(Q--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		getans(d, d - c + 1, a, b);	
	}
	return 0;
}
#include <stdio.h>
#include <bits/stdc++.h>
#define ls nod[p].lch
#define rs nod[p].rch
#define mid ((l + r) >> 1)

using namespace std;

const int N = 200010;

struct ST {
	struct Node {int lch, rch, x;} nod[N * 40];
	int rt[N << 1], cnt;

	void pushup(int p) {nod[p].x = nod[ls].x | nod[rs].x;}

	void Mdf(int &p, int l, int r, int x) {
		if (!p) p = ++cnt;
		if (l == r) return (void)(nod[p].x++);
		if (x <= mid) Mdf(ls, l, mid, x);
		else Mdf(rs, mid + 1, r, x);
		return pushup(p); 
	}

	int merge(int x, int y) {
		if(!x || !y) return x + y;
		int p = ++cnt;
		ls = merge(nod[x].lch, nod[y].lch);
		rs = merge(nod[x].rch, nod[y].rch);
		return pushup(p), p;
	}

	int Qry(int p, int l, int r, int tl, int tr) {
		if (r < tl || tr < l) return 0; 
		if(tl <= l && r <= tr) return nod[p].x;
		return Qry(ls, l, mid, tl, tr) | Qry(rs, mid + 1, r, tl, tr);
	}
}	st;

int c[N], a[N << 1], pos[N << 1];

struct SAM {
	struct Node {int ch[26], len, fa;} nod[N << 1];
	int cur, lst;
	
	void insert(int x) {
		int p = lst, np = lst = ++cur;
		nod[np].len = nod[p].len + 1;
		for (; p && !nod[p].ch[x]; p = nod[p].fa) nod[p].ch[x] = np;
		if (!p) nod[np].fa = 1;
		else {
			int q = nod[p].ch[x];
			if (nod[q].len == nod[p].len + 1) nod[np].fa = q;
			else {
				int nq = ++cur; nod[nq] = nod[q], pos[nq] = pos[q];
				nod[nq].len = nod[p].len + 1;
				nod[q].fa = nod[np].fa = nq;
				for (; p && nod[p].ch[x] == q; p = nod[p].fa) nod[p].ch[x] = nq;
			}
		}
	}

	void build(int n, char *s) {
		cur = lst = 1;
		for (int i = 1; i <= n; i++)
			insert(s[i] - 'a'), st.Mdf(st.rt[lst], 1, n, i), pos[lst] = i;
		for (int i = 1; i <= cur; i++) c[nod[i].len]++;
		for (int i = 1; i <= n; i++) c[i] += c[i - 1];
		for (int i = cur; i >= 1; i--) a[c[nod[i].len]--] = i;
		for (int i = cur; i >= 2; i--) st.rt[nod[a[i]].fa] = st.merge(st.rt[nod[a[i]].fa], st.rt[a[i]]);
	}
}	Sam;

int n, fa[N << 1], f[N << 1], A = 1; char s[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void con(int x, int y) {if(find(x) != find(y)) fa[fa[x]] = fa[y];}

int main() {
	scanf("%d%s", &n, s + 1);
	Sam.build(n, s);
	for (int i = 1; i <= Sam.cur; i++) fa[i] = i;
	for (int i = 2; i <= Sam.cur; i++) {
		int x = a[i], y = find(Sam.nod[x].fa);
		if (y == 1) {f[x] = 1; continue;}
		if (st.Qry(st.rt[y], 1, n, pos[x] - Sam.nod[x].len + Sam.nod[y].len, pos[x] - 1))
			f[x] = f[y] + 1;
		else f[x] = f[y], con(x, y);
		A = max(A, f[x]);
	}
	printf("%d\n", A);
	return 0;
}
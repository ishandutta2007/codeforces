#include <stdio.h>
struct Tr {int l, r, m, s; Tr *son[2];};
const int N = 2e5 + 1;
int n, q;
Tr mem[N * 40], *root[N], *tot = mem;
void build(register Tr *&root, register int l, register int r) {
	register int m;
	root = tot++;
	*root = (Tr) {l, r, m = l + r >> 1, 0};
	root->son[0] = root->son[1] = 0;
	if(l == r) return;
	build(root->son[0], l, m);
	build(root->son[1], m + 1, r);
}
void insert(Tr *&root, register int p) {
	*tot = *root, root = tot++;
	++root->s;
	if(root->l == root->r) return;
	insert(root->son[p > root->m], p);
}
int query(Tr *root, register int l, register int r) {
	if(root->l > r || root->r < l) return 0;
	if(root->l >= l && root->r <= r) return root->s;
	return query(root->son[0], l, r) + query(root->son[1], l, r);
}
int sum(register int l, register int r, register int d, register int u) {
	return query(root[r], d, u) - query(root[l - 1], d, u);
}
long long c(register long long x) {return x * (x - 1ll) / 2;}
int main() {
	register int i;
	scanf("%d%d", &n, &q);
	build(root[0], 1, n);
	for(i = 1; i <= n; ++i) {
		register int p;
		scanf("%d", &p);
		insert(root[i] = root[i - 1], p);
	}
	for(i = 1; i <= q; ++i) {
		register int l, r, u, d;
		scanf("%d%d%d%d", &l, &d, &r, &u); --l, ++r, --d, ++u;
		register int sd = sum(1, n, 1, d), su = sum(1, n, u, n), sl = sum(1, l, 1, n), sr = sum(r, n, 1, n);
		register int ld = sum(1, l, 1, d), rd = sum(r, n, 1, d), lu = sum(1, l, u, n), ru = sum(r, n, u, n);
//		printf("d%d u%d l%d r%d ld%d rd%d lu%d ru%d\n", sd, su, sl, sr, ld, rd, lu, ru);
		printf("%lld\n", c(n) - c(sd) - c(su) - c(sl) - c(sr) + c(ld) + c(rd) + c(lu) + c(ru));
	}
	return 0;
}
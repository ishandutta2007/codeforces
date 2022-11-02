#include <stdio.h>
#include <string.h>
#define For(i, l, r) for(register int i = l, _ = r; i <= _; ++i)
int F() {
	register int a, b, c;
	while(c = getchar(), c < '-');
	b = c == '-';
	for(a = b ? 0 : c - '0'; c = getchar(), c > '-'; a = a * 10 + c - '0');
	return b ? -a : a;
}
const int N = 5e5 + 5;
int n, fa[N], siz[N], w[N], row[N], col[N];
char ans[N];
int find(register int x) {
	if(x == fa[x]) return x;
	register int ret = find(fa[x]);
	w[x] ^= w[fa[x]];
	return fa[x] = ret;
}
void connect(register int x, register int y) {
	register int z;
	if(siz[x] < siz[y]) z = x, x = y, y = z;
	find(x), find(y);
	z = 1 ^ w[x] ^ w[y];
	x = fa[x], y = fa[y];
	fa[y] = x, siz[x] += siz[y], w[y] = z;
}
int main() {
	n = F();
	For(i, 1, n) fa[i] = i, siz[i] = 1;
	For(i, 1, n) {
		register int x = F(), y = F();
		if(row[x]) connect(i, row[x]), row[x] = 0; else row[x] = i;
		if(col[y]) connect(i, col[y]), col[y] = 0; else col[y] = i;
	}
	For(i, 1, n) find(i), ans[i] = w[i] ? 'b' : 'r';
	puts(ans + 1);
	return 0;
}
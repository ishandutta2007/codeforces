#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
struct LCT {
	int siz[N], mx[N], s[N], ch[N][2], fa[N], flag[N];
	bool get(int x) {
		return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
	}
	void upd(int x) {
		mx[x] = max(s[x], max(mx[ch[x][0]], mx[ch[x][1]]));
		siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	}
	void flip(int x) {
		swap(ch[x][0], ch[x][1]), flag[x] ^= 1;
	}
	void pushdown(int x) {
		if(!flag[x]) return;
		flip(ch[x][0]), flip(ch[x][1]), flag[x] ^= 1;
	}
	void rotate(int x) {
		int y = fa[x], z = fa[y], fson = (ch[y][1] == x), ano = ch[x][fson ^ 1];
		if(get(y)) ch[z][ch[z][1] == y] = x;
		if(ano) fa[ano] = y;
		ch[x][fson ^ 1] = y, ch[y][fson] = ano, fa[x] = z, fa[y] = x;
		upd(y), upd(x);
	}
	int f[N], ftot;
	void Splay(int x) {
		int fx = x; f[++ftot] = fx;
		while(get(fx)) f[++ftot] = fx = fa[fx];
		while(ftot) pushdown(f[ftot--]);
		while(get(x)) {
			int y = fa[x], z = fa[y];
			if(get(y)) rotate((ch[y][1] == x ^ ch[z][1] == y) ? x : y);
			rotate(x);
		}
	}
	void access(int x) {
		for(int y = 0; x; y = x, x = fa[x]) Splay(x), ch[x][1] = y, upd(x); 
	}
	void makeroot(int x) {
		access(x), Splay(x), flip(x);
	}
	void split(int x, int y) {
		makeroot(x), access(y), Splay(y);
	}
	int findrt(int x) {
		access(x), Splay(x);
		while(ch[x][0]) x = ch[x][0];
		Splay(x);
		return x;
	}
	void link(int x, int y) {
		makeroot(x);
		if(findrt(y) != x) fa[x] = y;
	}
	void cut(int x, int y) {
		makeroot(x);
		if(findrt(y) == x && fa[y] == x && !ch[y][0]) ch[x][1] = fa[y] = 0, upd(x);
	}
} lct;
int n, m, a[N];
int main() {
	n = read(), m = read();
	L(i, 1, n) {
		a[i] = read(), lct.s[i] = lct.mx[i] = i, lct.upd(i);
		if(a[i] + i > n) lct.upd(i), lct.link(i, n + 1);
		else lct.link(i, a[i] + i);
	}
	while(m--) {
		int opt = read(), x = read(), v;
		if(opt == 1) {
			lct.split(x, n + 1);
			printf("%d %d\n", lct.mx[n + 1], lct.siz[n + 1] - 1);
		}
		else {
			v = read(), lct.split(x, x);
			if(a[x] + x > n) lct.cut(x, n + 1);
			else lct.cut(x, a[x] + x);
			a[x] = v;
			if(a[x] + x > n) lct.link(x, n + 1);
			else lct.link(x, a[x] + x);
		}
	}
	return 0;
}
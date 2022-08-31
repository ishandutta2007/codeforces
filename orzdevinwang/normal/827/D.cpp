#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define putsl puts("")
using namespace std;
const int N = 4e5 + 7;
const int inf = 1e9 + 7;
template<typename T> inline void read(T &x) {
	x = 0; T f = 1; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
	x *= f;
}
template<typename T> inline void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}
int n, m;
struct LCT {
	int ch[N][2], fa[N], flag[N], s[N], mx[N], val[N], vfl[N];
	void upd(int x) {
		mx[x] = max(s[x], max(mx[ch[x][0]], mx[ch[x][1]]));
	}
	void flip(int x) {
		if(x) flag[x] ^= 1, swap(ch[x][0], ch[x][1]);
	}
	void ad(int x, int w) {
		vfl[x] = min(vfl[x], w), val[x] = min(val[x], w);
	}
	void pushdown(int x) {
		if(flag[x]) flip(ch[x][0]), flip(ch[x][1]), flag[x] ^= 1;
		if(vfl[x] < inf) ad(ch[x][0], vfl[x]), ad(ch[x][1], vfl[x]), vfl[x] = inf;
	}
	bool get(int x) {
		return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
	}
	void rotate(int x) {
		int y = fa[x], z = fa[y], fson = (ch[y][1] == x), ano = ch[x][fson ^ 1];
		if(get(y)) ch[z][ch[z][1] == y] = x;
		if(ano) fa[ano] = y;
		ch[x][fson ^ 1] = y, ch[y][fson] = ano, fa[y] = x, fa[x] = z;
		upd(y), upd(x);
	}
	int f[N], ftot;
	void Splay(int x) {
		int fx = x; f[++ftot] = x;
		while(get(fx)) fx = f[++ftot] = fa[fx];
		while(ftot) pushdown(f[ftot--]);
		while(get(x)) {
			int y = fa[x], z = fa[y];
			if(get(y)) rotate((ch[y][1] == x) ^ (ch[z][1] == y) ? x : y);
			rotate(x);
		}
	}
	void access(int x) {
		for(int y = 0; x; y = x, x = fa[x]) Splay(x), ch[x][1] = y, upd(x);
	}
	void makeroot(int x) {
		access(x), Splay(x), flip(x);
	}
	int findrt(int x) {
		access(x), Splay(x);
		while(ch[x][0]) pushdown(x), x = ch[x][0];
		Splay(x); return x;
	}
	void split(int x, int y) {
		makeroot(x), access(y), Splay(y);
	}
	void link(int x, int y) {
		makeroot(x);
		if(findrt(y) != x) fa[x] = y;
	}
	void cut(int x, int y) {
		makeroot(x);
		if(findrt(y) == x && fa[y] == x && !ch[y][0]) fa[y] = ch[x][1] = 0, upd(x);
	}
} lct;
int tot, ans[N];
struct edge {
	int id, from, to, val, sid;
} e[N];
int main() {
	read(n), read(m), tot = n;
	L(i, 1, m) e[i].id = i, read(e[i].from), read(e[i].to), read(e[i].val);
	sort(e + 1, e + m + 1, [&](edge aa, edge bb) { return aa.val < bb.val; });
	L(i, 1, 2 * n - 1) lct.val[i] = lct.vfl[i] = inf;
	L(i, 1, m) {
		if(lct.findrt(e[i].from) != lct.findrt(e[i].to)) 
			e[i].sid = ++tot, lct.s[tot] = e[i].val, lct.link(e[i].from, tot), lct.link(tot, e[i].to);
		else lct.split(e[i].from, e[i].to), ans[e[i].id] = lct.mx[e[i].to], lct.ad(e[i].to, e[i].val);
	}
	L(i, 1, m) if(e[i].sid) lct.split(e[i].sid, e[i].sid), ans[e[i].id] = lct.val[e[i].sid];
	L(i, 1, m) printf("%d ", ans[i] == inf ? -1 : ans[i] - 1); 
	putsl;
	return 0;
}
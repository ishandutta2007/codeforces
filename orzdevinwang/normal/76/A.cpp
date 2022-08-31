#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
struct edge {
	int fr, to, vala, valb;
} e[M];
multiset<int> st;
int n, m, S1, S2, fa[N], ch[N][2], flag[N], s[N], val[N], fr[N], to[N], total;
ll Ans = 3e18;
bool get(int x) {
	return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}
void filp(int x) {
	if(x) flag[x] ^= 1, swap(ch[x][0], ch[x][1]);
}
void pushdown(int x) {
	if(flag[x]) flag[x] ^= 1, filp(ch[x][0]), filp(ch[x][1]);
}
void upd(int x) {
	s[x] = x;
	if(val[s[ch[x][0]]] > val[s[x]]) s[x] = s[ch[x][0]];
	if(val[s[ch[x][1]]] > val[s[x]]) s[x] = s[ch[x][1]];
}
void rotate(int x) {
	int y = fa[x], z = fa[y], fson = (ch[y][1] == x), ano = ch[x][1^fson];
	if(get(y)) ch[z][ch[z][1] == y] = x;
	if(ano) fa[ano] = y;
	fa[y] = x, fa[x] = z, ch[x][1^fson] = y, ch[y][fson] = ano;
	upd(y), upd(x);
}
int f[N], tot, fx;
void Splay(int x) {
	tot = 1, f[tot] = fx = x;
	while(get(fx)) ++tot, f[tot] = fx = fa[fx];
	while(tot) pushdown(f[tot]), --tot;
	while(get(x)) {
		int y = fa[x], z = fa[y];
		if(get(y)) rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
		rotate(x);
	}
	upd(x);
}
void access(int x) {
	int y = 0;
	while(x) {
		Splay(x);
		ch[x][1] = y;
		upd(x);
		y = x;
		x = fa[x];
	}
}
void makeroot(int x) {
	access(x), Splay(x), filp(x);
}
int findroot(int x) {
	access(x), Splay(x);
	while(ch[x][0]) pushdown(x), x = ch[x][0];
	Splay(x);
	return x;
}
void split(int x, int y) {
	makeroot(x), access(y), Splay(y);
}
void link(int x, int y, int value) {
	makeroot(x);
	if(findroot(y) != x) ++total, fr[total] = x,  to[total] = y, fa[x] = total, fa[total] = y, val[total] = value, s[total] = total;
}
void ct(int x, int y) {
	makeroot(x);
	if(findroot(y) == x && fa[y] == x && !ch[y][0]) fa[y] = ch[x][0] = 0, upd(x);
}
void cut(int x) {
	ct(fr[x], x), ct(x, to[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> S1 >> S2, total = n;
	L(i, 1, m) cin >> e[i].fr >> e[i].to >> e[i].vala >> e[i].valb;
	sort(e + 1, e + m + 1, [&] (edge aa, edge bb) {
		return aa.vala < bb.vala;
	});
	L(i, 1, m) {
		if(findroot(e[i].fr) != findroot(e[i].to)) st.insert(e[i].valb), link(e[i].fr, e[i].to, e[i].valb);
		else {
			split(e[i].fr, e[i].to);
			if(val[s[e[i].to]] > e[i].valb) st.erase(st.find(val[s[e[i].to]])), st.insert(e[i].valb), cut(s[e[i].to]), link(e[i].fr, e[i].to, e[i].valb); 
		}
		if(sz(st) == n - 1) Ans = min(Ans, (ll) S2 * (* st.rbegin()) + (ll) e[i].vala * S1);
	}
	cout << (Ans == 3e18 ? -1 : Ans) << "\n";
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
const int N = 1e5 + 7;
int ch[N][2], siz[N];
ll w[N], fi[N], ad[N], key[N], lef[N], rig[N];
mt19937_64 orz(time(0) ^ clock());
void Add (int x, ll l, ll h) {
	w[x] += l + h * siz[ch[x][0]];
	fi[x] += l, ad[x] += h;
	lef[x] += l, rig[x] += l + h * (siz[x] - 1);
}
void Push (int x) {
	if(fi[x] || ad[x]) {
		if(ch[x][0]) Add (ch[x][0], fi[x], ad[x]);
		if(ch[x][1]) Add (ch[x][1], fi[x] + ad[x] * (siz[ch[x][0]] + 1), ad[x]);
		fi[x] = ad[x] = 0;
	}
}
void upd (int x) {
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	lef[x] = ch[x][0] ? lef[ch[x][0]] : w[x];
	rig[x] = ch[x][1] ? rig[ch[x][1]] : w[x];
}
void split (int now, int t, int &x, int &y) {
	if(!now) return x = y = 0, void ();
	Push (now);
	if(t <= siz[ch[now][0]]) y = now, split (ch[y][0], t, x, ch[y][0]), upd (y);
	else x = now, split (ch[x][1], t - siz[ch[x][0]] - 1, ch[x][1], y), upd (x);
}
int merge (int x, int y) {
	if(!x || !y) return x + y;
	if(key[x] < key[y]) return Push (x), ch[x][1] = merge (ch[x][1], y), upd (x), x;
	else return Push(y), ch[y][0] = merge (x, ch[y][0]), upd (y), y;
}
int findp(int x, int now, ll lst, ll A) {
	if(!x) return now;
	Push (x);
	ll cst = ch[x][0] ? rig[ch[x][0]] : lst;
	if(w[x] >= cst + (now + siz[ch[x][0]]) * A) return findp(ch[x][1], now + siz[ch[x][0]] + 1, w[x], A);
	else return findp(ch[x][0], now, lst, A);
} 
ll ns;
void DFS (int x) {
	Push (x);
	ns = max(ns, w[x]);
	if(ch[x][0]) DFS (ch[x][0]);
	if(ch[x][1]) DFS (ch[x][1]);
}
int n, a[N], rt = 1;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n + 1) key[i] = orz (), siz[i] = 1;
	L(i, 1, n) {
		int cs = findp(rt, 0, -1e18, a[i]), sx, sy;
		split (rt, cs, sx, sy);
		w[i + 1] = lef[i + 1] = rig[i + 1] = rig[sx] + (ll) cs * a[i];
		Add (sy, (ll) a[i] * (cs + 1), a[i]);
		rt = merge (merge (sx, i + 1), sy);
	}
	DFS (rt);
	cout << ns << '\n';
	return 0;
}
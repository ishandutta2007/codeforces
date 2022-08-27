#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7, inv6 = (mod + 1) / 6, W = 2;
int n, m, ch[N][2], mx[N], w[N], tag[N], fa[N], s[N], flag[N], fr[N], to[N], tot;
bool get(int x) {
	return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}
void filp(int x) {
	if(x) flag[x] ^= 1, swap(ch[x][0], ch[x][1]);
}
void upd(int x) {
	s[x] = x <= n ? 1919810 : x;
	if(ch[x][0] && s[x] > s[ch[x][0]]) s[x] = s[ch[x][0]];
	if(ch[x][1] && s[x] > s[ch[x][1]]) s[x] = s[ch[x][1]];
	mx[x] = max(w[x], max(mx[ch[x][0]], mx[ch[x][1]]));
}
void AD (int x, int r) {
	tag[x] += r, mx[x] += r, w[x] += r;
}
void pushdown(int x) {
	if(flag[x]) {
		if(ch[x][0]) filp(ch[x][0]);
		if(ch[x][1]) filp(ch[x][1]);
		flag[x] ^= 1;	
	}
	
	if(tag[x]) {
		if(ch[x][0]) AD(ch[x][0], tag[x]);
		if(ch[x][1]) AD(ch[x][1], tag[x]);
		tag[x] = 0;
	}
}
void rotate(int x) {
	int y = fa[x], z = fa[y], fson = (ch[y][1] == x), ano = ch[x][1^fson];
	if(get(y)) ch[z][ch[z][1] == y] = x;
	if(ano) fa[ano] = y;
	fa[y] = x, fa[x] = z, ch[x][1^fson] = y, ch[y][fson] = ano;
	upd(y), upd(x);
}
int fx, f[N], total;
void Splay(int x) {
	total = 1, fx = f[total] = x;
	while(get(fx)) ++total, fx = f[total] = fa[fx];
	while(total) pushdown(f[total]), --total;
	while(get(x)) {
		int y = fa[x], z = fa[y];
		if(get(y)) rotate(((ch[y][0] == x) ^ (ch[z][0] == y)) ? x : y);
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
void link(int x, int y) {
	makeroot(x);
	if(findroot(y) != x) fa[x] = y;
} 
void cut(int x, int y) {
	makeroot(x);
	if(findroot(y) == x && fa[y] == x && ! ch[y][0]) ch[x][1] = fa[y] = 0, upd(x);
}

int eu[N], ev[N];
bool ok[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 0, n) w[i] = -1e9;
	L(i, 1, m) 
		cin >> eu[i] >> ev[i];
	int cr = 1;
	ll ns = 0;
	L(i, 1, m) {
		if(i > 1) {
			int g = i - 1;
			if(ok[g]) cut (eu[g], g + n), cut (ev[g], g + n);
			else split (eu[g], ev[g]), AD(ev[g], -1);
		}
		while (cr <= m) {
			if(findroot (eu[cr]) == findroot (ev[cr])) {
				split (eu[cr], ev[cr]);
//				cout << "mx = " << mx[ev[cr]] << '\n';
				if(mx[ev[cr]] >= 1) break;
				int t = s[ev[cr]] - n;
//				cout << "t = " << t << '\n';
				cut (eu[t], t + n), cut (eu[t], t + n), ok[t] = false;
				link (eu[cr], cr + n), link (ev[cr], cr + n);
				split (eu[t], ev[t]);
				AD(ev[t], 1);
			}
			else link (eu[cr], cr + n), link (ev[cr], cr + n);
			ok[cr] = true, cr += 1;
		}
		ns += cr - i;
//		cout << i << " : " << cr << '\n';
	}
	cout << ns << '\n';
	return 0;
}
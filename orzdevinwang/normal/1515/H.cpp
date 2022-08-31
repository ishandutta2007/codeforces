#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, M = N * 80, rk = 20, mx = (1 << rk) - 1;

int n, q, a[N];
int ch[M][2], to0[M], to1[M], only[M], v[M], tot;

int Nw() { 
	++tot, only[tot] = mx, to0[tot] = 0, to1[tot] = mx, v[tot] = 0; 
	return tot; 
}

void upd(int x, int l) {
	only[x] = (only[ch[x][0]] & only[ch[x][1]]), v[x] = v[ch[x][0]] + v[ch[x][1]];
	if(ch[x][0] && ch[x][1]) only[x] ^= (only[x] & (1 << l));
}

void mk(int x, int t0, int t1) { 
	if(x) 
		to0[x] = (t0 & (to0[x] ^ mx)) | (t1 & to0[x]), 
		to1[x] = (t0 & (to1[x] ^ mx)) | (t1 & to1[x]);
}

void push(int x, int l) {
	int c0 = ch[x][0], c1 = ch[x][1];
	ch[x][0] = ch[x][1] = 0;
	if(c0) ch[x][to0[x] >> l & 1] = c0;
	if(c1) ch[x][to1[x] >> l & 1] = c1; 
	to0[x] = (to0[x] | (1 << l)) ^ (1 << l), to1[x] = to1[x] | (1 << l);
	mk(ch[x][0], to0[x], to1[x]), mk(ch[x][1], to0[x], to1[x]), to0[x] = 0, to1[x] = mx;
}

void split(int now, int &x, int &y, int k, int l = rk - 1) { 
	if(!now || l < 0) return x = now, y = 0, void();
	push(now, l);
	if(k >> l & 1) x = now, y = Nw(), split(ch[x][1], ch[x][1], ch[y][1], k, l - 1);
	else y = now, x = Nw(), split(ch[y][0], ch[x][0], ch[y][0], k, l - 1);
	upd(x, l), upd(y, l);
}

void ins (int &rt, int k, int l = rk - 1) {
	if(!rt) rt = Nw();
	if(l < 0) return v[rt] = 1, void();
	ins(ch[rt][k >> l & 1], k, l - 1), upd(rt, l);
}

int merge(int x, int y, int l = rk - 1) {
	if(!x || !y) return x | y;
	if(l == -1) return x;
	push(x, l), push(y, l);
	ch[x][0] = merge(ch[x][0], ch[y][0], l - 1);
	ch[x][1] = merge(ch[x][1], ch[y][1], l - 1);
	upd(x, l);
	return x;
}

void AND(int now, int k, int l = rk - 1) {
	if(!now || l < 0) return;
	if((only[now] & (mx ^ k)) == (mx ^ k)) return to0[now] &= k, to1[now] &= k, void();
	push(now, l);
	if(! (k >> l & 1)) ch[now][0] = merge(ch[now][0], ch[now][1], l - 1), ch[now][1] = 0;
	AND(ch[now][0], k, l - 1), AND(ch[now][1], k, l - 1), upd(now, l);
}
void OR(int now, int k, int l = rk - 1) {
	if(!now || l < 0) return;
	if((only[now] & k) == k) return to0[now] |= k, to1[now] |= k, void();
	push(now, l);
	if(k >> l & 1) ch[now][1] = merge(ch[now][0], ch[now][1], l - 1), ch[now][0] = 0;
	OR(ch[now][0], k, l - 1), OR(ch[now][1], k, l - 1), upd(now, l);
}
void dfs(int now, int l = rk - 1) {
	if(!now || l < 0) return;
	push(now, l), dfs(ch[now][0], l - 1), dfs(ch[now][1], l - 1), upd(now, l);
}

int rt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	only[0] = mx, cin >> n >> q;
	L(i, 1, n) cin >> a[i], ins(rt, a[i]);
	while(q--) {
		int op, l, r, x, ox, now, oy;
		cin >> op >> l >> r;
		
		if(!l) ox = 0, oy = rt;
		else split(rt, ox, oy, l - 1); //, cout << v[ox] << " and " << v[oy] << "\n";
		split(oy, now, oy, r);
		
//		cout << v[ox] << " " << v[now] << " " << v[oy] << "\n";

		if(op == 4) 
			cout << v[now] << "\n";
		else {
			cin >> x;
			if(op == 1) AND(now, x); //, dfs(now);
			if(op == 2) OR(now, x);
			if(op == 3) to0[now] ^= x, to1[now] ^= x;
		}
//		cout << "v = " << v[now] << "\n";
		rt = merge(merge(ox, now), oy);
//		cout << " rtv = " << v[rt] << "\n";
	} 
	return 0;
}
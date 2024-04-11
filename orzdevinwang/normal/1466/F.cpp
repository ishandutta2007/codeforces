#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int qpow(int x, int y) {
	int res = 1;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
} 
int n, m, cnt;
int d[N];
struct vec {
	int cnt;
	int f[3];
	void fix() {
		if(cnt == 2 && f[0] > f[1]) swap(f[0], f[1]);
	}
} g[N];
int sum = 0;
int f[N];
vec operator + (vec aa, vec bb) { // aa.0 = bb.0
	if(bb.cnt != 1) aa.f[0] = bb.f[1], aa.cnt = 2;
	else aa.f[0] = aa.f[1], aa.f[1] = 0, aa.cnt = 1;
	if(aa.cnt == 2 && aa.f[0] == aa.f[1]) aa.cnt = aa.f[0] = aa.f[1] = 0;
	if(aa.f[0] == 0) aa.cnt = 0;
	return aa;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]);  }
void insb(int x) {
	if(!g[x].cnt) return;
	int t = find(g[x].f[0]);
	if(!d[t]) d[t] = x, ++cnt;
}
void insa(int x) {
	if(!g[x].cnt) return;
	int t = find(g[x].f[0]);
	if(find(g[x].f[0]) == find(g[x].f[1])) return;
	if(!d[t]) {
		d[t] = x, ++cnt;
		if(g[x].f[1]) f[t] = g[x].f[1];
		return;
	} 
	else g[x] = g[x] + g[d[t]], insb(x);
}
int sav[N], tot;
void Main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) f[i] = i;
	L(i, 1, n) {
		scanf("%d", &g[i].cnt);
		L(j, 0, g[i].cnt - 1) scanf("%d", &g[i].f[j]);
		if(g[i].cnt == 1) insb(i); else insa(i);
	}
	printf("%d %d\n", qpow(2, cnt), cnt);
	L(i, 1, m) if(d[i]) sav[++tot] = d[i];
	sort(sav + 1, sav + tot + 1);
	L(i, 1, tot) printf("%d ", sav[i]);
	puts("");
}
int main() {
	Main();
	return 0;
}
/*
2 2
2 1 2
2 1 2
*/
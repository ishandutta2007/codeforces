// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 300007;
struct STtable {
	int n, st[20][N];
	void build(int *f) {
		L(i, 1, n) st[0][i] = f[i];
		L(i, 1, 18) L(j, 1, n - (1 << i) + 1) st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}
	int query(int l, int r) {
		int p = log2(r - l + 1);
		return max(st[p][l], st[p][r - (1 << p) + 1]);
	}
} F, G;
int n, a[N], f[N], g[N];
int get(int l, int r) {
	if(l == r) return a[l];
	int mid = (l + r) / 2;
	if((r - l + 1) & 1) return max(min(a[mid], a[mid - 1]), min(a[mid], a[mid + 1]));
	else return max(a[mid], a[mid + 1]);
}
int main() {
	scanf("%d", &n), F.n = G.n = n;
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 2, n - 1) f[i] = max(min(a[i], a[i - 1]), min(a[i], a[i + 1]));
	L(i, 1, n - 1) g[i] = max(a[i], a[i + 1]);
	F.build(f), G.build(g);
	L(i, 1, n - 1) {
		int res = 0;
		if((n - i + 1) & 1) printf("%d ", F.query((n - i) / 2 + 1, (i + n) / 2));
		else printf("%d ", G.query((n - i) / 2 + 1, (i + n) / 2));
	}
	int res = 0;
	L(i, 1, n) res = max(res, a[i]);
	printf("%d ", res);
	puts("");
	return 0;
}
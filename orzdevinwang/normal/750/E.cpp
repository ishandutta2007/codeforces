#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int inf = 1e9;
int maxn = 5;
struct Matrix {
	int f[6][6];
	void Print() { L(i, 1, maxn) L(j, 1, maxn) printf("%3d%s", f[i][j], j == maxn ? "\n" : " "); }
	void clear() { L(i, 1, maxn) L(j, 1, maxn) f[i][j] = inf; }
	void start() { clear(); L(i, 1, maxn) f[i][i] = 0; }
} ;
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res; res.clear();
	L(i, 1, maxn) L(j, 1, maxn) L(k, 1, maxn) res.f[i][j] = min(res.f[i][j], aa.f[i][k] + bb.f[k][j]);
	return res;
}
int mat[10]; char s[N];
Matrix f[10], seg[N << 2];
Matrix mAKe(int x) { // m[George1123]e
	Matrix G; G.clear();
	L(i, 1, maxn) G.f[i][i] = 1, mat[i] = i;
	if(x == 0) mat[2] = 3;
	if(x == 1) mat[3] = 4;
	if(x == 2) mat[1] = 2;
	if(x == 6) mat[4] = mat[5] = 0;
	if(x == 7) mat[4] = 5;
	L(i, 1, maxn) if(mat[i]) G.f[i][mat[i]] = 0;
	return G;
}
void build(int id, int L, int R) {
	if(L == R) return seg[id] = f[s[L] - '0'], void();
	int mid = (L + R) / 2;
	build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R);
	seg[id] = seg[id << 1] * seg[id << 1 | 1];
}
Matrix query(int id, int L, int R, int l, int r) {
	if(l == L && R == r) return seg[id];
	int mid = (L + R) / 2;
	if(r <= mid) return query(id << 1, L, mid, l, r);
	if(l > mid) return query(id << 1 | 1, mid + 1, R, l, r);
	return query(id << 1, L, mid, l, mid) * query(id << 1 | 1, mid + 1, R, mid + 1, r);
}
int n, m;
int main() {
	L(i, 0, 9) f[i] = mAKe(i);
	scanf("%d%d%s", &n, &m, s + 1);
	build(1, 1, n);
	while(m--) {
		int l, r; scanf("%d%d", &l, &r);
		int Ans = query(1, 1, n, l, r).f[1][5];
		if(Ans > 1e8) puts("-1");
		else printf("%d\n", Ans);
	}
	return 0;
}
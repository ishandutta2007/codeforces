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
const int N = 2e5 + 7;
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
int maxn = 4;
struct Matrix {
	int f[6][6];
	void Print() { L(i, 1, maxn) L(j, 1, maxn) printf("%3d%s", f[i][j], j == maxn ? "\n" : " "); }
	void clear() { L(i, 1, maxn) L(j, 1, maxn) f[i][j] = -inf; }
	void start() { clear(); L(i, 1, maxn) f[i][i] = 0; }
} ;
Matrix operator * (Matrix aa, Matrix bb) {
	Matrix res; res.clear();
	L(i, 1, maxn) L(j, 1, maxn) L(k, 1, maxn) res.f[i][j] = max(res.f[i][j], aa.f[i][k] + bb.f[k][j]);
	return res;
}
char s[N];
Matrix f[2], seg[N << 2];
int dep = 0;
void build(int id, int L, int R) {
	if(L == R) return seg[id] = f[s[L] == ')'], void();
	int mid = (L + R) >> 1;
	build(id << 1, L, mid), build(id << 1 | 1, mid + 1, R);
	seg[id] = seg[id << 1] * seg[id << 1 | 1];
}
void change(int id, int L, int R, int wz) {
	if(L == R) return seg[id] = f[s[wz] == ')'], void();
	int mid = (L + R) >> 1;
	if(wz <= mid) change(id << 1, L, mid, wz);
	else change(id << 1 | 1, mid + 1, R, wz);
	seg[id] = seg[id << 1] * seg[id << 1 | 1];
}
int n, m;
void printans() {
	print(max(max(seg[1].f[1][3], seg[1].f[2][3]), max(seg[1].f[3][3], seg[1].f[4][3]))), putsl;
}
int main() {
	f[0].clear(), f[1].clear();
	
	// f[0] : +1
	f[0].f[1][1] = -1,   f[0].f[1][2] = 1,    f[0].f[1][3] = 0,    f[0].f[1][4] = -inf;
	f[0].f[2][1] = -inf, f[0].f[2][2] = 1,    f[0].f[2][3] = 1,    f[0].f[2][4] = -inf;
	f[0].f[3][1] = -inf, f[0].f[3][2] = -inf, f[0].f[3][3] = 0,    f[0].f[3][4] = -inf;
	f[0].f[4][1] = 0,    f[0].f[4][2] = 0,    f[0].f[4][3] = 0,    f[0].f[4][4] = 0;
	
	// f[1] : -1
	f[1].f[1][1] = 1,    f[1].f[1][2] = 1,    f[1].f[1][3] = 1,    f[1].f[1][4] = -inf;
	f[1].f[2][1] = -inf, f[1].f[2][2] = -1,   f[1].f[2][3] = 0,    f[1].f[2][4] = -inf;
	f[1].f[3][1] = -inf, f[1].f[3][2] = -inf, f[1].f[3][3] = 0,    f[1].f[3][4] = -inf;
	f[1].f[4][1] = 0,    f[1].f[4][2] = 0,    f[1].f[4][3] = 0,    f[1].f[4][4] = 0;
	
	read(n), read(m), --n, n <<= 1, scanf("%s", s + 1);
	build(1, 1, n);
	printans();
	while(m--) {
		int x, y;
		read(x), read(y), swap(s[x], s[y]), change(1, 1, n, x), change(1, 1, n, y);
		printans();
	}
	return 0;
}
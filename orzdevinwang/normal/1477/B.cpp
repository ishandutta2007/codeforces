#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
int n, m;
int sum[N << 2], lazy[N << 2];
void ADD(int id, int L, int R, int val) { 
	lazy[id] = val, sum[id] = val * (R - L + 1);
} 
void pushdown(int id, int L, int R) {
	if(lazy[id] == -1) return;
	int mid = (L + R) / 2;
	ADD(id << 1, L, mid, lazy[id]), ADD(id << 1 | 1, mid + 1, R, lazy[id]), lazy[id] = -1;
}
void add(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ADD(id, L, R, val), void();
	pushdown(id, L, R);
	int mid = (L + R) / 2;
	if(l <= mid) add(id << 1, L, mid, l, r, val);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, val);
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
int query(int id, int L, int R, int l, int r) {
	if(l <= L && R <= r) return sum[id];
	pushdown(id, L, R);
	int mid = (L + R) / 2, res = 0;
	if(l <= mid) res += query(id << 1, L, mid, l, r);
	if(r > mid) res += query(id << 1 | 1, mid + 1, R, l, r);
	return res;
}
char s[N], p[N];
int l[N], r[N];
void Main() {
	n = read(), m = read();
	L(i, 1, n * 4) lazy[i] = -1, sum[i] = 0;
	scanf("%s", p + 1);
	scanf("%s", s + 1);
	L(i, 1, n) add(1, 1, n, i, i, s[i] - '0');
	L(i, 1, m) {
		l[i] = read();
		r[i] = read();
	}
	R(i, m, 1) {
		int cnt = query(1, 1, n, l[i], r[i]);
		if((r[i] - l[i] + 1) % 2 == 0 && (r[i] - l[i] + 1) / 2 == cnt) return puts("NO"), void(); 
		if(cnt <= (r[i] - l[i]) / 2) add(1, 1, n, l[i], r[i], 0);
		else add(1, 1, n, l[i], r[i], 1);
	}
	L(i, 1, n) if(p[i] - '0' != query(1, 1, n, i, i)) return puts("NO"), void();
	puts("YES");
}
int main() {
	int T = read();
	while(T--) Main(); 
	return 0;
}
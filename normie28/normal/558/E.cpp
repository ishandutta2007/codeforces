//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define FILE_IN "polygon.inp"
#define FILE_OUT "polygon.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define vi vector<int>
#define bi BigInt
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll;
const int maxN = 1e5 + 10;
int st[maxN<<2][26];
int lazy[maxN<<2][26];
int n, m;
char s[maxN];
 
void build(int nx=1, int l=0, int r=n-1) {
	if (l == r) {
		for (int k = 0; k < 26; ++k) st[nx][k] = s[r] == 'a' + k;
		return;
	}
	int mid = (l+r)/2;
	build(nx<<1, l, mid);
	build(nx<<1|1, mid+1, r);
	for (int k = 0; k < 26; ++k) st[nx][k] = st[nx<<1][k] + st[nx<<1|1][k];
}
 
void updNode(int k, int nx, int l, int r, int v) {
	st[nx][k] = v * (r - l + 1); 
	lazy[nx][k] = v;
}
 
void push(int k, int nx, int l, int r) {
	if (~lazy[nx][k]) {
		int mid = (l+r)/2;
		updNode(k, nx<<1, l, mid, lazy[nx][k]);
		updNode(k, nx<<1|1, mid+1, r, lazy[nx][k]);
		lazy[nx][k] = -1;
 	}
}
 
void upd(int k, int ll, int rr, int val, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return;
	if (ll <= l and r <= rr) {
		updNode(k, nx, l, r, val);
		return;
	}
	int mid = (l+r)/2;
	push(k, nx, l, r);
	upd(k, ll, rr, val, nx<<1, l, mid);
	upd(k, ll, rr, val, nx<<1|1, mid+1, r);
	st[nx][k] = st[nx<<1][k] + st[nx<<1|1][k];
}
 
int qry(int k, int ll, int rr, int nx=1, int l=0, int r=n-1) {
	if (rr < l or r < ll) return 0;
	if (ll <= l and r <= rr) return st[nx][k];
	int mid = (l+r)/2;
	push(k, nx, l, r);
	return qry(k, ll, rr, nx<<1, l, mid) + qry(k, ll, rr, nx<<1|1, mid+1, r);
}
 
int cnt[30];
int main() {
	scanf("%d %d\n%s", &n, &m, s);
	memset(lazy, -1, sizeof lazy);
	build();
	while (m--) {
		int l, r, p;
		scanf("%d %d %d", &l, &r, &p);
		l -= 1; r -= 1;
		for (int i = 0; i < 26; ++i) {
			cnt[i] = qry(i, l, r);
			upd(i, l, r, 0);
		}
		if (p == 0) {
			for (int t = 25; t >= 0; --t) {
				if (cnt[t] == 0) continue;
				upd(t, l, l + cnt[t] - 1, 1);
				l += cnt[t];
			}
		} else {
			for (int t = 0; t < 26; ++t) {
				if (cnt[t] == 0) continue;
				upd(t, l, l + cnt[t] - 1, 1);
				l += cnt[t];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (; t < 26; ++t) {
			if (qry(t, i, i) == 1) break;
		}
		putchar(t + 'a');
	}
}
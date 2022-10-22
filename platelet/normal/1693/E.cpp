#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;
using ll = long long;

const int N = 2e5 + 5, M = 1 << 18;

int read() {
	const int M = 1e6;
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
	static char buf[M], *p1, *p2;
	int c, r = 0;
	while((c = gc) < 48);
	while(c > 47) r = r * 10 + (c & 15), c = gc;
	return r;
}

int n, c[M], buc0[512], buc1[512];
ll a[N], b[N];
inline void add(int i) {
	for(; i < M; i += i & -i) c[i]++;
}
inline int qry(int i, int r = 0) {
	for(; i; i &= i - 1) r += c[i];
	return r;
}
inline int kth(int k, int r = 0) {
	for(int i = M >> 1; i; i >>= 1) if(c[r | i] < k) k -= c[r |= i];
	return r + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	rep(i, 1, n) {
		int x = read();
		a[i] = (ll)x << 32 | i, buc0[x & 511]++, buc1[x >> 9 & 511]++;
	}
	rep(i, 1, 511) buc0[i] += buc0[i - 1], buc1[i] += buc1[i - 1];
	per(i, n, 1) b[buc0[a[i] >> 32 & 511]--] = a[i];
	per(i, n, 1) a[buc1[b[i] >> 41]--] = b[i];
	ll ans = 0;
	int l = n, r = 1;
	a[0] = -1;
	for(int i = n, j = 1; j; i = j) {
		ll v = a[i] >> 32;
		if(!v) break;
		for(j = i; a[j] >> 32 == v; j--) {
			int idx = (unsigned)a[j];
			add(idx), l = min(l, idx), r = max(r, idx);
		}
		int ql = qry(l - 1), qr = qry(r); 
		r = kth(ql), l = kth(qr + 1), ans += qr - ql;
	}
	cout << ans;
}
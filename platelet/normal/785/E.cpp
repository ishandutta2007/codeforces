#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e5 + 5, MI = 1e6;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
void wrt(long long x) {
	static streambuf* out = cout.rdbuf();
	#define pc out -> sputc
	static char ch[20]; int sz = 0;
	if(!x) pc(48);
	else {
		while(x) ch[++sz] = x % 10, x /= 10;
		while(sz) pc(ch[sz--] + 48);
	} pc(10);
}
int n, q, sz, a[N], b[N]; long long ans;
void upd(int x, int v) {
	int id = x / sz, t = id * sz;
	if(id < n / sz) {
		while(b[t] ^ a[x]) t++;
		b[t] = a[x] = v;
		while(t > id * sz && b[t] < b[t-1]) swap(b[t], b[t-1]), t--;
		while(t < id * sz + sz - 1 && b[t] > b[t+1]) swap(b[t], b[t+1]), t++;
	} else a[x] = v;
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	n = read(), q = read(), sz = sqrt(n * log2(n));
	rep(i, 0, n - 1) a[i] = b[i] = i + 1;
	for(int l, r; q--; ) {
		l = read() - 1, r = read() - 1;
		if(l > r) swap(l, r);
		if(l == r) { wrt(ans); continue; }
		int al = a[l], ar = a[r];
		upd(l, ar), upd(r, al);
		while(l <= r) if(l % sz == 0 && l + sz - 1 <= r) {
			ans -= b + l + sz - upper_bound(b + l, b + l + sz, ar);
			ans += lower_bound(b + l, b + l + sz, ar) - b - l;
			ans -= lower_bound(b + l, b + l + sz, al) - b - l;
			ans += b + l + sz - upper_bound(b + l, b + l + sz, al);
			l += sz;
		} else ans += (a[l] < ar) + (a[l] > al) - (a[l] > ar) - (a[l] < al), l++;
		wrt(ans += al < ar ? -1 : 1);
	}
	return 0;
}
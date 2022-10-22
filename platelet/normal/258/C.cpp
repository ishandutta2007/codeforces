#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 5, MI = 1e6, P = 1e9 + 7;
typedef long long ll;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
int n, a[N]; ll ans;
int pos(int x) {
	return lower_bound(a + 1, a + n + 1, x) - a;
}
ll qpw(ll a, int n, ll r = 1) {
	for(; n; n >>= 1, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}
ll calc(ll a, int n) {
	ll x = (a - 1) * qpw(a, P - 2) % P;
	x = (qpw(x, n) + P - 1) * qpw(x + P - 1, P - 2) % P;
	return qpw(a, n - 1) * x % P;
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1);
	map <int, int> cnt;
	per(i, a[n], 1) {
		cnt.clear(); ll res = 1;
		for(int j = 1; j * j <= i; j++) if(i % j == 0) {
			cnt[pos(j)]++;
			if(j * j < i) cnt[pos(i / j)]++;
		}
		int lst = 0, tot = 0;
		for(map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
			if(it != cnt.begin()) res = res * qpw(tot, it->first - lst) % P;
			tot += it->second, lst = it->first;
		}
		ans = (ans + res * calc(tot, n - lst + 1)) % P;
	}
	return !(cout << ans);
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define mid ((l + r) / 2)
#define lch l, mid, o * 2
#define rch mid + 1, r, o * 2 + 1

using namespace std;
const int N = 1e5 + 5;
int T, n, a[N], nxt[N], ans[N];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		set <int> s;
		cin >> n;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) {
			nxt[i] = i < n ? i + 1 : 1;
			if(gcd(a[i], a[nxt[i]]) == 1) s.insert(i);
		}
		int p = 1, idx = 0;
		while(idx < n && !s.empty()) {
			int x = *s.rbegin() < p ? *s.begin() : *s.lower_bound(p);
			ans[++idx] = nxt[x], s.erase(x);
			if(s.count(nxt[x])) s.erase(nxt[x]);
			nxt[x] = nxt[nxt[x]];
			if(gcd(a[x], a[nxt[x]]) == 1) s.insert(x);
			p = nxt[x];
		}
		printf("%d ", idx);
		rep(i, 1, idx) printf("%d ", ans[i]);
		puts("");
	}	
	return 0;
}
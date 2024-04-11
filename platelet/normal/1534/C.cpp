#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 4e5 + 5, P = 1e9 + 7;

int n, p[N], q[N], fa[N];

int read() { int x; scanf("%d", &x); return x; }

int find(int x) { return x ^ fa[x] ? fa[x] = find(fa[x]) : x; }
void solve() {
	scanf("%d", &n);
	rep(i, 1, n) q[read()] = i, fa[i] = i;
	int as = 1;
	rep(i, 1, n) {
		p[i] = q[read()];
		int u = find(i), v = find(p[i]);
		if(u ^ v) fa[u] = v;
		else as = as * 2 % P;
	}
	printf("%d\n", as);
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	int T; for(cin >> T; T--;)
	solve();
	return 0;
}
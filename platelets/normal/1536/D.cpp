#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;

int T, n, b[N], g[N], c[N];
void add(int i) {
	for(; i <= n; i += i & -i) c[i]++;
}
int qry(int i, int r = 0) {
	for(; i; i &= i - 1) r += c[i];
	return r;
}
int solve() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &b[i]), g[i] = b[i], c[i] = 0;
	sort(g + 1, g + n + 1);
	rep(i, 1, n) {
		add(b[i] = lower_bound(g + 1, g + n + 1, b[i]) - g);
		if(i == 1) continue;
		int x = b[i - 1], y = b[i];
		if(x > y) swap(x, y);
		if(x < y && qry(y - 1) - qry(x)) return 0;
	}
	return 1;
}
int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--; puts(solve() ? "YES" : "NO"));
	return 0;
}
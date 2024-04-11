#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 4e5 + 5;

int n, m, a[N];

void solve() {
	scanf("%d", &n), a[n + 1] = 0;
	ll su = 0;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 0, n) su += abs(a[i] - a[i + 1]);
	rep(i, 1, n) su -= max(a[i] - max(a[i - 1], a[i + 1]), 0);
	printf("%lld\n", su);
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	int T; for(cin >> T; T--;)
	solve();
	return 0;
}
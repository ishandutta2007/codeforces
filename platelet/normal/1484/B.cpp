#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1e5 + 5;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int T, n, a[N];
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		int ma = 0;
		rep(i, 1, n) scanf("%d", &a[i]), ma = max(ma, a[i]);
		if(n <= 2) { puts("0"); continue; }
		per(i, n, 2) a[i] -= a[i - 1];
		int ans = 0;
		rep(i, 3, n) ans = gcd(ans, abs(a[i] - a[2]));
		if(!ans) puts("0");
		else if(ma < ans) printf("%d %lld\n", ans, (0ll + a[2] + ans) % ans);
		else puts("-1");
	}
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1e5 + 5;
int T, n, c[N];
typedef long long ll;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		ll su = 0, ans = 1e18;
		int mi[2] = { 1000000000, 1000000000 };
		rep(i, 1, n) {
			scanf("%d", &c[i]), su += c[i];
			mi[i & 1] = min(mi[i & 1], c[i]);
			if(i > 1) ans = min(ans, su + (ll)mi[1] * (n - (i + 1) / 2) + (ll)mi[0] * (n - i / 2));
		}
		printf("%lld\n", ans); 	
	}
	return 0;
}
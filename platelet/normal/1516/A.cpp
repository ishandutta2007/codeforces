#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 105;
int T, n, K, a[N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		cin >> n >> K;
		rep(i, 1, n) scanf("%d", &a[i]);
		For(i, 1, n) {
			int d = min(a[i], K);
			a[i] -= d, K -= d, a[n] += d;
		}
		rep(i, 1, n) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}
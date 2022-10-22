#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
int T, n, k1, k2, w, b;
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d%d%d%d", &n, &k1, &k2, &w, &b);
		if(k1 > k2) swap(k1, k2);
		puts(k1 + (k2 - k1) / 2 >= w && n - k2 + (k2 - k1) / 2 >= b ? "YES" : "NO");
	}
	return 0;
}
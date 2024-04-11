#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

const int N = 1e6 + 5;
int T, n, A[N], tp, stk[N], vis[N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n), tp = 0;
		rep(i, 1, n) scanf("%d", &A[i]), vis[i] = 0;
		int i = 1;
		for(; !vis[i]; i -= A[i]) vis[stk[++tp] = i] = 1;
		int pos = find(stk + 1, stk + tp + 1, i) - stk;
		printf("%d\n", tp - pos + 1);
		rep(i, pos, tp) printf("%d ", stk[i]);
		puts("");
	}
	return 0;
}
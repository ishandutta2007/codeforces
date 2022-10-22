#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;

const int N = 105;
int T, n, x, a[N];
int solve() {
	scanf("%d%d", &n, &x);
	rep(i, 1, n) scanf("%d", &a[i]);
	int su = 0;
	rep(i, 1, n) {
		su += a[i];
		if(su == x) {
			if(i < n) swap(a[i], a[i + 1]);
			return i < n;
		}
	}
	return 1;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		if(solve()) {
			puts("YES");
			rep(i, 1, n) printf("%d ", a[i]);
			puts("");
		} else puts("NO");
	}
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b)

using namespace std;
int T, n, x, a[55], b[55];
int main() {
	#ifdef local
//		freopen("1.in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &x);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		int f = 1;
		rep(i, 1, n) if(a[i] + b[n-i+1] > x) f = 0;
		puts(f ? "Yes" : "No");
	}
	return 0;
}
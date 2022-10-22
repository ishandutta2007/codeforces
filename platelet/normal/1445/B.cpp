#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b)

using namespace std;
int T, a, b, c, d;
int main() {
	#ifdef local
//		freopen("1.in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", max(a + b, c + d));
	}
	return 0;
}
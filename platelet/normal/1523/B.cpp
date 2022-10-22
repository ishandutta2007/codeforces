#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int T, n;

int main() {
#ifdef local
	// freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		cout << n * 3 << endl;
		auto solve = [](int x, int y) {
			printf("1 %d %d\n", x, y);
			printf("2 %d %d\n", x, y);
			printf("1 %d %d\n", x, y);
			printf("1 %d %d\n", x, y);
			printf("2 %d %d\n", x, y);
			printf("1 %d %d\n", x, y);
		};
		rep(i, 1, n / 2) solve(i * 2 - 1, i * 2);
		while(n--) scanf("%*d");
	}
}
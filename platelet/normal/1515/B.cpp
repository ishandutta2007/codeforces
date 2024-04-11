#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;

int T, n;
int chk(int n) {
	int x = sqrt(n);
	return x * x == n || (x - 1) * (x - 1) == n || (x + 1) * (x + 1) == n;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		puts(n % 2 == 0 && (chk(n / 2) || (n % 4 == 0 && chk(n / 4))) ? "YES" : "NO");
	}
	return 0;
}
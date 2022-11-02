#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2005;

int T, n, A[N];

int main() {
	for(cin >> T; T--;) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &A[i]);
		sort(A + 1, A + n + 1, [](int x, int y) { return __builtin_ctz(x) > __builtin_ctz(y); });
		int as = 0;
		rep(i, 1, n) rep(j, i + 1, n) as += __gcd(A[i], A[j] * 2) > 1;
		printf("%d\n", as);
	}
	return 0;
}
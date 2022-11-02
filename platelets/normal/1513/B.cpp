#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5, P = 1e9 + 7;

int T, n, A[N];

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		int x = -1, cn = 0;
		rep(i, 1, n) scanf("%d", &A[i]), x &= A[i];
		rep(i, 1, n) cn += x == A[i];
		long long as = 1;
		rep(i, 1, n - 2) as = as * i % P;
		printf("%lld\n", as * cn % P * (cn - 1) % P); 
	}
	return 0;
}
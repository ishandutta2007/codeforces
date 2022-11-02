#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int T, n, K, A[105];

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		cin >> n >> K;
		if(K > (n - 1) / 2) { puts("-1"); continue; }
		rep(i, 1, n) A[i] = 0;
		int idx = n;
		rep(i, 1, K) A[i * 2] = idx--;
		rep(i, 1, n) if(!A[i]) A[i] = idx--;
		rep(i, 1, n) printf("%d ", A[i]);
		puts("");
	}
	return 0;
}
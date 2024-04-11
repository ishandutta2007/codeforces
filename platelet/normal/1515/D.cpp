#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int T, n, l, r, A[N], L[N], R[N];

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d%d", &n, &l, &r);
		rep(i, 1, n) scanf("%d", &A[i]), L[i] = R[i] = 0;
		if(l < r) swap(l, r), reverse(A + 1, A + n + 1);
		rep(i, l + 1, n) R[A[i]]++;
		int re = (l - r) / 2, as = 0;
		rep(i, 1, l) if(R[A[i]]) R[A[i]]--;
		else if(L[A[i]] && re) L[A[i]]--, as++, re--;
		else L[A[i]]++;
		rep(i, 1, n) as += L[i];
		printf("%d\n", as);
	}
	return 0;
}
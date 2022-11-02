#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5, P = 1e9 + 7;

int T, n, p, A[N], ord[N], L[N], R[N], fa[N];
int find(int x) { return x ^ fa[x] ? fa[x] = find(fa[x]) : x; }

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &p);
		rep(i, 1, n) scanf("%d", &A[i]), fa[i] = ord[i] = i;
		rep(i, 1, n) for(int& j = L[i] = i - 1; j && A[j] % A[i] == 0; j = L[j]);
		per(i, n, 1) for(int& j = R[i] = i + 1; j <= n && A[j] % A[i] == 0; j = R[j]);
		sort(ord + 1, ord + n + 1, [](int x, int y) { return A[x] < A[y]; });
		long long as = p * (n - 1ll);
		rep(i, 1, n) if(A[ord[i]] < p)
		for(int l = find(L[ord[i]] + 1); l <= R[ord[i]] - 2; l = find(l))
			as += A[ord[i]] - p, fa[l] = l + 1;
		printf("%lld\n", as);
	}
	return 0;
}
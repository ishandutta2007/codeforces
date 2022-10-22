#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

int n, A[1005], B[1005], pos[1005], tp, x[1000005], y[1000005];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &A[i]), B[i] = A[i];
	sort(B + 1, B + n + 1);
	rep(i, 1, n) A[i] = lower_bound(B + 1, B + n + 1, A[i]) - B, B[A[i]]--, pos[A[i]] = i;
	per(i, n, 1) rep(j, A[i] + 1, n) if(pos[j] < i) x[++tp] = pos[j], y[tp] = i;
	cout << tp << endl;
	rep(i, 1, tp) printf("%d %d\n", x[i], y[i]);
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 4e5 + 5;
int T, n, A[N], B[N], C[N], D[N];
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n), n *= 2;
		int cnA = 0, cnB = 0, cnC = 0;
		rep(i, 1, n) scanf("%1d", &A[i]), cnA += A[i];
		rep(i, 1, n) scanf("%1d", &B[i]), cnB += B[i];
		rep(i, 1, n) scanf("%1d", &C[i]), cnC += C[i];
		auto Swap = [](int A[], int B[]) {
			rep(i, 1, n) swap(A[i], B[i]);
		};
		if(cnA > cnB) Swap(A, B), swap(cnA, cnB);
		if(cnA > cnC) Swap(A, C), swap(cnA, cnC);
		if(cnB > cnC) Swap(B, C), swap(cnB, cnC);
		int p = 1, idx = 0;
		if(cnB <= n / 2) rep(i, 1, n) {
			while(p <= n && B[p] == 1) D[++idx] = 1, p++;
			if(p <= n && A[i] == 0) p++;
			D[++idx] = A[i];
		} else rep(i, 1, n) {
			while(p <= n && B[p] == 0) D[++idx] = 0, p++;
			if(p <= n && C[i] == 1) p++;
			D[++idx] = C[i];
		}
		while(p <= n) D[++idx] = B[p++];
		rep(i, 1, idx) printf("%d", D[i]);
		puts("");
	}
	return 0;
}
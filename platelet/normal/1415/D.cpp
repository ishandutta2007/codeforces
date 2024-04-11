#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 1e5 + 5;
int n, A[N]; 

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &A[i]);
	if(n <= 100) {
		int ans = 1e9;
		rep(i, 1, n) {
			int l = 0;
			rep(j, i, n) {
				l ^= A[j];
				int r = 0;
				rep(k, j + 1, n) {
					r ^= A[k];
					if(l > r) ans = min(ans, k - i - 1);
				}
			}
		}
		printf("%d\n", ans == 1e9 ? -1 : ans);
	} else puts("1");
	return 0;
}
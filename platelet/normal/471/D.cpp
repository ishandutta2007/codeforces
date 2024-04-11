#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e5 + 5; 
int n, m, A[N], B[N], f[N]; 
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m, n--, m--;
	if(!m) return !printf("%d", n + 1); 
	rep(i, 0, n) scanf("%d", &A[i]);
	per(i, n, 1) A[i] -= A[i-1];
	rep(i, 0, m) scanf("%d", &B[i]);
	per(i, m, 1) B[i] -= B[i-1];
	rep(i, 2, m) {
		int& j = f[i] = f[i-1];
		while(j && B[i] ^ B[j+1]) j = f[j];
		if(B[i] == B[j+1]) j++;
	}
	int j = 0, ans = 0;
	rep(i, 1, n) {
		while(j && A[i] ^ B[j+1]) j = f[j];
		if(A[i] == B[j+1]) j++;
		if(j == m) j = f[j], ans++;
	}
	cout << ans;
	return 0;
}
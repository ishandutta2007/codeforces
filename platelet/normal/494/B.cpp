#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 5, P = 1e9 + 7;
int n, m; char a[N], b[N]; int f[N]; long long dp[N], su[N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	rep(i, 2, m) {
		int& j = f[i] = f[i-1];
		while(j && b[i] ^ b[j+1]) j = f[j];
		if(b[i] == b[j+1]) j++;
	}
	su[0] = dp[0] = 1; int j = 0, lst = 0;
	rep(i, 1, n) {
		dp[i] = dp[i-1];
		while(j && a[i] ^ b[j+1]) j = f[j];
		if(a[i] == b[j+1]) j++;
		if(j == m) lst = i;
		if(lst) (dp[i] += su[lst-m]) %= P;
		su[i] = (su[i-1] + dp[i]) % P;
	}
	cout << (dp[n] + P - 1) % P;
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
int n, f[505][505]; char s[505];
int dp(int l, int r) {
	if(l >= r) return l == r;
	if(f[l][r]) return f[l][r];
	int& ret = f[l][r] = dp(l + 1, r) + 1;
	rep(k, l + 1, r) if(s[l] == s[k])
		ret = min(ret, dp(l + 1, k) + dp(k + 1, r));
	return ret;
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%d%s", &n, s + 1);
	return !(cout << dp(1, n));
}
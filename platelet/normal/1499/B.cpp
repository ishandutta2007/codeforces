#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 105;
int T, n, f[N], a[N]; char s[N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%s", s + 1), n = strlen(s + 1);
		mem(f, 0), f[0] = 1;
		rep(i, 1, n) f[i] = (s[i - 1] <= s[i] && f[i - 1]) | (s[i - 2] <= s[i] && f[i - 2]);
		puts(f[n] | f[n - 1] ? "YES" : "NO");
	}
	return 0;
}
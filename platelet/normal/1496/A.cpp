#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	int T, n, K;
	char s[105];
	for(cin >> T; T--;) {
		scanf("%d%d%s", &n, &K, s + 1);
		int i = 0;
		while(i < n / 2 && s[i + 1] == s[n - i]) i++;
		if(i == n / 2) puts((n + 1) / 2 >= K + 1 ? "YES" : "NO");
		else puts(i >= K ? "YES" : "NO");
	}
	return 0;
}
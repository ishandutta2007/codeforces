#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 1005;

int T, n, nxt[N][26];
char s[N], t[N];
int chk(int m) {
	rep(i, 1, n - m + 1) {
		int f = 1;
		rep(j, 1, m) f &= s[i + j - 1] == t[j];
		if(f) return 1;
	}
	return 0;
}
int dfs(int i, int m) {
	if(i > m) {
		if(!chk(m)) {
			t[m + 1] = 0;
			printf("%s\n", t + 1);
			return 1;
		}
		return 0;
	}
	rep(j, 'a', 'z') {
		t[i] = j;
		if(dfs(i + 1, m)) return 1;
	}
	return 0;
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--;) {
		scanf("%d%s", &n, s + 1);
		rep(i, 1, n) if(dfs(1, i)) break;
	}
	return 0;
}
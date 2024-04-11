#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1005;
int T, n, m, a[N], b[N];

int main() {
#ifdef local
	// freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &m);
		a[n + 1] = 0;
		rep(i, 1, n) scanf("%1d", &a[i]);
		while(m--) {
			int f = 0;
			rep(i, 1, n) if(!a[i]) f |= b[i] = a[i - 1] ^ a[i + 1];
			if(!f) break;
			rep(i, 1, n) a[i] |= b[i];
		}
		rep(i, 1, n) printf("%d", a[i]);
		puts("");
	}
}
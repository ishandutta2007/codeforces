#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
int T, n, m, x, su[205];
void solve() {
	mem(su, 0);
	cin >> n >> m;
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &x), su[i + j] ^= x;
	rep(i, 1, n + m) if(su[i]) { puts("Ashish"); return; }
	puts("Jeel");
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--; solve());
	return 0;
}
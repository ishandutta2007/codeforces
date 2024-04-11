#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2005;
int T, n, K, a[N];
int solve() {
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]);
	int su = 0;
	For(i, 1, n) {
		su ^= a[i];
		int nw = 0, ok = 0;
		rep(j, i + 1, n) {
			nw ^= a[j];
			if(nw == su) nw = 0, ok = 1;
		}
		if(!nw && ok) return 1;
	}
	return 0;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--; puts(solve() ? "YES" : "NO"));
	return 0;
}
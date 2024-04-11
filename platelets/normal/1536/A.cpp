#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 105;

int T, n, a[N];

int main() {
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef local
	freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--;) {
		cin >> n;
		int x = 0;
		rep(i, 1, n) cin >> a[i], x |= a[i] < 0;
		if(x) puts("NO");
		else {
			cout << "YES" << endl << 300 << endl;
			rep(i, 0, 299) cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}
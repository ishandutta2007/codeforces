#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 5e5 + 5;

int T, n, f[N];
char s[N];

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--;) {
		scanf("%d%s", &n, s + 1);
		map<pair<int, int>, int> ls;
		int d = 0, k = 0;
		rep(i, 1, n) {
			d += s[i] == 'D', k += s[i] == 'K';
			int g = __gcd(d, k);
			pair<int, int> p(d / g, k / g);
			f[i] = f[ls[p]] + 1;
			ls[p] = i;
			printf("%d ", f[i]);
		}
		puts("");
	}
	return 0;
}
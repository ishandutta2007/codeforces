#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 105;
int n, a[N];
bitset <N * 2000> b;
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	int gcd = 1e9;
	rep(i, 1, n) scanf("%d", &a[i]), gcd = min(gcd, 1 << __builtin_ctz(a[i]));
	b[0] = 1;
	int su = 0;
	rep(i, 1, n) a[i] /= gcd, b |= b << a[i], su += a[i];
	if(su % 2 || !b[su / 2]) puts("0"), exit(0);
	puts("1");
	rep(i, 1, n) if(a[i] & 1) cout << i, exit(0);
	return 0;
}
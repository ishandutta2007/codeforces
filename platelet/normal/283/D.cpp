#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 5005;
long long a[N]; int n, ctz[N], f[N], as = 1e9;
int main() {
	mem(f, 63), f[0] = 0;
	cin >> n;
	rep(i, 1, n) scanf("%lld", &a[i]), ctz[i] = __builtin_ctzll(a[i]);
	rep(i, 1, n) {
		rep(j, 0, i - 1)
		if(!a[j] || ((a[j] >> ctz[j]) % (a[i] >> ctz[i]) == 0 && (ctz[i] - ctz[j] == i - j || ctz[i] <= i - j - 1)))
			f[i] = min(f[i], f[j] + i - j - 1);
		as = min(as, f[i] + n - i);
	}
	cout << as;
	return 0;
}
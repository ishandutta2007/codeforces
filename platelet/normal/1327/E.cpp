#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e5 + 5, P = 998244353;
typedef long long ll;
int n; ll ten[N], f[N];
int main() {
	cin >> n, ten[0] = 1;
	rep(i, 1, n) ten[i] = ten[i-1] * 10 % P;
	rep(i, 1, n) f[i] = 10 * (n - i + 1) * ten[n-i] % P;
	rep(i, 1, n) printf("%lld ", (f[i] - 2 * f[i+1] + f[i+2] + P * 2) % P);
	return 0;
}
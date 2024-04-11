#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;

typedef long long ll;
const int N = 205;
const ll P = 1e9 + 7;

int n, K, C[N * 2][N * 2];
ll f[N * 2][N], as[N];

ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}
ll calc(int x) {
	ll a = 1, b = 1;
	while(x) b = b * x-- % P, a = a * (n - x) % P;
	return a * Pow(b, P - 2) % P;
}
int main() {
	cin >> n >> K;
	f[0][0] = 1;
	rep(i, 1, K * 2) rep(j, 1, K)
		f[i][j] = (f[i - 1][j - 1] + (i - 1) * f[i - 1][j]) % P;
	rep(i, 0, K * 2) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	rep(i, 1, K * 2) rep(j, 1, K) rep(k, 1, min(i, j))
		(f[i][j] -= C[i][k] * f[i - k][j - k]) %= P;
	rep(i, 0, K) {
		rep(j, i, i * 2) (as[i] += f[j][j - i] * calc(j)) %= P;
		if(i >= 2) (as[i] += as[i - 2]) %= P;
		if(i) printf("%lld ", (as[i] + P) % P);
	}
	return 0;
}
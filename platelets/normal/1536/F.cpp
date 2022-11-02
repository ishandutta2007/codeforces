#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;
const int N = 1e6 + 5;
const ll P = 1e9 + 7;

int T, n;
ll J[N], iJ[N];

ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}
ll C(int n, int m) {
	return n >= m && m >= 0 ? J[n] * iJ[m] % P * iJ[n - m] % P : 0;
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	cin >> n;
	if(n == 2) puts("4"), exit(0);
	J[0] = 1;
	rep(i, 1, n) J[i] = J[i - 1] * i % P;
	iJ[n] = Pow(J[n], P - 2);
	per(i, n, 1) iJ[i - 1] = iJ[i] * i % P;
	ll as = 0;
	rep(i, 1, n) if(~i & 1) (as += J[i] * (C(i - 1, n - i - 1) + C(i, n - i))) %= P;
	cout << as * 2 % P;
	return 0;
}
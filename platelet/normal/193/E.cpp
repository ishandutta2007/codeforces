#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

typedef long long ll;

ll P = 1000, T = 1500, x;

ll mul(ll a, ll b) {
	return (a * b - (ll)((long double)a / P * b + 0.5) * P + P) % P;
}

struct mat {
	ll a[2][2];
	mat() { mem(a, 0); }
	mat operator *(const mat& b) {
		mat c;
		rep(i, 0, 1) rep(j, 0, 1) rep(k, 0, 1)
			(c.a[i][j] += mul(a[i][k], b.a[k][j])) %= P;
		return c;
	}
};

ll fib(ll n) {
	mat A, R;
	A.a[0][0] = A.a[0][1] = A.a[1][0] = R.a[0][0] = R.a[1][1] = 1;
	for(; n; n /= 2, A = A * A) if(n & 1) R = R * A;
	return R.a[0][1];
}

int F[1500];
int main() {
	cin >> x;
	F[1] = 1;
	For(i, 2, T) F[i] = (F[i - 1] + F[i - 2]) % P;
	vector<ll> nw, as;
	For(i, 0, T) if(F[i] == x % P) nw.pb(i);
	rep(i, 4, 13) {
		P *= 10;
		rep(j, 0, 9) for(ll k : nw) {
			ll t = T * j + k;
			if(fib(t) == x % P) as.pb(t);
		}
		nw = as, as.clear(), T *= 10;
	}
	cout << (nw.empty() ? -1 : nw[0]);
	return 0;
}
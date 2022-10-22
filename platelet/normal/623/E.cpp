#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
constexpr int N = 65536, P = 1e9 + 7, M = sqrt(P);
typedef long long ll;
const double PI = acos(-1);
typedef complex <double> cmp;
const cmp I(0, 1);
int K, lim = 1, bit = -1, rev[N];
cmp wn[N], a0[N], a1[N], b0[N], b1[N], p[N], q[N];
ll n, J[N], iJ[N], A[N], R[N];
ll Pow(ll a, int n, ll r = 1) {
	for(; n; n /= 2, a = a * a % P)
	if(n & 1) r = r * a % P;
	return r;
}

void FFT(cmp a[], int inv) {
	if(!~inv) For(i, 1, lim) if(i < lim - i) swap(a[i], a[lim - i]);
	For(i, 0, lim) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int i = 1; i < lim; i *= 2) for(int j = 0; j < lim; j += i * 2) For(k, 0, i) {
		cmp x = a[j + k], y = a[i + j + k] * wn[lim / i * k];
		a[j + k] = x + y, a[i + j + k] = x - y;
	}
	if(!~inv) For(i, 0, lim) a[i] /= lim;
}
void FFT2(cmp a[], cmp b[]) {
	For(i, 0, lim) a[i] += b[i] * I;
	FFT(a, 1);
	For(i, 0, lim) b[i] = conj(a[i ? lim - i : 0]);
	For(i, 0, lim) {
		cmp x = a[i], y = b[i];
		a[i] = (y + x) * 0.5, b[i] = (y - x) * 0.5 * I;
	}
}
ll num(double x) { return ll(x + 0.5) % P; }
void MTT(ll a[], ll b[], ll c[], ll t) {
	For(i, 0, lim) a0[i] = a1[i] = b0[i] = b1[i] = 0;
	ll pw = 1;
	rep(i, 0, K) {
		ll x = a[i] * iJ[i] % P * pw % P, y = b[i] * iJ[i] % P; (pw *= t) %= P;
		a0[i] = x / M, a1[i] = x % M, b0[i] = y / M, b1[i] = y % M;
	}
	FFT2(a0, a1), FFT2(b0, b1);
	For(i, 0, lim) {
		p[i] = a0[i] * b0[i] + I * a1[i] * b0[i];
		q[i] = a0[i] * b1[i] + I * a1[i] * b1[i];
	}
	FFT(p, -1), FFT(q, -1);
	rep(i, 0, K) c[i] = (M * (M * num(p[i].real()) +
	num(p[i].imag()) + num(q[i].real())) + num(q[i].imag())) % P;
	rep(i, 0, K) (c[i] *= J[i]) %= P;
}
int main() {
	cin >> n >> K;
	if(n > K) puts("0"), exit(0);
	rep(i, 1, K) A[i] = 1;
	R[0] = J[0] = iJ[0] = 1;
	rep(i, 1, K) iJ[i] = Pow(J[i] = J[i - 1] * i % P, P - 2);
	while(lim <= K * 2) lim *= 2, bit++;
	For(i, 0, lim) {
		rev[i] = rev[i / 2] / 2 | (i & 1) << bit;
		wn[i] = cmp(cos(PI / lim * i), sin(PI / lim * i));
	}
	for(ll two = 2; n; n /= 2, MTT(A, A, A, two), (two *= two) %= P)
	if(n & 1) MTT(R, A, R, two);
	ll ans = 0;
	rep(i, 1, K) (ans += R[i] * J[K] % P * iJ[K - i] % P * iJ[i]) %= P;
	cout << ans;
	return 0;
}
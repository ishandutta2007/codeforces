#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 107, mod = 998244353, inv2 = (mod + 1) / 2;
int ns = 0;
ll na, la[N], ra[N], nb, lb[N], rb[N], tp; 
struct node {
	ll v, k;
} s[N * N * N * 8];
void calc(ll l, ll r, ll k) {
	++tp, s[tp].v = l, s[tp].k = k;
	++tp, s[tp].v = r + 1, s[tp].k = -k;
}
void minx(ll x, ll y, int op) {
	ll all = (x ^ y);
	for(; x; ) {
		ll r = (x & -x);
		x -= r;
		ll tmp = all ^ (all & (r - 1)) ^ r;
		calc(tmp, tmp + r - 1, (y & (r - 1)) * op);
	}
}
void allu(ll x, ll y, int op) {
	ll all = (x ^ y);
	for(; x; ) {
		ll r = (x & -x);
		x -= r;
		if(!(y & r)) continue;
		ll tmp = all ^ (all & (r - 1));
		calc(tmp, tmp + r - 1, r * op);
	}
}
void qry (ll x, ll y, int op) {
	++x, ++y, minx(x, y, op), minx(y, x, op), allu(x, y, op);
}
int sumk (ll l, ll r) { return (r - l + 1) % mod * ((l + r) % mod) % mod; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> na;
	L(i, 1, na) cin >> la[i] >> ra[i];
	cin >> nb;
	L(i, 1, nb) cin >> lb[i] >> rb[i];
	L(i, 1, na) L(j, 1, nb) {
		qry(ra[i], rb[j], 1), qry(la[i] - 1, rb[j], -1);
		qry(ra[i], lb[j] - 1, -1), qry(la[i] - 1, lb[j] - 1, 1);
	}
	sort(s + 1, s + tp + 1, [&] (node a, node b) { return a.v < b.v; });
	ll sum = 0;
	L(i, 1, tp) {
		if(sum) (ns += sumk(s[i - 1].v, s[i].v - 1)) %= mod;
		sum += s[i].k;
	}
	ns = (ll) ns * inv2 % mod;
	cout << ns << '\n';
	return 0;
}
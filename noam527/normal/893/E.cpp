#include <bits/stdc++.h>
typedef long long ll;
const int md = 1e9 + 7;
using namespace std;

const int lim = 1e6 + 50;

int d[lim];
ll inv[lim], f[lim];

void sieve() {
	for (int i = 0; i < lim; i++) d[i] = -1;
	int i = 2;
	for (; i * i < lim; i++)
		if (d[i] == -1)
			for (int j = i; j < lim; j += i)
				if (d[j] == -1)
					d[j] = i;
	for (; i < lim; i++)
		if (d[i] == -1) d[i] = i;
}

void preprocess() {
	sieve();

	inv[0] = inv[1] = 1;
	for (int i = 2; i < lim; i++)
		inv[i] = (md - (md / i) * inv[md % i] % md) % md;
	for (int i = 2; i < lim; i++)
		inv[i] = (inv[i] * inv[i - 1]) % md;

	f[1] = 1;
	for (int i = 2; i < lim; i++)
		f[i] = (i * f[i - 1]) % md;
}

int modpow(ll b, int e) {
	int rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}

int nck(int top, int bot) {
	return (((ll)f[top] * inv[bot]) % md * (ll)inv[top - bot]) % md;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	preprocess();
	int q, lst, cnt, x, y;
	ll ans;
	cin >> q;
	while (q--) {
		cin >> x >> y;
		ans = 1;
		if (x == 1) cout << modpow(2, y - 1) << '\n';
		else {
			lst = d[x], x /= d[x], cnt = 1;
			while (x > 1) {
				if (lst == d[x]) cnt++;
				else ans = (ans * nck(y + cnt - 1, cnt)) % md, cnt = 1, lst = d[x];
				x /= d[x];
			}
			ans = (ans * nck(y + cnt - 1, cnt)) % md;
			ans = (ans * modpow(2, y - 1)) % md;
			cout << ans << '\n';
		}
	}
}
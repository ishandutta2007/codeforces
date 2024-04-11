#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

ll pw(ll b, ll e) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}
ll inv(ll x) {
	return pw(x, md - 2);
}
ll choose(ll n, ll k) {
	k = min(k, n - k);
	ll rtn = 1;
	for (ll i = n; i > n - k; i--)
		rtn = rtn * i % md;
	for (ll i = 1; i <= k; i++)
		rtn = rtn * inv(i) % md;
	return rtn;
}

ll n, k;
ll divcnt = 1;
vector<pair<ll, ll>> b;
ll C[20][55][10001], in[100];
ll ans = 0;
ll I;

void pre(int ind, int tot) {
	for (int i = 1; i < 100; i++) in[i] = inv(i);

	for (int i = 0; i <= tot; i++) C[ind][i][0] = 0;
	C[ind][tot][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= tot; j++) {
			C[ind][j][i] = 0;
			for (int x = j; x <= tot; x++)
				C[ind][j][i] = (C[ind][j][i] + C[ind][x][i - 1] * in[1 + x]) % md;
		}
	}
}

void calc(int ind = 0, ll D = 1, ll cnt = 1) {
	if (ind == b.size()) {
		ans = (ans + ((D % md * cnt) % md)) % md;
		return;
	}
	for (int i = 0; i <= b[ind].second; i++) {
		calc(ind + 1, D, cnt * C[ind][i][k] % md);
		D = D * b[ind].first;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	ll tmp = n;
	for (ll i = 2; i * i <= n; i++) {
		if (tmp % i == 0) {
			b.push_back({ i, 0 });
			while (tmp % i == 0) {
				tmp /= i;
				b.back().second++;
			}
		}
	}
	if (tmp > 1) b.push_back({ tmp, 1 });

	for (auto &i : b)
		divcnt = divcnt * (1 + i.second);

	for (int i = 0; i < b.size(); i++)
		pre(i, b[i].second);
	I = 1;
	for (int i = 0; i < k; i++)
		I = I * divcnt % md;
	I = inv(I);

	calc();
	cout << ans << endl;
}
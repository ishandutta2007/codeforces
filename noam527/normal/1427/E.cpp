#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

ll pw(ll b, ll e, ll mod) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % mod;
		e /= 2, b = b * b % mod;
	}
	return rtn;
}

ll topmost(ll x) {
	while (x != (x & -x)) x ^= (x & -x);
	return x;
}

int bitcount(ll x) {
	int res = 0;
	while (x) {
		res++;
		x ^= (x & -x);
	}
	return res;
}

int oddmult(ll x) {
	for (int i = 1; i <= 1000000; i++) {
		ll a = i * x;
		if (bitcount(a) % 2 == 1) return i;
	}
	cout << "bad\n";
	return -1;
}

vector<string> ans;

void outputadd(ll x, ll y) {
	string str = "";
	str.append(to_string(x));
	str.append(" + ");
	str.append(to_string(y));
	ans.push_back(str);
}
void outputxor(ll x, ll y) {
	string str = "";
	str.append(to_string(x));
	str.append(" ^ ");
	str.append(to_string(y));
	ans.push_back(str);
}

void getmult(ll x, ll i) {
	for (ll cur = 1; 2 * cur <= i; cur *= 2) {
		outputadd(cur * x, cur * x);
	}
	vector<ll> b;
	for (ll j = 1; j <= i; j *= 2) {
		if (i & j) b.push_back(j);
	}
	if (b.size() == 1) return;
	ll cur = b[0];
	for (int j = 1; j < b.size(); j++) {
		outputadd(cur * x, b[j] * x);
		cur += b[j];
	}
}

void solve() {
	ll x;
	cin >> x;
	if (x % 4 == 3) {
		outputadd(x, x);
		outputadd(x, 2 * x);
		x = 3 * x;
	}

	ll top = topmost(x);
	getmult(x, top);
	ll y = x * top;
	outputxor(x, y);
	outputadd(x, y);
	outputxor(x ^ y, x + y);
	ll r = (x ^ y) ^ (x + y);
	ll single = r;

	/*

	if (OO) {
		cout << "r: " << r << '\n';
	}

	ll need = oddmult(x);
	getmult(x, need);
	ll single = x * need;

	getmult(r, (1 << 21));
	while (topmost(single) > topmost(r)) {
		outputxor(single, r * topmost(single) / topmost(r));
		single ^= (r * topmost(single) / topmost(r));
	}
	while (single != (single & -single)) {
		if ((single ^ r) > single) {
			outputadd(single, single);
			single *= 2;
		}
		else {
			outputxor(single, r);
			single ^= r;
		}
	}

	*/
	while (x >= single) {
		outputadd(single, single);
		single *= 2;
	}
	if (OO) {
		cout << "single " << single << '\n';
	}
	getmult(single, (1 << 21));
	ll inv = pw(x, single / 2 - 1, single);
	if (OO) {
		cout << "inv " << inv << '\n';
	}
	getmult(x, inv);
	ll fin = x * inv;
	if (OO) {
		cout << "fin " << fin << '\n';
	}
	while (fin != 1) {
		ll ratio = topmost(fin) / topmost(single);
		outputxor(fin, ratio * single);
		fin ^= (ratio * single);
	}
	// the end
	cout << ans.size() << '\n';
	for (const auto &i : ans) cout << i << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) {
		solve();
	}
}
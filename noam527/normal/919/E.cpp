#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int pw(ll b, int e, const int &p) {
	int rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % p;
		e /= 2, b = b * b % p;
	}
	return rtn;
}
int inv(int x, const int &p) {
	return pw(x, p - 2, p);
}

ll a, b, p, x, cnt = 0;

int main() {
	cin >> a >> b >> p >> x;
	for (int i = 0, mult = 1; i < p - 1; i++, mult = (mult * a) % p) {
		ll ans = b * inv(mult, p) % p;
		ll st = i + (p - 1) * ((i - ans + p) % p);
		if (st <= x) cnt += 1 + (x - st) / (p * (p - 1));
	}
	cout << cnt << endl;
}
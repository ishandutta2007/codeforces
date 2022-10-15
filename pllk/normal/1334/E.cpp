#include <iostream>
#include <vector>

using namespace std;

#define M 998244353
typedef long long ll;

ll ncr[1010][1010];

int main() {
	ncr[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
			ncr[i][j] %= M;
		}
	}
	ll d;
	cin >> d;
	vector<ll> f;
	for (ll x = 2; x*x <= d; x++) {
		if (d%x == 0) {
			f.push_back(x);
			while (d%x == 0) d /= x;
		}
	}
	if (d != 1) f.push_back(d);
	int q;
	cin >> q;
	while (q--) {
		ll v, u;
		cin >> v >> u;
		vector<int> ca, cb;
		int sa = 0, sb = 0;
		for (auto x : f) {
			int c1 = 0, c2 = 0;
			while (v%x == 0) {c1++; v /= x;}
			while (u%x == 0) {c2++; u /= x;}
			if (c1 < c2) {
				ca.push_back(c2-c1);
				sa += c2-c1;
			} else if (c1 > c2) {
				cb.push_back(c1-c2);
				sb += c1-c2;
			}
		}
		ll r = 1;
		for (auto x : ca) {
			r *= ncr[sa][x];
			r %= M;
			sa -= x;
		}
		for (auto x : cb) {
			r *= ncr[sb][x];
			r %= M;
			sb -= x;
		}
		cout << r << "\n";
	}
}
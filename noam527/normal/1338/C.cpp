#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll nt;

void solve() {
	cin >> nt;
	ll n = (nt + 2) / 3;
	ll k = 0, l = 1, r = 1;
	while (r < n) {
		k++;
		l = r + 1;
		r += (1LL << (2 * k));
	}
	ll kk = k;
	ll A = (1LL << (2 * k)) + n - l;
	ll B = 0;
	while (kk > 0) {
		--kk;
		ll div = (1LL << (2 * kk));
		ll rank = (n - l) / div;

		//cout << div << " " << n - l << " " << rank << endl;
		if (rank == 1) {
			B += 2 * div;
		}
		else if (rank == 2) {
			B += 3 * div;
		}
		else if (rank == 3) {
			B += div;
		}
		while (rank > 0) {
			n -= div;
			rank--;
		}
	}
	B += 2 * (1LL << (2 * k));
	if (nt % 3 == 1) cout << A << '\n';
	if (nt % 3 == 2) cout << B << '\n';
	if (nt % 3 == 0) cout << (A ^ B) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}
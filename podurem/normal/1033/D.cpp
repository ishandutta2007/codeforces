#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
typedef long double ld;

using namespace std;

const int dd = (int)1e4 + 7;
const ll mod = 998244353;

ll A[dd];

ll sq(ll a, int x) {
	ll l = 0, r = (x == 2 ? 2e9 : x == 3 ? 15e5 : 4e4);
	while (r - l > 1) {
		ll m = (l + r) / 2;
		ll C = 1;
		for (int i = 0; i < x; ++i) 
			C *= m;
		if (C <= a) 
			l = m;
		else
			r = m;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<ll, int> P;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	ll um = 1;
	for (int i = 0; i < n; ++i) {
		ll X = sq(A[i], 4);
		if (X * X * X * X == A[i]) { //5
			P[X] += 4;
		} else {
			X = sq(A[i], 2);
			if (X * X == A[i]) { //3
				P[X] += 2;
			} else { //4
				ll X = sq(A[i], 3);
				if (X * X * X == A[i]) {
					P[X] += 3;
				} else {
					set<ll> S;
					for (int j = 0; j < n; ++j) if (i != j) {
						ll F = __gcd(A[i], A[j]);
						if (F > 1 && F < A[i]) {
							S.insert(F);
						}
					}
					if (S.empty()) {
						int cnt = 0;
						int ok = 1;
						for (int j = 0; j < i; ++j) if (A[i] == A[j]) {
							ok = 0;
						}
						if (ok) {
							for (int j = 0; j < n; ++j)
								cnt += (A[i] == A[j]);
							um = um * (cnt + 1) % mod * (cnt + 1) % mod;
						}
					} else {
						if (S.size() == 1) {
							S.insert(A[i] / *S.begin());
						}
						P[*S.begin()]++;
						P[*S.rbegin()]++;
					}
				}
			}
		}
	}
	for (auto i : P) {
		um = um * (i.second + 1) % mod;
	}
	cout << um << "\n";
	return 0;
}
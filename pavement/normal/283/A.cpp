#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, T, A, X, K, S, ft[200005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int l, int r, int v) {
	for (; l <= 200000; l += ls(l)) ft[l] += v;
	for (r++; r <= 200000; r += ls(r)) ft[r] -= v;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int sz = 1; N--; ) {
		cin >> T;
		if (T == 1) {
			cin >> A >> X;
			upd(1, A, X);
			S += X * A;
		} else if (T == 2) {
			cin >> K;
			sz++;
			S += K;
			upd(sz, sz, K);
		} else {
			S -= qry(sz);
			upd(sz, sz, -qry(sz));
			sz--;
		}
		cout << fixed << setprecision(6) << (ld)S / (ld)sz << '\n';
	}
}
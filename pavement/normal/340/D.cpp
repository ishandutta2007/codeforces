#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, A[100005], ft[100005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r = max(r, ft[p]);
	return r;
}

void upd(int p, int v) {
	for (; p <= N; p += ls(p)) ft[p] = max(ft[p], v);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		int r = qry(A[i]) + 1;
		M = max(M, r);
		upd(A[i], r);
	}
	cout << M << '\n';
}
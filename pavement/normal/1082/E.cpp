#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, C, M, A[500005], VC[500005], pf[500005];
map<int, int> rs, nm;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] == C) VC[i] = VC[i - 1] + 1;
		else VC[i] = VC[i - 1];
		A[i] -= C;
		pf[i] = ++rs[A[i]];
	}
	rs.clear();
	nm[A[1]] = 0;
	for (int i = 1; i <= N; i++) {
		rs[A[i]]++;
		M = max(M, nm[A[i]] + pf[i] + VC[N] - VC[i]);
		if (nm.find(A[i + 1]) != nm.end()) nm[A[i + 1]] = max(nm[A[i + 1]], -rs[A[i + 1]] + VC[i]);
		else nm[A[i + 1]] = -rs[A[i + 1]] + VC[i];
	}
	cout << M << '\n';
}

/*
3 3
3 1 3
*/
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

int N, R, T, A[300005], B[300005], fac[300005];
const int M = 998244353;
pair<int, int> C[300005];
map<int, int> cnta, cntb;
map<pair<int, int>, int> scnt;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	fac[0] = 1;
	for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		C[i] = mp(A[i], B[i]);
		cnta[A[i]]++;
		cntb[B[i]]++;
		scnt[mp(A[i], B[i])]++;
	}
	R = 1;
	for (auto &i : cnta)
		R = R * fac[i.second] % M;
	T = R;
	R = 1;
	for (auto &i : cntb)
		R = R * fac[i.second] % M;
	T = (T + R) % M;
	R = 1;
	bool v = 0;
	sort(C + 1, C + 1 + N);
	for (int i = 1; i <= N; i++)
		if (C[i].second < C[i - 1].second) v = 1;
	if (!v) {
		R = 1;
		for (auto &i : scnt)
			R = R * fac[i.second] % M;
		T = (T - R) % M;
	}
	int x = (fac[N] - T) % M;
	while (x < 0) x += M;
	cout << x << '\n';
}
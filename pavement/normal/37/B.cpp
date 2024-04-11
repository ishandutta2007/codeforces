#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, O, M, R, C, T, P[1005], D[1005];
bitset<1005> V;
vector<pair<int, int> > U;

main() {
	V.reset();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> R;
	O = M;
	for (int i = 1; i <= N; i++) cin >> P[i] >> D[i];
	for (; M > 0; M = min(O, M - C + R), T++) {
		int r = 0, p = -1;
		for (int j = 1; j <= N; j++)
			if (!V[j] && 100 * M <= O * P[j] && D[j] > r) {
				r = D[j];
				p = j;
			}
		if (p == -1 && R >= C) return cout << "NO\n", 0;
		if (p != -1) U.emplace_back(T, p), V[p] = 1;
		C += r;
	}
	cout << "YES\n" << T << ' ' << U.size() << '\n';
	for (auto i : U) cout << i.first << ' ' << i.second << '\n';
}
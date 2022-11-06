#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, V[4005], D[4005], P[4005];
bool G[4005];
vector<int> A;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> V[i] >> D[i] >> P[i];
	for (int i = 1; i <= N; i++) {
		if (G[i]) continue;
		A.push_back(i);
		for (int j = i + 1, k = V[i]; j <= N; j++) {
			if (G[j]) continue;
			//cout << "DCRY " << i << ' ' << j << ' ' << k << '\n';
			P[j] -= k;
			k = max(0ll, k - 1);
		}
		for (int j = i + 1; j <= N; j++)
			if (!G[j] && P[j] < 0) {
				G[j] = 1;
				for (int k = j + 1; k <= N; k++) {
					//cout << "LCRY " << k << ' ' << D[j] << '\n';
					P[k] -= D[j];
				}
			}
	}
	cout << A.size() << '\n';
	for (int i : A) cout << i << ' ';
	cout << '\n';
}
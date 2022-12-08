#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	
	vector<int> V(n), T(n), G(n + 2);
	vector<ll> P(n + 1), A(n + 1);
	
	for (int i = 0; i < n; i++) cin >> V[i];
	for (int i = 0; i < n; i++) cin >> T[i];
	
	for (int i = 0; i < n; i++) P[i + 1] = P[i] + T[i];
	
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(P.begin(), P.end(), V[i] + P[i]) - P.begin() - 1;
	
		if (ind < i) continue;
		
		//err("i = %d, ind = %d\n", i, ind);
		if (i <= ind) G[i]++, G[ind]--;
		if (ind < n) A[ind] += V[i] - (P[ind] - P[i]);
	}
	
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += G[i];
		cout << 1ll * cur * T[i] + A[i] << " ";
	}
	return 0;
}
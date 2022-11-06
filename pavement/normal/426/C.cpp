#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, M = LLONG_MAX, A[205];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i], A[i] = -A[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++) {
			int S = 0;
			priority_queue<int> D;
			priority_queue<int, vector<int>, greater<int> > E;
			for (int k = 1; k <= N; k++) {
				if (j <= k && k <= i) D.emplace(A[k]), S += A[k];
				else E.emplace(A[k]);
			}
			for (int k = 1; k <= K; k++) {
				if (D.empty() || E.empty() || D.top() <= E.top()) break;
				S -= D.top() - E.top();
				D.pop();
				E.pop();
			}
			M = min(M, S);
		}
	cout << -M << '\n';
}
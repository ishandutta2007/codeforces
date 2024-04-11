#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, ms, rs, S[100005], R[100005], acc[100005];
stack<int> proc[2];
vector<int> T[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> S[i] >> R[i];
		T[S[i]].push_back(R[i]);
	}
	for (int i = 1; i <= M; i++) {
		if (T[i].size()) {
			proc[1].push(i);
			sort(T[i].begin(), T[i].end(), greater<int>());
		}
	}
	for (int i = 1; i <= N; i++) {
		int minus = 0;
		while (!proc[i & 1].empty()) {
			rs += T[proc[i & 1].top()][i - 1];
			acc[proc[i & 1].top()] += T[proc[i & 1].top()][i - 1];
			if (acc[proc[i & 1].top()] < 0) rs -= acc[proc[i & 1].top()];
			else if (T[proc[i & 1].top()].size() == i) minus += acc[proc[i & 1].top()];
			else proc[1 - (i & 1)].push(proc[i & 1].top());
			proc[i & 1].pop();
		}
		ms = max(ms, rs);
		rs -= minus;
	}
	cout << ms << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int N, K;
priority_queue<int> pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < 30; i++) {
		if (N & (1<<i)) {
			pq.emplace(i);
			K--;
		}
	}
	if (K < 0) return cout << "NO\n", 0;
	while (K--) {
		int x = pq.top();
		pq.pop();
		if (x == 0) return cout << "NO\n", 0;
		pq.emplace(x - 1), pq.emplace(x - 1);
	}
	cout << "YES\n";
	while (!pq.empty()) cout << (1<<pq.top()) << ' ', pq.pop();
	cout << '\n';
}
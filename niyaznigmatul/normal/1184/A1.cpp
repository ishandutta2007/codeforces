/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;


long long const INF = 1LL << 60;
pair<long long, long long> trySolve(long long r, long long x) {
	r--;
	assert(r % x == 0);
	r /= x;
	r -= x;
	if (r < 0) return {INF, INF};
	if (r % 2 == 1 && r > 1) {
		return {x, (r - 1) / 2};
	}
	return {INF, INF};
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);	
	long long r;
	cin >> r;
	pair<long long, long long> ans = {INF, INF};
	for (long long x = 1; x * x <= r - 1; x++) {
		if ((r - 1) % x != 0) continue;
		ans = min(ans, trySolve(r, x));
		ans = min(ans, trySolve(r, (r - 1) / x));
	}
	if (ans.first == INF) {
		cout << "NO\n";
	} else {
		cout << ans.first << ' ' << ans.second << endl;
	}
}
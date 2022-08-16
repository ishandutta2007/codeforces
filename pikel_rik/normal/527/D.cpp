#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n), w(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> w[i];

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
	    return x[i] + w[i] < x[j] + w[j];
	});

	int ans = 0, last = (int)-1e9;
	for (int i : ind) {
	    if (last <= x[i] - w[i]) {
	        ans += 1;
	        last = x[i] + w[i];
	    }
	}
	cout << ans << '\n';
	return 0;
}
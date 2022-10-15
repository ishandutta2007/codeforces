/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];	
	sort(a.begin(), a.end());
	vector<int> used(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		ans++;
		for (int j = i; j < n; j++) {
			if (a[j] % a[i] == 0) {
				used[j] = true;
			}
		}
	}
	cout << ans << endl;
}
#include <iostream>
#include <map>

using namespace std;

map<int, int> data;
int n, q;

int main() {

	cin.sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		data[val]++;
	}

	while (q--) {
		int x;
		cin >> x;
		int ans = 0;
		for (auto it = data.rbegin(); it != data.rend(); ++it) {
			int v = it->first;
			int k = min(it->second, x / v);
			ans += k;
			x -= v * k;
		}

		if (x > 0) ans = -1;
		cout << ans << "\n";
	}

	return 0;
}
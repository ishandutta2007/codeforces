#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, ai, aj;
		cin >> n >> m >> ai >> aj;

		long long dist = 0;
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

		array<pair<int, int>, 4> v;

		v[0] = make_pair(1, 1);
		v[1] = make_pair(1, m);
		v[2] = make_pair(n, 1);
		v[3] = make_pair(n, m);

		for (auto &p1 : v) {
			for (auto &p2 : v) {
				long long temp = 0;
				temp += abs(ai - p1.first) + abs(p1.first - p2.first) + abs(p2.first - ai);
				temp += abs(aj - p1.second) + (p1.second - p2.second) + abs(p2.second - aj);
				if (dist <= temp) {
					dist = temp;
					tie(x1, y1) = p1;
					tie(x2, y2) = p2;
				}
			}
		}
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	}
	return 0;
}
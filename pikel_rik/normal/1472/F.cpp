#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> r(m), c(m);
		for (int i = 0; i < m; i++) cin >> r[i] >> c[i], --r[i];

		if (m % 2 != 0) {
			cout << "NO\n";
			continue;
		}

		vector<int> ind(m);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return c[i] < c[j];
		});

		int st = 0;
		array<int, 2> arr = {0};

		if (c[ind[0]] == c[ind[1]]) {
			st = 2;
		} else {
			arr[r[ind[0]]] = 1;
			st = 1;
		}

		bool ok = true;
		for (int i = st; i < m; i++) {
			if (i + 1 < m && c[ind[i]] == c[ind[i + 1]]) {
				if (arr[0] == 1 || arr[1] == 1) {
					ok = false;
					break;
				}
				i += 1;
			} else {
				if (arr[0] == 0 && arr[1] == 0) {
					arr[r[ind[i]]] = 1;
					arr[1 - r[ind[i]]] = 0;
				} else {
					int len = c[ind[i]] - 1 - (c[ind[i - 1]] + 1) + 1;
					if (len == 0 && arr[r[ind[i]]] == 0) {
						ok = false;
						break;
					} else if (arr[r[ind[i]]] == 1) {
						if (len % 2 != 0) {
							ok = false;
							break;
						}
					} else {
						if (len % 2 == 0) {
							ok = false;
							break;
						}
					}
					arr[0] = arr[1] = 0;
				}
			}
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
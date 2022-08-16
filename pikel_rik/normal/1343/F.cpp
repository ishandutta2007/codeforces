#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> sz(n);
		vector<bitset<200>> segments(n);

		for (int i = 1; i < n; i++) {
			cin >> sz[i];
			for (int j = 0, x; j < sz[i]; j++) {
				cin >> x, --x;
				segments[i][x] = true;
			}
		}

		vector<int> ans;
		for (int ch = 1; ch < n; ch++) {
			if (sz[ch] > 2) {
				continue;
			}

			vector<int> first;
			for (int i = 0; i < n; i++) {
				if (segments[ch][i]) {
					first.push_back(i);
				}
			}

			for (int j = 0; j < 2; j++) {
				vector<int> p(n, -1);
				p[0] = first[j], p[1] = first[j ^ 1];

				vector<int> new_sz = sz;
				vector<bitset<200>> new_segments = segments;

				bool illegal = false;
				for (int i = 1; i < n; i++) {
					illegal |= new_segments[i][p[0]] && !new_segments[i][p[1]];
					new_sz[i] -= new_segments[i][p[0]];
					new_sz[i] -= new_segments[i][p[1]];
					new_segments[i][p[0]] = false;
					new_segments[i][p[1]] = false;
				}

				if (illegal) {
					continue;
				}

				for (int k = 2; k < n; k++) {
					int use = -1;
					for (int l = 1; l < n; l++) {
						if (new_sz[l] == 1) {
							use = l;
							break;
						}
					}
					if (use == -1) {
						break;
					}
					for (int i = 0; i < n; i++) {
						if (new_segments[use][i]) {
							p[k] = i;
						}
					}
					for (int l = 1; l < n; l++) {
						if (new_segments[l][p[k]]) {
							new_segments[l][p[k]] = false;
							new_sz[l] -= 1;
						}
					}
				}

				if (count(p.begin(), p.end(), -1) > 0) {
					continue;
				}

				vector<int> pos(n);
				for (int i = 0; i < n; i++) {
					pos[p[i]] = i;
				}

				bool ok = true;
				for (int i = 1; i < n; i++) {
					int mn = n, mx = -1;
					for (int k = 0; k < n; k++) {
						if (segments[i][k]) {
							mn = min(mn, pos[k]);
							mx = max(mx, pos[k]);
						}
					}
					ok &= mx - mn + 1 == sz[i];
				}

				if (ok) {
					ans = p;
					break;
				}
			}

			if (!ans.empty()) {
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
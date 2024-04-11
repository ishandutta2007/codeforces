/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> d(m);
	for (int i = 0; i < m; i++) cin >> d[i];
	sort(d.begin(), d.end());	
	int green, red;
	cin >> green >> red;
	vector<vector<int>> q(green + 1);
	for (auto &e : q) {
		e.reserve(m + 1);
	}
	vector<vector<int>> dist(green + 1, vector<int>(m, -1));
	q[0].push_back(0);
	int startTime = 0;
	while (true) {
		for (int t = 0; t < green; t++) {
			for (int &v : q[t]) {
				if (v == m - 1) {
					cout << startTime + t << '\n';
					return 0;
				}
				int cd = dist[t][v];
				if (v > 0) {
					int nt = d[v] - d[v - 1] + t;
					if (nt <= green && dist[nt][v - 1] == -1) {
						dist[nt][v - 1] = cd + nt - t;
						q[nt].push_back(v - 1);
					}
				}
				if (v + 1 < m) {
					int nt = d[v + 1] - d[v] + t;
					if (nt <= green && dist[nt][v + 1] == -1) {
						dist[nt][v + 1] = cd + nt - t;
						q[nt].push_back(v + 1);
					}
				}
			}
			q[t].clear();
		}
		for (int &v : q[green]) {
			if (v == m - 1) {
				cout << startTime + green << '\n';
				return 0;
			}
			if (dist[0][v] == -1) {
				dist[0][v] = startTime + green + red;
				q[0].push_back(v);
			}
		}
		q[green].clear();
		if (q[0].empty()) break;
		startTime += red + green;
	}
	cout << "-1\n";
}
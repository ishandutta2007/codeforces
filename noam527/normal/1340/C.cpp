#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m, g, r;
int d[10005];
int dist[1005][10005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> d[i];
	sort(d, d + m); // bro wtf
	cin >> g >> r;

	for (int t = 0; t <= g; t++) for (int i = 0; i < m; i++)
		dist[t][i] = -1;

	queue<pair<int, int>> cur, nxt;
	dist[g][0] = 0;
	cur.push({ g, 0 });
	int D = 0;
	while (cur.size() || nxt.size()) {
		if (!cur.size()) {
			swap(cur, nxt);
			D++;
			continue;
		}
		pair<int, int> x = cur.front();
		cur.pop();
		if (x.second == m - 1) continue;
		if (x.first == 0) {
			dist[g][x.second] = D + 1;
			nxt.push({ g, x.second });
			continue;
		}
		int d1 = (d[x.second + 1] - d[x.second]);
		int d2 = (x.second == 0 ? -1 : d[x.second] - d[x.second - 1]);
		
		if (d1 != -1 && x.first >= d1 && dist[x.first - d1][x.second + 1] == -1) {
			dist[x.first - d1][x.second + 1] = D;
			cur.push({ x.first - d1, x.second + 1 });
		}
		if (d2 != -1 && x.first >= d2 && dist[x.first - d2][x.second - 1] == -1) {
			dist[x.first - d2][x.second - 1] = D;
			cur.push({ x.first - d2, x.second - 1 });
		}
	}
	ll ans = inf;
	for (int t = 0; t <= g; t++) {
		if (dist[t][m - 1] != -1) {
			ans = min(ans, ll(g + r) * dist[t][m - 1] + g - t);
		}
	}
	if (ans == inf) cout << "-1\n";
	else cout << ans << endl;
}
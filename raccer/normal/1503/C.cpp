#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pii;

vector <pii> from[300010];
long long dist[300010];
priority_queue <pii, vector <pii>, greater <pii> > q;
pii a[300010];
int T[300010], C[300010];
int lst[300010];
int vis[300010];

int main() {
//	freopen("data.in", "r", stdin);
	int n; scanf("%d", &n);
	int maxj = -1; long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		C[i] = y, a[i] = mp(x, i);
		sum += y;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(a + 1, a + n + 1, mp(a[i].fi + C[a[i].se], -1)) - a;
		if (pos != n + 1) from[pos + n].push_back(mp(a[i].se, -a[i].fi - C[a[i].se]));
		if (pos != 1) from[pos + n + n - 1].push_back(mp(a[i].se, 0));
		from[a[i].se].push_back(mp(i + n, a[i].fi));
		from[a[i].se].push_back(mp(i + n + n, 0));
		if (i != n) from[i + n + 1].push_back(mp(i + n, 0));
		if (i != 1) from[i + n + n - 1].push_back(mp(i + n + n, 0));
	}
	memset(dist, 0x3f, sizeof(dist)), dist[a[n].se] = 0, q.push(mp(dist[a[n].se], a[n].se));
	while (!q.empty()) {
		pii tmp = q.top(); q.pop();
		int x = tmp.se;
		if (dist[x] != tmp.fi) continue;
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, w = from[x][i].se;
			if (dist[v] > dist[x] + w) {
				dist[v] = dist[x] + w;
				q.push(mp(dist[v], v)), lst[v] = x;
			}
		}
	}
	long long ans = dist[1];
	memset(dist, 0x3f, sizeof(dist)), dist[1] = 0, q.push(mp(dist[1], 1));
	while (!q.empty()) {
		pii tmp = q.top(); q.pop();
		int x = tmp.se;
		if (dist[x] != tmp.fi) continue;
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, w = from[x][i].se;
			if (dist[v] > dist[x] + w) {
				dist[v] = dist[x] + w;
				q.push(mp(dist[v], v)), lst[v] = x;
			}
		}
	}
	int x = a[n].se;
	printf("%I64d\n", ans + dist[a[1].se] + sum);
	return 0;
}
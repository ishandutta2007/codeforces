#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define INF 999999999

int n, m;
int a, b, c;
ll p[202020];
ll s[202020];
vector<int> v[202020];
int d[4][202020];

void lol() {
	cin >> n >> m >> a >> b >> c;
	for (int i = 1; i <= m; i++) cin >> p[i];
	sort(p+1,p+m+1);
	for (int i = 1; i <= m; i++) s[i] = s[i-1]+p[i];
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int h = 1; h <= 3; h++) {
		for (int i = 1; i <= n; i++) d[h][i] = INF;
		int x;
		if (h == 1) x = a;
		if (h == 2) x = b;
		if (h == 3) x = c;
		d[h][x] = 0;
		vector<int> q;
		q.push_back(x);
		for (int i = 0; i < q.size(); i++) {
			for (auto u : v[q[i]]) {
				if (d[h][u] != INF) continue;
				d[h][u] = d[h][q[i]]+1;
				q.push_back(u);
			}
		}
	}
	ll p = 1e18;
	for (int i = 1; i <= n; i++) {
		int d1 = d[1][i];
		int d2 = d[2][i];
		int d3 = d[3][i];
		if (d1+d2+d3 > m) continue;
		ll e1 = s[d2]*2;
		ll e2 = s[d1+d2]-s[d2];
		ll e3 = s[d1+d2+d3]-s[d1+d2];
		p = min(p,e1+e2+e3);
	}
	cout << p << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}
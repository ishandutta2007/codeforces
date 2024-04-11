#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int x[202020];
int y[202020];
set<int> v[202020];
int d[202020];
int z[202020];
vector<int> q;
int c;
vector<int> r;
int p[202020];

void lol() {
	for (int i = 0; i < q.size(); i++) {
		int x = q[i];
		if (!z[x]) continue;
		z[x] = 0;
		c--;
		for (auto y : v[x]) {
			d[y]--;
			if (d[y] < k) {
				if (p[y]) continue;
				p[y] = 1;
				q.push_back(y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) z[i] = 1;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		v[x[i]].insert(y[i]);
		d[x[i]]++;
		v[y[i]].insert(x[i]);
		d[y[i]]++;
	}
	c = n;
	for (int i = 1; i <= n; i++) {
		if (d[i] < k) q.push_back(i);
	}
	lol();
	r.push_back(c);
	for (int i = m; i >= 1; i--) {
		q.clear();
		if (z[x[i]] && z[y[i]]) {
			v[x[i]].erase(y[i]);
			v[y[i]].erase(x[i]);
			d[x[i]]--;
			d[y[i]]--;
			if (d[x[i]] < k) q.push_back(x[i]);
			if (d[y[i]] < k) q.push_back(y[i]);
			lol();
		}
   	    if (i != 1) r.push_back(c);
	}
	reverse(r.begin(),r.end());
	for (auto x : r) cout << x << "\n";
}
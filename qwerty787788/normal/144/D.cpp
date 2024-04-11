#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
struct road {
	long long x1, x2, x3;
};
//
const int INF = 1000000000;
road a[100001];
long long n, m, s, l, x, y, z, sum = 0;
vector < vector < pair<int,int> > > g (1e5+1);
vector<int> d (1e5+1, INF),  p (1e5+1);
set < pair<int,int> > q;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
		a[i].x1 = x;
		a[i].x2 = y;
		a[i].x3 = z;
	}
	scanf("%d", &l);
	//
	d[s] = 0;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}
		}
	}
	//
	for (int i = 1; i <= n; i++) {
		if (d[i] == l) sum++;
	}
	for (int i = 0; i < m; i++) {
		if (d[a[i].x1] < l && d[a[i].x2] > l) sum++; else
			if (d[a[i].x2] < l && d[a[i].x1] > l) sum++; else {
				if (d[a[i].x1] < l) {
					if (d[a[i].x2] == l) {
						if (d[a[i].x1] + a[i].x3 > d[a[i].x2]) sum++;
					} else 
					if (d[a[i].x2] > l) {
						sum++;
					} else {
						if (d[a[i].x1] + d[a[i].x2] + a[i].x3 == 2*l) sum++; else
							if (d[a[i].x1] + d[a[i].x2] + a[i].x3 > 2*l) sum+=2; 
					}
				} else
				if (d[a[i].x2] < l) {
					if (d[a[i].x1] == l) {
						if (d[a[i].x2] + a[i].x3 > d[a[i].x1]) sum++;
					} else 
					if (d[a[i].x1] >= l) {
						sum++;
					} else {
						if (d[a[i].x1] + d[a[i].x2] + a[i].x3 == 2*l) sum++; else
							if (d[a[i].x1] + d[a[i].x2] + a[i].x3 > 2*l) sum+=2; 
					}
				}
			}
	}
	cout << sum << endl;
	//

}
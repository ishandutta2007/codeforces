#include <stdio.h>
#include <bits/stdc++.h>
#define lep(i, j, k) for (int i = (j); i <= (k); i++)

using namespace std;

typedef double db;

const int N = 410, inf = 0x3f3f3f3f;

int n, m, d[N][N];
vector <int> v[N][N];
db c[N], f[N];

int vec[N], cvec;
int D[N], cD;

int main() {
	scanf("%d%d", &n, &m);
	lep (i, 1, n) lep (j, 1, n)
		d[i][j] = inf;
	lep (i, 1, n) d[i][i] = 0;
	lep (i, 1, m) {
		int a, b; scanf("%d%d", &a, &b);
		d[a][b] = d[b][a] = 1;
	}
	lep (k, 1, n) lep (i, 1, n) lep (j, 1, n)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	lep (i, 1, n) lep (j, 1, n) v[i][d[i][j]].push_back(j);
	db Max = 0;
	lep (a, 1, n) {
		db res = 0;
		lep (d1, 0, n) {
			db p1 = (db)v[a][d1].size() / n;
			if (v[a][d1].size() == 0) continue;
			cvec = 0;
			int s = v[a][d1].size();
			for (int i : v[a][d1]) for (int j : v[i][1]) {
				if (c[j] == 0) vec[++cvec] = j;
				c[j] += 1.0 / v[i][1].size();
			}
			db p2 = 1.0 / v[a][d1].size();
			lep (b, 1, n) {
				cD = 0;
				lep (i, 1, cvec) {
					if (c[vec[i]] == 0) continue;
					if (!f[d[b][vec[i]]]) D[++cD] = d[b][vec[i]];
					f[d[b][vec[i]]] = max(c[vec[i]], f[d[b][vec[i]]]);
				}
				double sum = 0;
				lep (i, 1, cD)
					sum += f[D[i]] / s, f[D[i]] = 0;
				p2 = max(p2, sum);
			}
			res += p1 * p2;
			for (int i : vec) c[i] = 0;
		}
		Max = max(res, Max);
	}
	printf("%.10lf\n", Max);
	return 0;
}
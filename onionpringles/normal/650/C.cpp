#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <complex>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 1000000;

vector<int> rowmax;
vector<int> colmax;

vector<int> orig[MN];

map<int, int> rows[MN];

map<int, vector<pii> > mm;

vector<int> jw[2][1000000];

pii quu[2000010];
int qs, qe;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	nii(n, m);
	rowmax.resize(n); colmax.resize(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; ni(a);
			orig[i].push_back(a);
			mm[a].push_back(mp(i, j));
		}
	}
	for (auto &x : mm) {
		//fprintf(stderr, "%d\n", x.first);
		map<int, int> rownum;
		map<int, int> colnum;
		for (auto &y : x.second) {
			rownum[y.first] = 0;
			colnum[y.second] = 0;
			jw[0][y.first].push_back(y.second);
			jw[1][y.second].push_back(y.first);
		}
		for (auto &y : x.second) {
			if (rownum[y.first]) continue;
			qs = qe = 0;
			quu[qe++] = mp(y.first, 0);
			rownum[y.first] = 1;
			int _M = 0;
			while (qs<qe) {
				auto z = quu[qs]; qs++;
				if (z.second == 0) {
					_M = max(_M, rowmax[z.first] + 1);
					for (auto &w : jw[0][z.first]) {
						if (colnum[w]) continue;
						quu[qe++] = mp(w, 1);
						colnum[w] = 1;
					}
				}
				else {
					_M = max(_M, colmax[z.first] + 1);
					for (auto &w : jw[1][z.first]) {
						if (rownum[w]) continue;
						quu[qe++] = mp(w, 0);
						rownum[w] = 1;
					}
				}
			}
			for (int i = 0; i < qe; i++) {
				if (quu[i].second == 0) {
					rows[quu[i].first][x.first] = _M;
					rowmax[quu[i].first] = _M;
				}
				else {
					colmax[quu[i].first] = _M;
				}
			}
		}
		for (auto &y : rownum) jw[0][y.first].clear();
		for (auto &y : colnum) jw[1][y.first].clear();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", rows[i][orig[i][j]]);
		}
		printf("\n");
	}
	return 0;
}
#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)
#define println(x) printf("%d\n", x)
#define print(x) printf("%d ", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 3000;
vector<int> adj[N];

int dist[N][N];
int vis[N];

int _M[N][3];
int _N[N][3];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	F(i, m) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	F(i, n) {
		memset(vis, 0, sizeof(vis));
		F(j, n) dist[i][j] = inf;
		queue<int> qq;
		dist[i][i] = 0;
		qq.push(i);
		vis[i] = 1;
		while (!qq.empty()) {
			auto x = qq.front(); qq.pop();
			for (auto &y : adj[x]) {
				if (vis[y]) continue;
				dist[i][y] = dist[i][x] + 1;
				qq.push(y);
				vis[y] = 1;
			}
		}
	}
	F(i, n) {
		F(k, 3) {
			_M[i][k] = _N[i][k] = -1;
		}
	}
	F(i, n) {
		F(j, n) {
			if (dist[i][j] < inf) {
				int& m1 = _M[i][0];
				int& m2 = _M[i][1];
				int& m3 = _M[i][2];
				if (m1 == -1) {
					m1 = j;
				}
				else if (dist[i][j] > dist[i][m1]) {
					m3 = m2;
					m2 = m1;
					m1 = j;
				}
				else if (m2 == -1) {
					m2 = j;
				}
				else if (dist[i][j] > dist[i][m2]) {
					m3 = m2;
					m2 = j;
				}
				else if (m3 == -1) {
					m3 = j;
				}
				else if (dist[i][j] > dist[i][m3]) {
					m3 = j;
				}
				
			}
		}
	}
	F(i, n) {
		F(j, n) {
			if (dist[j][i] < inf) {
				int& m1 = _N[i][0];
				int& m2 = _N[i][1];
				int& m3 = _N[i][2];
				if (m1 == -1) m1 = j;
				else if (dist[j][i] > dist[m1][i]) {
					m3 = m2;
					m2 = m1;
					m1 = j;
				}
				else if (m2 == -1) m2 = j;
				else if (dist[j][i] > dist[m2][i]) {
					m3 = m2;
					m2 = j;
				}
				else if (m3 == -1) m3 = j;
				else if (dist[j][i] > dist[m3][i]) {
					m3 = j;
				}
			}
		}
	}

	int MD = -1;
	tuple<int, int, int, int> tp;
	F(i, n) {
		F(j, n) {
			if (i == j) continue;
			if (dist[i][j] == inf) continue;
			for (int k = 0; k < 3; k++) {
				if (dist[_N[i][k]][i] == inf || _N[i][k] == j || _N[i][k] == i || _N[i][k] == -1) continue;
				for (int t = 0; t < 3; t++) {
					if (dist[j][_M[j][t]] == inf || _M[j][t] == i || _M[j][t] == _N[i][k] || _M[j][t] == j || _M[j][t] == -1) continue;
					int DD = dist[_N[i][k]][i] + dist[i][j] + dist[j][_M[j][t]];
					if (DD > MD) {
						MD = DD;
						tp = mtp(_N[i][k], i, j, _M[j][t]);
					}
				}
			}
		}
	}
	printf("%d %d %d %d", get<0>(tp) + 1, get<1>(tp) + 1, get<2>(tp) + 1, get<3>(tp) + 1);
	return 0;
}
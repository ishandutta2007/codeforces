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
#include <iterator>
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
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 3000;
vector<int> adj[N];
int q[N];
int qs, qe;
int dist[N][N];
int chk[N];

void bfs(int u,int* dist, int n) {
	qs = qe = 0;
	F(i, n)chk[i] = 0,dist[i]=inf;
	dist[u] = 0;
	chk[u] = 1;
	q[qe++] = u;
	while (qs < qe) {
		int u = q[qs++];
		for (auto &x : adj[u]) {
			if (!chk[x]) {
				dist[x] = dist[u] + 1;
				chk[x] = 1;
				q[qe++] = x;
			}
		}
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	F(i, m) {
		int u, v; nii(u, v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s1, t1, l1, s2, t2, l2;
	nii(s1, t1); nii(l1, s2); nii(t2, l2);
	s1--; t1--; s2--; t2--;
	F(i, n) {
		bfs(i, dist[i], n);
	}
	if (l1 < dist[s1][t1] || l2 < dist[s2][t2]) {
		puts("-1"); return 0;
	}
	int x = dist[s1][t1] + dist[s2][t2];
	F(i, n)F(j, n) {
		if (dist[i][s1] + dist[i][j] + dist[j][t1] > l1) continue;
		if (dist[i][s2] + dist[i][j] + dist[j][t2] <= l2) x = min(x, dist[i][s1] + dist[i][s2] + dist[i][j] + dist[j][t1] + dist[j][t2]);
		if (dist[i][t2] + dist[i][j] + dist[j][s2] <= l2) x = min(x, dist[i][s1] + dist[i][t2] + dist[i][j] + dist[j][t1] + dist[j][s2]);
	}
	printf("%d\n", m - x);
	return 0;
}
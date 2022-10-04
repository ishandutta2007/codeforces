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

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 1000;
const int M = 10000;
vector<int> adj[N];
struct Edge {
	int u, v;
	int w;
	Edge() {}
	Edge(int a,int b,int c):u(a),v(b),w(c){}
	int get(int _u) {
		return (u == _u) ? v : u;
	}
}el[M];
ll dist[N];
int chk[N];
void dijk(int u,int n,ll* d) {
	F(i, n) d[i] = infl;
	d[u] = 0;
	memset(chk, 0, sizeof(chk));
	priority_queue<pair<ll, int> > pq;
	pq.push(mp(0, u));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (chk[u])continue;
		chk[u] = 1;
		for (auto &i : adj[u]) {
			int v = el[i].get(u);
			if (d[v] > d[u] + el[i].w) {
				d[v] = d[u] + el[i].w;
				pq.push(make_pair(-d[v], v));
			}
		}
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m, L, s, t;
	nii(n, m); ni(L); nii(s, t);
	vector<int> era;
	F(i, m) {
		int u, v, w; nii(u, v); ni(w);
		el[i] = Edge(u, v, w);
		adj[u].push_back(i);
		adj[v].push_back(i);
		if (!w)era.push_back(i);
	}
	int sz = era.size();
	if (sz == 0) {
		dijk(s, n, dist);
		if (dist[t] != L) {
			puts("NO");
			return 0;
		}
		puts("YES");
		F(i, m) {
			printf("%d %d %d\n", el[i].u, el[i].v, el[i].w);
		}
		return 0;
	}
	ll low = sz; ll high = (ll)(L + 1)*sz;
	while (low != high) {
		ll mid = (low + high) / 2;
		ll rem = mid%sz;
		ll q = mid / sz;
		F(i, sz) {
			el[era[i]].w = (int)q;
		}
		F(i, rem) {
			el[era[i]].w++;
		}
		dijk(s, n, dist);
		if (dist[t] >= L)high = mid;
		else low = mid + 1;
	}
	F(i, sz) {
		el[era[i]].w = (int)(low / sz);
	}
	F(i, low%sz) {
		el[era[i]].w++;
	}
	dijk(s, n, dist);
	if (dist[t] != L) {
		puts("NO"); return 0;
	}
	puts("YES");
	F(i, m) {
		printf("%d %d %d\n", el[i].u, el[i].v, el[i].w);
	}
	return 0;
}
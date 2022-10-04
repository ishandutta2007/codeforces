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
const ll infll = 9000000000000000000LL;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int M = 101010;
const int N = 5010;

int stk[N];
int sp;
pair<pair<int, int>, double> in[N];
int a[M];

//graph
int par[N];
int val[N];
vector<pair<int, double> > adj[N];

int Max;
vector<double> dfs(int u) {
	vector<double> V(10001);
	int i = 0;
	if (val[u] + 5000 > Max)i = val[u] + 5000 - Max;
	for (; i <= 10000; i++)V[i] = 1;
	for (auto &p : adj[u]) {
		int v = p.first;
		vector<double> V2 = dfs(v);
		V2[10000] *= 1 - p.second;
		for (int i = 9999; i >= 0; i--) {
			V2[i + 1] += V2[i] * p.second;
			V2[i] *= 1 - p.second;
		}
		for (int i = 0; i <= 10000; i++)V[i] *= V2[i];
	}
	return V;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int m, n; nii(m, n);
	F(i, m)ni(a[i]);
	FF(i, n) {
		int l, r; double p;
		nii(l, r); l--; r--;
		scanf("%lf", &p);
		in[i] = mp(mp(l, -r), p);
	}
	sort(in + 1, in + 1 + n);
	par[0] = -1;
	val[0] = -inf;
	int cur = 0;
	int j = 1;
	F(i, m) {
		while (j <= n&&in[j].first.first == i) {
			stk[sp++] = j;
			adj[cur].emplace_back(j, in[j].second);
			par[j] = cur;
			cur = j;
			val[cur] = -inf;
			j++;
		}
		val[cur] = max(val[cur], a[i]);
		while (sp) {
			int t = stk[sp - 1];
			if (in[t].first.second == -i) {
				cur = par[cur];
				sp--;
			}
			else break;
		}
	}
	Max = *max_element(a, a + m);
	auto V = dfs(0);
	double ans = 0;
	for (int i = 5000; i <= 10000; i++) {
		ans += (V[i] - V[i - 1])*(Max - 5000 + i);
	}
	printf("%.15f\n", ans);
	return 0;
}
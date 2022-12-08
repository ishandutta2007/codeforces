#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <random>
#include <cassert>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "queuemin2"

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

vector<int> G[dd];
ll ans = 0;
int k;

vector<pair<ll, int> > X[dd];

vector<pair<ll, int> > calc(int v, int p) {
	vector<pair<ll, int> > A = vector<pair<ll, int> >(k, { 0ll, 0 });
	A[0] = { 0ll, 1 };

	for (int to : G[v]) if (to != p) {
		auto Y = calc(to, v);

		for (int i = 1; i < k; ++i) {
			A[i + 1 == k ? 0 : i + 1].first += Y[i].first;
			A[i + 1 == k ? 0 : i + 1].second += Y[i].second;
		}
		A[k > 1].first += Y[0].first + Y[0].second;
		A[k > 1].second += Y[0].second;

	}

	for (int i = 0; i < k; ++i)
		ans += A[i].first;
	return X[v] = A;
}


vector<pair<ll, int> > dfs(int v, int p, vector<pair<ll, int> > Q) {
	vector<pair<ll, int> > A = vector<pair<ll, int> >(k, { 0ll, 0 });
	A[0] = { 0ll, 1 };

	for (int i = 1; i < k; ++i)
		ans += Q[i].first;
	ans += Q[0].first + Q[0].second;

	for (int to : G[v]) if (to != p) {
		auto Y = X[to];

		for (int i = 1; i < k; ++i) {
			A[i + 1 == k ? 0 : i + 1].first += Y[i].first;
			A[i + 1 == k ? 0 : i + 1].second += Y[i].second;
		}
		A[k > 1].first += Y[0].first + Y[0].second;
		A[k > 1].second += Y[0].second;

	}

	for (int i = 1; i < k; ++i) {
		A[i + 1 == k ? 0 : i + 1].first += Q[i].first;
		A[i + 1 == k ? 0 : i + 1].second += Q[i].second;
	}
	A[k > 1].first += Q[0].first + Q[0].second;
	A[k > 1].second += Q[0].second;

	for (int to : G[v]) if (to != p) {
		auto Y = X[to];
		for (int i = 1; i < k; ++i) {
			A[i + 1 == k ? 0 : i + 1].first -= Y[i].first;
			A[i + 1 == k ? 0 : i + 1].second -= Y[i].second;
		}
		A[k > 1].first -= Y[0].first + Y[0].second;
		A[k > 1].second -= Y[0].second;

		dfs(to, v, A);

		for (int i = 1; i < k; ++i) {
			A[i + 1 == k ? 0 : i + 1].first += Y[i].first;
			A[i + 1 == k ? 0 : i + 1].second += Y[i].second;
		}
		A[k > 1].first += Y[0].first + Y[0].second;
		A[k > 1].second += Y[0].second;
	}
	return A;
}
/*
vector<pair<ll, int> > dfs(int v, int p) {
vector<pair<ll, int> > A = vector<pair<ll, int> >(k, { 0ll, 0 });
A[0] = { 0ll, 1 };
for (int to : G[v]) if (to != p) {


auto Y = dfs(to, v);
for (int i = 1; i < k; ++i) {
A[i + 1 == k ? 0 : i + 1].first += Y[i].first;
A[i + 1 == k ? 0 : i + 1].second += Y[i].second;
}
A[1].first += Y[0].first + Y[0].second;
A[1].second += Y[0].second;
}
for (int i = 0; i < k; ++i)
ans += A[i].first;
return A;
}
*/
int solve() {
	int n;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	calc(0, -1);
	vector<pair<ll, int> > L(k, { 0ll, 0 });
	dfs(0, -1, L);
	printf("%I64d", ans / 2);
	return 0;
}
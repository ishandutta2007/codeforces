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

const int N = 100000;

vector<pair<int, char> > adj[N];
int chk[N];
int vis[N];
void dfs(int u, char zero, vector<int>& a) {
	a.push_back(u);
	vis[u] = 1;
	for (auto &x : adj[u]) {
		if (vis[x.first]) {
			if ((chk[x.first] ^ chk[u]) != (x.second != zero))  throw vector<int>({ -1 });
			continue;
		}
		chk[x.first] = chk[u] ^ (x.second != zero);
		dfs(x.first, zero, a);
	}
}

vector<int> solve(int n, char zero) {
	try {
		F(i, n)chk[i] = 0, vis[i] = 0;
		vector<int> k;
		F(i, n) {
			if (vis[i])continue;
			vector<int> a, b, c;
			dfs(i, zero, a);
			for (auto &x : a) {
				if (chk[x]) b.push_back(x);
				else c.push_back(x);
			}
			if (b.size() < c.size()) for (auto &x : b) k.push_back(x);
			else for (auto &x : c)k.push_back(x);
		}
		throw k;
	}
	catch (vector<int> V) {
		return V;
	}
	return vector<int>();
}

void printv(const vector<int>& V) {
	printf("%d\n", V.size());
	for (auto &x : V) printf("%d ", x + 1); puts("");
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	F(i, m) {
		int u, v; char c;
		scanf("%d %d %c", &u, &v, &c);
		u--; v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	vector<int> a, b;
	a = solve(n, 'R');
	b = solve(n, 'B');
	vector<int> impos = { -1 };
	if (a == impos) {
		if (b == impos) {
			puts("-1");
			return 0;
		}
		printv(b);
	}
	else if (b == impos) {
		printv(a);
	}
	else if (a.size() < b.size()) printv(a);
	else printv(b);
	return 0;
}
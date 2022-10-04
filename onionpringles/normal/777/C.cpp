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


vector<vector<int> > V;

int ans[100000];

pair<pii, int> q[100000];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	F(i, n) {
		V.push_back(vector<int>());
		F(j, m) {
			int x; ni(x);
			V.back().push_back(x);
		}
	}
	int Q; ni(Q);
	F(i, Q) {
		int l, r; nii(l, r); l--; r--;
		q[i] = mp(mp(r, l), i);

	}
	sort(q, q + Q);
	set<pii> sts;
	priority_queue<pair<int, pii> > pq;
	int L = 0;
	F(i, n) {
		F(j, m) {
			if (i == 0 || V[i - 1][j] > V[i][j]) {
				sts.insert(pii(i, j));
				int k;
				for (k = i; k < n; k++) {
					if (k == n - 1 || V[k +1][j]  <V[k][j])break;
				}
				pq.emplace(-k, pii(i, j));
			}
		}
		int x = sts.begin()->first;
		while (L < Q && q[L].first.first == i) {
			if (q[L].first.second >= x)ans[q[L].second] = 1;
			L++;
		}
		while (!pq.empty()) {
			auto P = pq.top();
			int K = -P.first;
			if (i == K) {
				pq.pop();
				sts.erase(P.second);
			}
			else break;
		}
	}
	F(i, Q) {
		if (ans[i])puts("Yes"); else puts("No");
	}
	return 0;
}
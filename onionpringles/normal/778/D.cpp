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

const int N = 51;
char a[N][N], b[N][N];
typedef char arr[N][N];
int n, m;

void conv(int i, int j, arr& a) {
	if (a[i][j] == 'U') {
		a[i][j] = 'L';
		a[i][j + 1] = 'R';
		a[i + 1][j] = 'L';
		a[i + 1][j + 1] = 'R';
	}
	else {

		a[i][j] = 'U';
		a[i][j + 1] = 'U';
		a[i + 1][j] = 'D';
		a[i + 1][j + 1] = 'D';
	}
}

void go(vector<pii>& V, int i, int l, int r, arr& a) {
	if (i == 0) return;
	if (l > r) return;
	vector<int> W;
	for (int j = l; j <= r; j++) {
		if (a[i][j] == 'D')W.push_back(j);
	}
	int sz = W.size();
	if (sz == 0)return;
	F(k, sz - 1) {
		go(V, i - 1, W[k] + 1, W[k + 1] - 1, a);
	}
	F(k, sz - 1) {
		int L = W[k] + 1;
		int R = W[k + 1] - 1;
		for (int j = L; j <= R; j += 2) {
			V.emplace_back(i - 1, j);
			conv(i - 1, j, a);
		}
	}
	for (int j = W[0]; j <= W[sz - 1]; j += 2) {
		V.emplace_back(i - 1, j);
		conv(i - 1, j, a);
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	nii(n, m);
	bool sw = false;
	F(i, n) {
		scanf("%s", a[i]);
	}
	F(i, n)scanf("%s", b[i]);
	if (m & 1) {
		sw = true;
		swap(n, m);
		int M = max(m, n);
		F(i, M)F(j, i) {
			swap(a[i][j], a[j][i]);
			swap(b[i][j], b[j][i]);
		}
		F(i, n)F(j, m) {
			if (a[i][j] == 'L') a[i][j] = 'U';
			else if (a[i][j] == 'R') a[i][j] = 'D';
			else if (a[i][j] == 'U') a[i][j] = 'L';
			else a[i][j] = 'R';
			if (b[i][j] == 'L') b[i][j] = 'U';
			else if (b[i][j] == 'R') b[i][j] = 'D';
			else if (b[i][j] == 'U') b[i][j] = 'L';
			else b[i][j] = 'R';
		}
	}
	vector<pii> A, B;
	for (int i = n - 1; i >= 0; i--)go(A, i, 0, m - 1, a);
	for (int i = n - 1; i >= 0; i--)go(B, i, 0, m - 1, b);
	printf("%d\n", A.size() + B.size());
	for (auto &x : A) {
		if (sw)printf("%d %d\n", x.second + 1, x.first + 1);
		else printf("%d %d\n", x.first + 1, x.second + 1);
	}
	int sz = B.size();
	for (int i = sz - 1; i >= 0; i--) {
		auto x = B[i];
		if (sw)printf("%d %d\n", x.second + 1, x.first + 1);
		else printf("%d %d\n", x.first + 1, x.second + 1);
	}
	return 0;
}
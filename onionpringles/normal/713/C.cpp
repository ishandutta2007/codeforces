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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 3010;
int A[N];
int B[N];
ll D[N][N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	F(i, n) ni(A[i]);
	F(i, n) A[i] -= i;
	F(i, n) B[i] = A[i];
	sort(B, B + n);
	D[0][0] = abs(A[0] - B[0]);
	FF(j, n - 1) D[0][j] = min(abs(0LL + A[0] - B[j]), D[0][j - 1]);
	FF(i, n - 1)F(j,n) {
		if (!j) {
			D[i][j] = abs(A[i] - B[0]) + D[i - 1][0];
		}
		else {
			D[i][j] = min(D[i][j - 1], D[i - 1][j] + abs(A[i] - B[j]));
		}
	}
	printf("%lld\n", D[n - 1][n - 1]);
	return 0;
}
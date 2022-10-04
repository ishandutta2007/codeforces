#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <iomanip>
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

typedef long double ld;
const ld eps = 1e-16;

ld solve_quad(ld a, ld b, ld c) {
	if (a<0) {
		a = -a;
		b = -b;
		c = -c;
	}
	ld disc = b*b - 4 * a*c;
	disc = sqrt(disc + eps);
	if (-b - disc<0) return (-b + disc) / a / 2;
	else return (-b - disc) / a / 2;
}

const int N = 100000;

ld M[N];
ld m[N];

ld SP[N + 1];
ld SQ[N + 1];
ld SM[N + 1];
ld Sm[N + 1];
ld p[N]; ld q[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(8);
	int n; cin >> n;
	F(i, n) {
		cin >> M[i];
	}
	F(i, n) cin >> m[i];
	SM[0] = Sm[0] = SP[0] = SQ[0] = 0;
	F(i, n) {
		SM[i + 1] = SM[i] + M[i]; Sm[i + 1] = Sm[i] + m[i];
	}
	FF(i, n) {
		ld prod = SM[i];
		ld sum = prod + Sm[i];
		ld x = solve_quad(1, -sum, prod);
		ld y = sum - x;
		SP[i] = max(x, y);
		SQ[i] = min(x, y);
	}
	F(i, n) {
		p[i] = SP[i + 1] - SP[i];
		q[i] = SQ[i + 1] - SQ[i];
	}
	F(i, n) cout << p[i] << " ";
	cout << "\n";
	F(i, n) cout << q[i] << " ";
}
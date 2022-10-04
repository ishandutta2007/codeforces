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

const int N = 20;
double p[N];
double D[1 << N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k; nii(n, k);
	F(i, n) {
		scanf("%lf", p + i);
	}
	F(i, (1 << n)) {
		if (i == 0) {
			D[i] = 1;
			continue;
		}
		double P = 0;
		F(j, n) if (i&(1 << j)) P += p[j];
		D[i] = 0;
		F(j, n) {
			if (i&(1 << j)) D[i] += p[j]*D[i ^ (1 << j)];
		}
		D[i] = D[i] / (1 - P);
	}
	F(i, n) {
		double SA = 0;
		if (p[i] < 0.001) {
			printf("%.15f\n", 0.0); continue;
		}
		F(j, (1 << n)) {
			if (j&(1 << i)) continue;
			int cnt = 0;
			double ps = 0;
			F(k, n) {
				if (j&(1 << k)) {
					ps += p[k];
					cnt++;
				}
			}
			if (cnt != k - 1) continue;
			double prs = 1 - ps - p[i];
			SA += prs * D[j];
		}
		SA *= p[i];
	//	printf("SA: %.15f\n", SA);
		printf("%.15f\n", 1 - SA / p[i]);
	}

	return 0;
}
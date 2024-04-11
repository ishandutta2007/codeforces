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
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

set<vector<int> > S;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	int p1 = 0;
	int p2 = 0;
	for (int i = 1; i < n; i*=7) {
		p1++;
	}
	for (int i = 1; i < m; i *= 7) {
		p2++;
	}
	if (!p1)p1++;
	if (!p2)p2++;
	if (p1 + p2 >= 8) {
	
		puts("0");
		return 0;
	}
	
	
	vector<int> P;
	F(i, 7) P.push_back(i);
	int cnt = 0;
	do {
		vector<int> V = P;
		V.resize(p1 + p2);
		if (S.find(V) != S.end()) continue;
		S.insert(V);
		int x = 0;
		F(i, p1) {
			x *= 7;
			x += V[i];
		}
		int y = 0;
		F(j, p2) {
			y *= 7;
			y += V[p1 + j];
		}
		if (x < n && y < m) cnt++;
	} while (next_permutation(P.begin(), P.end()));
	printf("%d\n", cnt);
	return 0;
}
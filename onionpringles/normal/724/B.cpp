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
int a[20][20];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	F(i, n)F(j, m) {
		ni(a[i][j]);
		a[i][j]--;
	}
	vector<pii> V[20];
	F(i, n) {
		int cnt = 0;
		int cnt2 = 0;
		F(j, m) {
			if (a[i][j] != j) {
				cnt++;
				if (a[i][a[i][j]] == j) {
					cnt2++;
					if (j < a[i][j]) {
						V[i].emplace_back(j, a[i][j]);
					}
				}
				else {
					V[i].emplace_back(min(j, a[i][j]), max(j, a[i][j]));
				}
			}
		}
		if (cnt > 4 || cnt == 4 && cnt2 == 0) {
			puts("NO"); return 0;
		}
	}
	bool good = true;
	F(i, n) {
		if (V[i].size() > 1)good = false;
	}
	if (good) {
		puts("YES"); return 0;
	}
	F(i,m){
		F(j,i){
			bool fnd = true;
			auto p = make_pair(j,i);
			F(i, n) {
				if (find(V[i].begin(), V[i].end(), p) == V[i].end()) {
					if(!V[i].empty()){
						fnd = false;
						break;
					}
				}
			}
			if (fnd) {
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");

	return 0;
}
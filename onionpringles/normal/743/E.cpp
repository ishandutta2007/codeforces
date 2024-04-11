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
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 1000;
int a[N];
vector<int> v[8];
int p[8][N];
int e[N];
int D[N][1 << 8];
int n;

void fill(int mid) {
	if (mid == 0) {
		D[n - 1][0xff] = 0;
		F(i, 8)D[n - 1][0xff] += !v[i].empty();
		return;
	}
	F(i, n) {
		F(j, 1 << 8) {
			if (j == 0xff) {
				int a = 2;
			}
			if (j == 0) {
				D[i][j] = 0;
				continue;
			}
			D[i][j] = -1;
			F(k, 8) {
				if (!(j&(1 << k)))continue;
				int mk = j ^ (1 << k);
				int lst = p[k][i];
				if (lst == -1)continue;
				int ind = e[lst] + 1;
				if (ind < mid) {
					continue;
				}
				else if (ind == mid) {
					int bf = v[k][0] - 1;
					if (bf == -1 && mk > 0) {
						continue;
					}
					else if (bf == -1) {
						D[i][j] = max(D[i][j], mid);
					}
					else {
						if (D[bf][mk] == -1)continue;
						D[i][j] = max(D[bf][mk] + mid, D[i][j]);
					}
				}
				else {
					if (ind - mid  < (int)v[k].size()) {
						int bf = v[k][ind - mid] - 1;
						if (D[bf][mk] != -1)
							D[i][j] = max(D[i][j], D[bf][mk] + mid);
					}
					int bf = v[a[lst]][ind - mid - 1] - 1;
					if (bf == -1 && mk > 0) {
						continue;
					}
					else if (bf == -1) {
						D[i][j] = max(D[i][j], mid + 1);
					}
					else {
						if (D[bf][mk] == -1)continue;
						D[i][j] = max(D[bf][mk] + mid+ 1, D[i][j]);
					}
				}
			}
		}
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	ni(n);
	F(i, n)ni(a[i]);
	F(i, n) {
		e[i] = v[a[i] - 1].size();
		v[--a[i]].push_back(i);
	}
	F(j, 8) {
		int cur = -1;
		F(i, n) {
			if (a[i] == j) {
				cur = i;
			}
			p[j][i] = cur;
		}
	}
	int low = 0;
	int high = 126;
	int ans = 0;
	while (low != high) {
		int mid = (low + high) / 2;
		fill(mid);
		if (D[n - 1][0xff] == -1) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	fill(low - 1);
	printf("%d\n", D[n-1][0xff]);
}
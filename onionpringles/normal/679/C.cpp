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

const int N = 500;
const int M = 500 * 500;

int par[M];
int cnt[M];
int n, k;
int badn[M];
int chk[M];

inline int getind(int i, int j) {
	return n*i + j;
}
int find(int i) {
	if (par[i] == i) return i;
	else return par[i] = find(par[i]);
}
void merge(int i, int j) {
	i = find(i); j = find(j);
	if (i == j) return;
	if (cnt[i] > cnt[j]) swap(i, j);
	par[i] = j;
	cnt[j] += cnt[i];
}

char buf[N + 1];
int bd[N + 1][N + 1];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int _ans = -1;
	nii(n, k);
	F(i, n) {
		scanf("%s", buf);
		F(j, n) {
			bd[i][j] = (buf[j] == '.');
		}
	}
	F(i, n*n) par[i] = i, cnt[i] = 1;
	F(i, n) {
		F(j, n) {
			if (bd[i][j]) {
				if (i && bd[i - 1][j])  merge(getind(i, j), getind(i - 1, j));
				if (j && bd[i][j - 1]) merge(getind(i, j), getind(i, j - 1));
			}
		}
	}
	F(v, n - k + 1) {
		F(i, M) badn[i] = 0;
		F(i, k) {
			F(j, k) {
				if(bd[v+i][j]) badn[find(getind(v + i, j))]++;
			}
		}
		F(h, n - k + 1) {
			vector<int> chkd;
			int nt = 0;
			if (v) {
				F(j, k) {
					if (!bd[v - 1][h + j]) continue;
					int p = find(getind(v - 1, h + j));
					if (chk[p]) continue;
					chk[p] = 1;
					chkd.push_back(p);
					nt += cnt[p] - badn[p];
				}
			}
			if (v+k < n ) {
				F(j, k) {
					if (!bd[v + k][h + j]) continue;
					int p = find(getind(v + k, h + j));
					if (chk[p]) continue;
					chk[p] = 1;
					chkd.push_back(p);
					nt += cnt[p] - badn[p];
				}
			}
			if (h) {
				F(i, k) {
					if (!bd[v + i][h - 1]) continue;
					int  p = find(getind(v + i, h - 1));
					if (chk[p]) continue;
					chk[p] = 1;
					chkd.push_back(p);
					nt += cnt[p] - badn[p];
				}
			}
			if (h +k< n - 1) {
				F(i, k) {
					if (!bd[v + i][h + k]) continue;
					int p = find(getind(v + i, h + k));
					if (chk[p]) continue;
					chk[p] = 1;
					chkd.push_back(p);
					nt += cnt[p] - badn[p];
				}
			}
			for (auto &x : chkd) chk[x] = 0;
			_ans = max(_ans, nt);
		//	printf("%d %d %d\n", v, h, nt);
			//change
			if (h < n - k) {
				F(i,k) {
					int p;
					if (bd[v + i][h]) {
						p = find(getind(v + i, h));
						badn[p]--;
					}
					if (bd[v + i][h + k]) {
						p = find(getind(v + i, h + k));
						badn[p]++;
					}
				}
			}
		}
	}
	printf("%d\n", _ans + k*k);
	return 0;
	
}
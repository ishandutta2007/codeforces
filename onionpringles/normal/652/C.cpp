#pragma warning(disable:4996)

#include <stdio.h>
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
#include <random>
#include <time.h>
#include <tuple>
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
#define print(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 300000;


int ilog[N + 1];
int rmq[N][19];
int ind[N];
int p[N];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	nii(n, m);
	F(i, n) {
		ni(p[i]);
		p[i]--;
		ind[p[i]] = i;
		rmq[i][0] = inf;
	}
	F(i, m) {
		int x, y;
		nii(x, y);
		x--; y--;
		if (ind[y] < ind[x]) swap(x, y);
		rmq[ind[x]][0] = min(rmq[ind[x]][0], ind[y]);
	}
	FF(i, 18) {
		F(j, n) {
			if (j + (1 << (i - 1)) >= n) {
				rmq[j][i] = rmq[j][i - 1];
			}
			else {
				int a = j + (1 << (i - 1));
				rmq[j][i] = min(rmq[j][i - 1], rmq[a][i - 1]);
			}
		}
	}
	int il = 0;
	FF(i, n) {
		if (i < (1 << (il + 1))) ilog[i] = il;
		else ilog[i] = ++il;
	}
	ll ans = 0;
	F(i, n) {
		int low = i; int high = n;
		while (low != high) {
			int mid = (low + high) / 2;
			int il = ilog[mid - i + 1];
			int val = min(rmq[i][il], rmq[mid - (1 << il) + 1][il]);
			if (val <= mid) high = mid;
			else low = mid + 1;
		}
		ans += (high - i);
	}
	printf("%I64d", ans);
	return 0;
}
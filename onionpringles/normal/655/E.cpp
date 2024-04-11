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
#define F_(i,n) for(int i = 1; i <= (n); i++)
#define println(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//


char buf[2000010];
int dyn[2000010];
int dyn2[2000010];
int pos[26];
int srt[26];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k; nii(n, k);
	scanf("%s", buf);
	int m = strlen(buf);
	F(i, k) pos[i] = -1;
	F(i, m) {
		pos[buf[i] - 'a'] = i;
	}
	F(i, k)srt[i] = i;
	sort(srt, srt + k, [&](int x, int y) {
		return pos[x] < pos[y];
	});
	int j = 0;
	F(i, n) {
		buf[m + i] = srt[j] + 'a';
		j++; if (j == k) j = 0;
	}
	F(i, k) pos[i] = -1;
	dyn[0] = 1;
	dyn2[0] = 2;
	pos[buf[0]-'a'] = 0;
	F_(i, m + n - 1) {
		int u = buf[i] - 'a';
		if (pos[u] == -1) {
			dyn[i] = dyn2[i - 1];
		}
		else if (pos[u] == 0) {
			dyn[i] = dyn2[i - 1] - 1;
		}
		else {
			dyn[i] = dyn2[i - 1] - dyn2[pos[u] - 1];
		}
		if (dyn[i] < 0) dyn[i] += mod;
		dyn2[i] = dyn[i] + dyn2[i - 1];
		if (dyn2[i] >= mod ) dyn2[i] -= mod;
		pos[u] = i;
	}
	println(dyn2[m + n - 1]);
	return 0;
}
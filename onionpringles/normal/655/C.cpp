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
#define println(x) printf("%d\n", x);

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

char buf[100001];

int n, k;
int rms[100000];
int ps[100000];

int get(int l, int r) {
	l = max(l, 0);
	r = min(r, n - 1);
	if (l > r) return 0;
	if (!l) return ps[r];
	else return ps[r] - ps[l - 1];
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	nii(n, k);
	scanf("%s", buf);
	F(i,n) rms[i] = (buf[i] - '0')^1;
	ps[0] = rms[0];
	for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + rms[i];
	int low = 0; int high = 100000;
	while (low != high) {
		int mid = (low + high) / 2;
		int good = 0;
		F(i,n) {
			if (!rms[i]) continue;
			if (get(i - mid, i + mid) >= k + 1) {
				good = 1;
				break;
			}
		}
		if (good) high = mid;
		else low = mid + 1;
	}
	println(high);
	return 0;
}
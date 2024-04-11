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

const int N = 300000;

char buf[2][2][3];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < 2; i++) scanf("%s %s", buf[i][0], buf[i][1]);
	int aa[2][3];
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		int j = 0;
		if (buf[i][0][0] != 'X') aa[i][j++] = buf[i][0][0] - 'A';
		if (buf[i][0][1] != 'X') aa[i][j++] = buf[i][0][1] - 'A';
		if (buf[i][1][1] != 'X') aa[i][j++] = buf[i][1][1] - 'A';
		if (buf[i][1][0] != 'X') aa[i][j++] = buf[i][1][0] - 'A';
		int cnt = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = j + 1; k < 3; k++) {
				if (aa[i][j] > aa[i][k])  cnt++;
			}
		}
		ans ^= (cnt % 2);
	}
	if (ans) {
		puts("NO");

	}
	else { puts("YES"); }
	
	
	return 0;
}
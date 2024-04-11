#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MN = 500000;

ll pref[MN + 1];
ll suff[MN + 1];

ll pref2[MN + 1];
ll suff2[MN + 1];

int p[MN];
char buf[MN + 1];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	for (int i = 0; i < n; i++) ni(p[i]);
	scanf("%s", buf);
	pref[0] = 0;
	for (int i = 0; i < n; i++) {
		pref[i + 1] = pref[i];
		pref2[i + 1] = pref2[i];
		if (buf[i] == 'A') {
			pref[i + 1] += p[i];
		}
		else {
			pref2[i + 1] += p[i];
		}
	}
	suff[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		suff[i] = suff[i + 1];
		suff2[i] = suff2[i + 1];
		if (buf[i] == 'B') {
			suff[i] += p[i];
		}
		else {
			suff2[i] += p[i];
		}
	}
	ll _M = -1;
	for (int i = 0; i <= n; i++) {
		_M = max(_M, pref[i] + suff[i]);
		_M = max(_M, pref2[i] + suff2[i]);
	}
	printf("%I64d", _M);
	return 0;
}
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

const char half[] = "half";

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, p; nii(n, p);
	char buf[10]; int cnt = 0;
	ll ans = 0;
	ll hh = 1;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		if (strcmp(buf, half) != 0) {
			cnt++;
			ans += hh;
		}
		hh *= 2;
	}
	printf("%I64d", p*ans - p / 2 * cnt);

	return 0;
}
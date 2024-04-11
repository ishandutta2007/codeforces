#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(n), &(m))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x;
	ni(x);
	int ans = 0;
	for (int i = 5; i >= 1; i--) {
		ans += (x / i);
		x %= i;
	}
	printf("%d", ans);

	return 0;
}
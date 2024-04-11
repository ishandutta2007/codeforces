#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int  x1, y1, x2, y2;
	nii(x1, y1); nii(x2, y2);
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	printf("%d", max(dx, dy));
	return 0;
}
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

int disp[10] = { 6,2,5,5,4,5,6,3,7,6 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	nii(a, b);
	int ans = 0;
	for (int i = a; i <= b; i++) {
		int tmp = i;
		while (tmp) {
			ans += disp[tmp % 10];
			tmp /= 10;
		}
	}
	printf("%d", ans);
	return 0;
}
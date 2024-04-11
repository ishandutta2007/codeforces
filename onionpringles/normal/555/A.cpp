#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

#define ni(n) scanf("%d", &(n))
#define mp make_pair
#ifndef __GNUG__
#define __INT_MAX__ 2147483647
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int buf[100000];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int mi; ni(mi);
		for (int j = 0; j < mi; j++) {
			scanf("%d", buf + j);
		}
		if (buf[0] == 1) {
			for (int j = 1; j < mi; j++) {
				if (buf[j] == buf[j - 1] + 1) n--;
				else break;
			}
		}

	}
	printf("%d", 2 * n - k - 1);
	return 0;
}
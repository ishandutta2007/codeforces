//#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>
#include <unordered_map>

using namespace std;

const int maxn = 5010;
int v[maxn];
map <int, int> m;

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		for (int j = 0; j <= k; j++) {
			if (!m.count(v[i] * j)) {
				m[v[i] * j] = j;
			} else {
				m[v[i] * j] = min(m[v[i] * j], j);
			}
		}
	}

	int q;

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		int x;

		scanf("%d", &x);

		int ans = 1000;

		for (int j = 0; j < n; j++) {
			for (int t = 0; t <= k; t++) {
				int y = x - t * v[j];

				if (m.count(y)) {
					ans = min(ans, t + m[y]);
				}
			}
		}

		if (ans <= k) {
			printf("%d\n", ans);
		} else {
			printf("-1\n");
		}
	}

	return 0;
}
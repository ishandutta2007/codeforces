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

const int maxn = (int)1e5 + 10;

int v[maxn];
int d[maxn];
int r[maxn];
bool can[maxn];
bool ans[maxn];

int main() {
	int t;

	scanf("%d", &t);

	while (t != 0) {
		t--;
		int n, m;

		scanf("%d %d", &m, &n);

		for (int i = 1; i <= n; i++) {
			can[i] = true;
			ans[i] = false;
			scanf("%d", &v[i]);
		}

		m--;

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &d[i], &r[i]);
		}

		int cnt = 0;
		bool st = false;

		for (int i = 0; i < m; i++) {
			if (!st) {
				if (r[i] == 0) {
					if (d[i] == 0) {
						cnt++;
					} else {
						v[d[i]]--;
					}
				} else {
					for (int j = 1; j <= n; j++) {
						if (v[j] > cnt) {
							can[j] = false;
						}
					}
					st = true;
					if (d[i] == 0) {
						cnt++;
					} else {
						v[d[i]]--;
						can[d[i]] = false;
					}
				}
			} else {
				if (d[i] == 0) {
					cnt++;
				} else {
					v[d[i]]--;
					can[d[i]] = false;
				}
			}
		}

		if (st) {
			int count = (int)1e9;

			for (int i = 1; i <= n; i++) {
				if (can[i]) {
					count = min(count, v[i]);
					ans[i] = true;
				}
			}

			cnt -= count;
		}

		for (int i = 1; i <= n; i++) {
			if (!ans[i]) {
				if (cnt >= v[i]) {
					ans[i] = true;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (ans[i]) {
				printf("Y");
			} else {
				printf("N");
			}
		}

		printf("\n");
	}

	return 0;
}
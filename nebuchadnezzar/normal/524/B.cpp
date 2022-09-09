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

const int maxn = 1010;

int w[maxn];
int h[maxn];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w[i], &h[i]);
	}

	int ans = (int)2e9;

	for (int i = 1000; i >= 1; i--) {
		int now = 0;

		bool st = true;

		for (int j = 0; j < n; j++) {
			if (w[j] > i && h[j] > i) {
				st = false;
				break;
			}

			if (w[j] > i) {
				now += w[j];
			} else if (h[j] > i) {
				now += h[j];
			} else {
				now += min(w[j], h[j]);
			}
		}

		if (!st) {
			continue;
		}

		ans = min(ans, now * i);
	}

	cout << ans << endl;

	return 0;
}
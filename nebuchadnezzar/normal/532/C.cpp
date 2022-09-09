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

using namespace std;

int main() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if (a < c) {
		int x = d - c + a;

		if (x >= 0 && abs(b - x) <= abs(d - x)) {
			printf("Polycarp");
			return 0;
		}
	}

	if (b < d) {
		int x = c - d + b;

		if (x >= 0 && abs(a - x) <= abs(c - x)) {
			printf("Polycarp");
			return 0;
		}
	}

	if (a + b <= max(c, d)) {
		printf("Polycarp");
		return 0;
	}

	printf("Vasiliy");

	return 0;
}
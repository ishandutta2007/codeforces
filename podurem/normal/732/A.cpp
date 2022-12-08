#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TASK "cinema"

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

const int dd = (int)1e5 + 7;
const int INF = (int)1e9 + 7;

int main() {
	int k, r;
	scanf("%d%d", &k, &r);
	for (int i = 1; i <= 10; ++i) {
		int t = i * k;
		if (t % 10 == 0 || t % 10 == r) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
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
#define TASK "twopaths"

const ll dd = (ll)2e5 + 7;
const int INF = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

map<ll, int> M;

int main() {
	file();
	int t;
	scanf("%d", &t);
	while (t--) {
		char c;
		scanf("\n%c", &c);
		ll g = 0, x, k = 1;
		scanf("%I64d", &x);
		while (x > 0) {
			g += (x % 2) * k;
			k *= 10;
			x /= 10;
		}
		if (c == '+') {
			++M[g];
		}
		if (c == '-') {
			--M[g];
		}
		if (c == '?') {
			printf("%d\n", M[g]);
		}
	}
	return 0;
}
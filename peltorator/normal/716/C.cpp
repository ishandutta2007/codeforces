#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

int main() {
	ll x;

	x = 2;

	ll n;

	cin >> n;

	for (ll i = 1; i <= n; i++) {
		ll y = (x / i);

		if (y >= i * (i + 1) * (i + 1)) {
			throw 1;
		}

		printf("%I64d\n", i * (i + 1) * (i + 1) - y);

		x = i * (i + 1);
	}

	return 0;
}
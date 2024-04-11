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

const int dd = (int)5e2 + 7;
const int INF = (int)1e9 + 7;

inline ll maz(ll a, ll b, ll c) {
	return max(a, max(b, c));
}

int main() {
	file();
	ll a, b, c;
	cin >> a >> b >> c;
	ll k = maz(a, b, c);
	ll ans = k - a + k - b + k - c;
	k = maz(a + 1, b, c);
	ans = min(ans, k - a - 1 + k - b + k - c);
	k = maz(a + 1, b + 1, c);
	ans = min(ans, k - a - 1 + k - b - 1 + k - c);

	k = maz(a, b, c + 1);
	ans = min(ans, k - a + k - b + k - c - 1);
	k = maz(a, b + 1, c + 1);
	ans = min(ans, k - a + k - b - 1 + k - c - 1);

	k = maz(b, a + 1, c + 1);
	ans = min(ans, k - b + k - a - 1 + k - c - 1);

	k = maz(b + 1, a, c);
	ans = min(ans, k - b - 1 + k - a + k - c);
	cout << ans;
	return 0;
}
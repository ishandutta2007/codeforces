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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forq(i, q, n) for (int i = int(q); i < int(q); ++i)
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"
#define X first
#define Y second

const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e12 + 7;
const int MOD = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int main() {
	file();
	int n, k;
	scanf("%d%d", &n, &k);
	vector<ll> C(n);
	ll sum = 0;
	ll ans = 0;
	forn(i, n) {
		scanf("%I64d", &C[i]);
		sum += C[i];
	}
	vector<bool> A(n);
	int x;
	ll sum1 = 0;
	forn(i, k) {
		scanf("%d", &x);
		--x;
		A[x] = 1;
		ans += 2 * (sum - C[x]) * C[x] - 2 * sum1 * C[x];
		sum1 += C[x];
	}
	forn(i, n) {
		int k = (i - 1 + n) % n;
		int j = (i + 1) % n;
		if (!A[i] && !A[k]) {
			ans += C[i] * C[k];
		}
		if (!A[i] && !A[j]) {
			ans += C[i] * C[j];
		}
	}
	printf("%I64d", ans / 2);
	return 0;
}
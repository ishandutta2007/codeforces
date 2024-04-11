#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
//#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define X first
#define Y second
#define TASK "source"

const int INF = (int)1e9 + 7;
const int MOD = (int)1e5 + 3;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-7;
const double PI = acos(-1.0);

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int main() {
	file();
	ll n, q, e;
	ll d = 0, x;
	ll kol1 = 0, kol2 = 0, kkk = 0;
	scanf("%lld%lld", &n, &q);
	forn(i, q) {
		scanf("%lld", &e);
		if (e == 2) {
			if ((d + kkk) & 1) {
				++kol1;
			}
			else {
				++kol2;
			}
			++kkk;
		}
		else {
			scanf("%lld", &x);
			d += x;
			if (d >= n) {
				d -= n;
			}
			if (d < 0) {
				d += n;
			}
		}
	}
	vi ans(n);
	forn(i, n) {
		if (i & 1) {
			ans[(i + kol1 - kol2 + d + 2 * q * n) % n] = i;
		}
		else {
			ans[(i - kol1 + kol2 + d + 2 * q * n) % n] = i;
		}
	}
	forn(i, n) {
		printf("%d ", ans[i] + 1);
	}
	return 0;
}
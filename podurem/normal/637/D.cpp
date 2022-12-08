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
#include <unordered_map>
#include <unordered_set>

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
#define TASK "triangles"

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-6;

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	vi a(n + 1);
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	a[n] = m + 1 + s;
	sort(all(a));
	++n;
	if (a[0] - 1 < s) {
		puts("IMPOSSIBLE");
		return 0;
	}
	vector <pii> otr;
	otr.psh(mk(0, a[0] - 1));
	forn(i, n - 1) {
		if (a[i + 1] - a[i] - 2 >= s) {
			otr.psh(mk(a[i] + 1, a[i + 1] - 1));
		}
	}
	forn(i, otr.size() - 1) {
		if (otr[i + 1].X - otr[i].Y > d) {
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	forn(i, otr.size() - 1) {
		printf("RUN %d\n", otr[i].Y - otr[i].X);
		printf("JUMP %d\n", otr[i + 1].X - otr[i].Y);
	}
	if (otr[otr.size() - 1].X != m) {
		printf("RUN %d\n", m - otr[otr.size() - 1].X);
	}
	return 0;
}
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair <short, short> pii;
typedef vector <int> vi;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forq(i, q, n) for (int i = (int)q; i < (int)n; ++i)
#define mk make_pair
#define psh push_back
#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define X first
#define Y second
#define TASK "donut"

const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e18 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-6;
const double PI = acos(-1.0);

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

vi kol;
int kol1, kol2;

bool ok(int x, int y) {
	kol = vi(7, 0);
	int kkk = 0;
	while (x > 0) {
		++kol[x % 7];
		++kkk;
		x /= 7;
	}
	forn(i, kol1 - kkk) {
		++kol[0];
	}
	kkk = 0;
	while (y > 0) {
		++kol[y % 7];
		++kkk;
		y /= 7;
	}
	forn(i, kol2 - kkk) {
		++kol[0];
	}
	forn(i, 7) {
		if (kol[i] > 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	file();
	ll n, m, x;
	cin >> n >> m;
	--n;
	--m;
	x = 6;
	kol1 = 1, kol2 = 1;
	while (x < n) {
		x *= 7;
		x += 6;
		++kol1;
	}
	x = 6;
	while (x < m) {
		x *= 7;
		x += 6;
		++kol2;
	}
	if (kol1 + kol2 > 7) {
		cout << 0;
		return 0;
	}
	int ans = 0;
	++n;
	++m;
	forn(i, n) {
		forn(j, m) {
			ans += ok(i, j);
		}
	}
	cout << ans;
	return 0;
}
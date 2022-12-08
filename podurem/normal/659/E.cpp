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
#define TASK "st2d"

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-6;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int kol, v;
bool used[MAXN];
vector <vi> G;

void dfs(int x) {
	used[x] = 1;
	v++;
	kol += G[x].size();
	forn(i, G[x].size()) {
		if (!used[G[x][i]]) {
			dfs(G[x][i]);
		}
	}
}

int main() {
	file();
	int n, m, x, y;
	cin >> n >> m;
	G.resize(n);
	forn(i, m) {
		cin >> x >> y;
		--x;
		--y;
		G[x].psh(y);
		G[y].psh(x);
	}
	int ans = 0;
	forn(i, n) {
		if (!used[i]) {
			kol = 0;
			v = 0;
			dfs(i);
			kol /= 2;
			ans += max(0, v - kol);
		}
	}
	cout << ans;
	return 0;
}
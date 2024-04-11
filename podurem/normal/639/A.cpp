
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STGCK:66777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornn(i, q, n) for (int i = q; i < (ll)n; i++)
#define mp make_pair
#define pk push_back
#define all(v) v.begin(), v.end()
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define prev ptrev

#define TASK "game"

const double EPS = 1e-10;
const double PI = acos(-1.0);

const int INF = (int)2e9 + 7;
const ll LINF = (ll)8e18;
const ll MM = (ll)1e9 + 7;
const int MAXN = (int)1e3 + 7;

int solve();
int main() {
#ifdef starcall
	srand(atoi("Korob, please die"));
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("test.txt", "w", stderr);
#endif
	solve();
	return 0;
}      

vector<int> G;
int solve() {
	int n, k, q;
	scanf("%d %d %d", &n, &k, &q);
	G.resize(n);
	forn(i, n) {
		scanf("%d", &G[i]);
	}
	set<pair<int, int> > S;
	while (q--) {
		int w, id;
		scanf("%d %d", &w, &id);
		if (w == 1) {
			S.insert(mp(G[id - 1], id - 1));
			if (k < S.size())
				S.erase(S.begin());
		}
		else {
			bool ok = false;
			for (auto it : S)
				if (it.second == id - 1) {
					ok = true;
				}
			puts(ok ? "YES" : "NO");
		}
	}

	return 0;

}
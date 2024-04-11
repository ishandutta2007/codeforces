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

#define TASK "field"

const double EPS = 1e-10;
const double PI = acos(-1.0);

const int INF = (int)2e9 + 7;
const ll LINF = (ll)8e18;
const ll MM = (ll)1e9 + 7;
const int MAXN = (int)1e5 + 7;
const int MAXC = (int)20;

int solve();
int main() {
#ifdef starcall

	srand(atoi("Korob, please die"));
	//srand(time(0));
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	G.resize(n);
	forn(i, n) {
		cin >> G[i];
	}
	set<ll> was;
	ll cur = 0;
	while (true) {
		was.insert(cur);
		if (s[cur] == '<') {
			cur -= G[cur];
		}
		else {
			cur += G[cur];
		}
		if (cur < 0 || cur >= n) {
			puts("FINITE");
			return 0;
		}
		if (was.count(cur)) {
			puts("INFINITE");
			return 0;
		}
	}

	return 0;
}
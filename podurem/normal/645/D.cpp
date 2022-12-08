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

vi top;
vector <vi> G;
vector <bool> used;

void dfs(int x) {
	used[x] = 1;
	forn(i, G[x].size()) {
		if (!used[G[x][i]]) {
			dfs(G[x][i]);
		}
	}
	top.psh(x);
}

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	G.resize(n);
	used.resize(n, 0);
	vector <pii> a(m);
	vi kol(n, 0);
	forn(i, m) {
		cin >> a[i].X >> a[i].Y;
		a[i].X--;
		a[i].Y--;
		G[a[i].X].psh(a[i].Y);
		kol[a[i].Y]++;
	}
	int v, min1 = INF;
	forn(i, n) {
		if (min1 > kol[i]) {
			min1 = kol[i];
			v = i;
		}
	}
	dfs(v);
	if (top.size() != n) {
		cout << -1;
		return 0;
	}
	forn(i, n) {
		kol[top[i]] = i;
	}
	int k = 0;
	forn(i, m) {
		if (abs(kol[a[i].X] - kol[a[i].Y]) == 1) {
			k++;
			if (k == n - 1) {
				cout << i + 1;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}
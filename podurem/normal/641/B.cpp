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
const int MAXN = (int)100 + 7;
const double EPS = (double)1e-7;
const double PI = acos(-1.0);

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

ll G[MAXN][MAXN];
vector<pair<int, int> > T;

int n, m, q;

int main() {
	file();
	cin >> n >> m >> q;
	forn(i, q) {
		int type;
		scanf("%d ", &type);
		if (type == 1) {
			int r;
			scanf("%d ", &r);
			r--;
			ll cop = G[r][0];
			forn(j, m - 1) {
				G[r][j] = G[r][j + 1];
			}
			G[r][m - 1] = cop;
			T.push_back(mk(1, r));
		}
		if (type == 2) {
			int r;
			scanf("%d ", &r);
			r--;
			ll cop = G[0][r];
			forn(j, n - 1) {
				G[j][r] = G[j + 1][r];
			}
			G[n - 1][r] = cop;
			T.push_back(mk(2, r));
		}
		if (type == 3) {
			int w, e, t;
			scanf("%d %d %d", &w, &e, &t);
			G[w - 1][e - 1] = t;
		}
	}
	reverse(T.begin(), T.end());
	forn(i, T.size()) {
		if (T[i].first == 1) {
			int v = T[i].second;
			ll cop = G[v][m - 1];
			for (int j = m - 1; j >= 1; j--) {
				G[v][j] = G[v][j - 1];
			}
			G[v][0] = cop;
		}
		else {
			int v = T[i].second;
			ll cop = G[n - 1][v];
			for (int j = n - 1; j >= 1; j--) {
				G[j][v] = G[j - 1][v];
			}
			G[0][v] = cop;
		}
	}
	forn(i, n) {
		forn(j, m) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
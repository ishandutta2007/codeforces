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
const int MAXN = (int)1e3 + 7;
const double EPS = (double)1e-6;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

bool comp(pair <int, string> a, pair <int, string> b) {
	return a.X >= b.X;
}

int main() {
	file();
	int n, m, r, k;
	scanf("%d%d", &n, &m);
	vector <vector <pair <int, string> > > A(m);
	string s;
	forn(i, n) {
		cin >> s >> r >> k;
		--r;
		A[r].psh(mk(k, s));
	}
	forn(i, m) {
		sort(all(A[i]), comp);
	}
	forn(i, m) {
		if (A[i].size() > 2) {
			if (A[i][1].X == A[i][2].X) {
				puts("?");
			}
			else {
				cout << A[i][0].Y << " " << A[i][1].Y << "\n";
			}
		}
		else {
			cout << A[i][0].Y << " " << A[i][1].Y << "\n";
		}
	}
	return 0;
}
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
#define TASK ""

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = 5 * (int)1e6 + 7;
const double EPS = (double)1e-7;

pii str[5007], sttol[5007];

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, t, x, y;
	scanf("%d%d", &n, &m);
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &t, &x, &y);
		x--;
		if (t == 1) {
			str[x] = mk(-q + MAXN, y);
		}
		else {
			sttol[x] = mk(-q + MAXN, y);
		}
	}
	forn(i, n) {
		forn(j, m) {
			printf("%d ", max(str[i], sttol[j]).Y);
		}
		printf("\n");
	}
	return 0;
}
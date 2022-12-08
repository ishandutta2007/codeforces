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
const double EPS = (double)1e-4;

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <string> a(n);
	forn(i, n) {
		cin >> a[i];
	}
	int ans = 6;
	forn(i, n - 1) {
		forq(j, i + 1, n) {
			int kol = 0;
			forn(k, 6) {
				if (a[i][k] == a[j][k]) {
					++kol;
				}
			}
			if (kol == 0) {
				ans = min(ans, 2);
			}
			if (kol == 1) {
				ans = min(ans, 2);
			}
			if (kol == 2) {
				ans = min(ans, 1);
			}
			if (kol == 3) {
				ans = min(ans, 1);
			}
			if (kol >= 4) {
				ans = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
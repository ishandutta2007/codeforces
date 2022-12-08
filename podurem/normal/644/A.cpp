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
	//("output.txt", "w", stdout);
	int k, n, m;
	cin >> k >> n >> m;
	if (n * m < k) {
		cout << -1;
		return 0;
	}
	vector <vi> ans(n, vi(m, 0));
	if (m & 1) {
		int k1 = 1;
		forn(i, n) {
			forn(j, m) {
				if (k1 <= k) {
					ans[i][j] = k1;
				}
				++k1;
			}
		}
	}
	else {
		int k1 = 1;
		for (int i = 0; i < n; i += 2) {
			forn(j, m) {
				if (k1 <= k) {
					ans[i][j] = k1;
				}
				++k1;
			}
		}
		for (int i = 1; i < n; i += 2) {
			forq(j, 1, m + 1) {
				if (k1 <= k) {
					ans[i][(j % m)] = k1;
				}
				++k1;
			}
		}
	}
	forn(i, n) {
		forn(j, m) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
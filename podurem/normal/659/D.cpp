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

int main() {
	file();
	int n;
	cin >> n;
	vector <pii> A(n + 1);
	forn(i, n + 1) {
		cin >> A[i].X >> A[i].Y;
	}
	int ans = 0;
	forn(i, n - 1) {
		if (A[i].X == A[i + 1].X) {
			if (A[i].Y < A[i + 1].Y) {
				if (A[i + 1].X > A[i + 2].X) {
					ans++;
				}
			}
			else {
				if (A[i + 1].X < A[i + 2].X) {
					ans++;
				}
			}
		}
		else {
			if (A[i].X < A[i + 1].X) {
				if (A[i + 1].Y < A[i + 2].Y) {
					ans++;
				}
			}
			else {
				if (A[i + 1].Y > A[i + 2].Y) {
					ans++;
				}
			}
		}
	}
	if (A[n - 1].X == A[0].X) {
		if (A[n - 1].Y < A[0].Y) {
			if (A[0].X > A[1].X) {
				ans++;
			}
		}
		else {
			if (A[0].X < A[1].X) {
				ans++;
			}
		}
	}
	else {
		if (A[n - 1].X < A[0].X) {
			if (A[0].Y < A[1].Y) {
				ans++;
			}
		}
		else {
			if (A[0].Y > A[1].Y) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
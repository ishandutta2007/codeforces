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
	//freopen("output.txt", "w", stdout);
	char a1, b1, c1, d1, a2, b2, c2, d2;
	cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
	string s1 = "A", s2 = "A";
	if (a1 == 'A') {
		if (b1 != 'X') {
			s1 += b1;
		}
		if (d1 != 'X') {
			s1 += d1;
		}
		if (c1 != 'X') {
			s1 += c1;
		}
	}
	if (b1 == 'A') {
		if (d1 != 'X') {
			s1 += d1;
		}
		if (c1 != 'X') {
			s1 += c1;
		}
		if (a1 != 'X') {
			s1 += a1;
		}
	}
	if (d1 == 'A') {
		if (c1 != 'X') {
			s1 += c1;
		}
		if (a1 != 'X') {
			s1 += a1;
		}
		if (b1 != 'X') {
			s1 += b1;
		}
	}
	if (c1 == 'A') {
		if (a1 != 'X') {
			s1 += a1;
		}
		if (b1 != 'X') {
			s1 += b1;
		}
		if (d1 != 'X') {
			s1 += d1;
		}
	}
	if (a2 == 'A') {
		if (b2 != 'X') {
			s2 += b2;
		}
		if (d2 != 'X') {
			s2 += d2;
		}
		if (c2 != 'X') {
			s2 += c2;
		}
	}
	if (b2 == 'A') {
		if (d2 != 'X') {
			s2 += d2;
		}
		if (c2 != 'X') {
			s2 += c2;
		}
		if (a2 != 'X') {
			s2 += a2;
		}
	}
	if (d2 == 'A') {
		if (c2 != 'X') {
			s2 += c2;
		}
		if (a2 != 'X') {
			s2 += a2;
		}
		if (b2 != 'X') {
			s2 += b2;
		}
	}
	if (c2 == 'A') {
		if (a2 != 'X') {
			s2 += a2;
		}
		if (b2 != 'X') {
			s2 += b2;
		}
		if (d2 != 'X') {
			s2 += d2;
		}
	}
	if (s1 == s2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
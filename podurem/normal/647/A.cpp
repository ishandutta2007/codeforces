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
#define TASK "shopping"

const int INF = (int)1e9 + 7;
const int MOD = (int)1e9 + 7;
const int MAXN = 5 * (int)1e4 + 7;

int main() {
	//freopen(TASK".dat", "r", stdin);
	//freopen(TASK".sol", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, kol = 0, ans = 0;
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &x);
		if (x >= 4) {
			kol++;
		}
		else {
			kol = 0;
		}
		if (kol == 3) {
			ans++;
			kol = 0;
		}
	}
	printf("%d", ans);
	return 0;
}
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
	int n, k;
	cin >> n >> k;
	int kol0 = 0, r = -1;
	vector <char> a(n);
	vi v0;
	forn(i, n) {
		cin >> a[i];
		if (a[i] == '0') {
			v0.psh(i);
		}
	}
	int ans = INF;
	forn(i, n) {
		while (kol0 < k + 1) {
			r++;
			if (r == n) {
				break;
			}
			if (a[r] == '0') {
				kol0++;
			}
		}
		if (r == n) {
			break;
		}
		//cout << i << " " << r << "\n";
		int it = lower_bound(all(v0), (i + r) / 2) - v0.begin();
		ans = min(max(r - v0[it], v0[it] - i), ans);
		if (it - 1 != -1) {
			it--;
			ans = min(max(r - v0[it], v0[it] - i), ans);
		}
		if (a[i] == '0') {
			kol0--;
		}
	}
	cout << ans;
	return 0;
}
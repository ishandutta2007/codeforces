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

int a[200007];

int main() {
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q, x, y;
	cin >> n >> q;
	forn(i, n) {
		cin >> a[i];
	}
	int siz = 0;
	vector <pii> s;
	while (q--) {
		cin >> x >> y;
		y = -y;
		auto it = lower_bound(s.begin(), s.begin() + siz, mk(y, 0));
		if (it == s.end()) {
			s.psh(mk(y, x));
			siz = s.size();
		}
		else {
			s[it - s.begin()] = mk(y, x);
			siz = it - s.begin() + 1;
		}
	}
	forn(i, siz) {
		s[i].X = -s[i].X;
	}
	vi ans(n);
	for (int i = s[0].X; i < n; ++i) {
		ans[i] = a[i];
	}
	multiset <int> ss;
	for (int i = s[0].X - 1; i >= 0; --i) {
		ss.insert(a[i]);
	}
	int r = 0;
	for (int i = s[0].X - 1; i >= 0; --i) {
		if (r != siz - 1) {
			if (i + 1 == s[r + 1].X) {
				++r;
			}
		}
		if (s[r].Y == 1) {
			ans[i] = *ss.rbegin();
			auto it = ss.end();
			it--;
			ss.erase(it);
		}
		else {
			ans[i] = *ss.begin();
			ss.erase(ss.begin());
		}
	}
	forn(i, n) {
		cout << ans[i] << " ";
	}
	return 0;
}
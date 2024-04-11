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
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
const int MAXN = (int)1e5 + 7;
const double EPS = (double)1e-7;
const double PI = acos(-1.0);

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

int main() {
	file();
	int n, t, x, v;
	scanf("%d", &n);
	map <int, vector <pair <pii, int> > > a;
	forn(i, n) {
		scanf("%d%d%d", &t, &v, &x);
		a[x].psh(mk(mk(v, t), i));
	}
	vi ans(n, -1);
	tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> s, dd;
	for (auto it = a.begin(); it != a.end(); it++) {
		vector <pair <pii, int> > b = it->Y;
		s.clear();
		dd.clear();
		forn(i, b.size()) {
            if (b[i].X.Y == 1) {
                s.insert(b[i].X.X);
            }
            else {
                if (b[i].X.Y == 2) {
                    dd.insert(b[i].X.X);
                }
                else {
                    ans[b[i].Y] = s.order_of_key(b[i].X.X) - dd.order_of_key(b[i].X.X);
                }
            }
		}
	}
	forn(i, n) {
        if (ans[i] != -1) {
            printf("%d\n", ans[i]);
        }
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, s, c[200002] = {};
int p1, p2;
int ans = 0;

int main() {
	fast;
	cin >> n >> s; --s;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		if (i == s && a != 0) a = 0, ans++;
		c[a]++;
	}

	p1 = 0, p2 = n - 1;
	while (c[0] > 1) {
		if (c[p1]) p1++;
		else c[0]--, c[p1]++, ans++;
	}
	while (p1 < p2) {
		if (c[p1]) ++p1;
		else if (!c[p2]) --p2;
		else {
			ans++;
			c[p1]++;
			c[p2]--;
		}
	}
	finish(ans);
}
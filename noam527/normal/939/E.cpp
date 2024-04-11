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

int q, p[2], nxt = 1;
ll s[500001], best = 1;
ldb ans = -9e18;

int main() {
	fast;
	cin >> q;
	cout.precision(7);
	s[0] = 0;
	while (q--) {
		cin >> p[0];
		if (p[0] == 1) {
			cin >> p[1];
			s[nxt] = p[1] + s[nxt - 1];
			while (best < nxt && s[best] + p[1] > (best + 1) * (s[best + 1] - s[best])) best++;
			ans = max(ans, p[1] - (s[best] + p[1]) / (ldb)(best + 1));
			nxt++;
		}
		else {
			cout << ans << endl;
		}
	}
}
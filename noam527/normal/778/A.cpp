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
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s, t;
int a[200000];

bool can(int x) {
	int p = 0;
	for (int i = 0; i < s.size(); i++) {
		if (a[i] >= x && s[i] == t[p]) {
			p++;
			if (p == t.size()) return true;
		}
	}
	return false;
}

int main() {
	fast;
	cin >> s >> t;
	for (int i = 0, v; i < s.size(); i++)
		cin >> v, a[v - 1] = i;

	int lo = 1, hi = s.size(), mid;
	while (lo < hi) {
		mid = lo + (hi - lo + 1) / 2;
		if (can(mid)) lo = mid;
		else hi = mid - 1;
	}
	if (lo == 1 && !can(1)) cout << 0 << endl;
	else cout << lo << endl;
}
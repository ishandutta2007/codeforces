#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

ll inter(ll la, ll ra, ll lb, ll rb) {
	return max(min(ra, rb) - max(la, lb) + 1, 0ll);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;
	ll g = __gcd(ta, tb);
	ll da = ra - la, db = rb - lb;
	la %= g;
	lb %= g;
	ll ans = inter(la, la + da, lb, lb + db);
	ans = max(ans, inter(la, la + da, lb + g, lb + g + db));
	ans = max(ans, inter(la + g, la + g + da, lb, lb + db));
	cout << ans;
}
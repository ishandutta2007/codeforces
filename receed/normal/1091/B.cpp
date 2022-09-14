#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int inf = 1e7, ma = inf, mb = inf, mx = -inf, my = -inf, a, b, n;
	cin >> n;
	rep(i, n) {
		cin >> a >> b;
		ma = min(ma, a);
		mb = min(mb, b);
	}
	rep(i, n) {
		cin >> a >> b;
		mx = max(mx, a);
		my = max(my, b);
	}
	cout << ma + mx << ' ' << mb + my;
}
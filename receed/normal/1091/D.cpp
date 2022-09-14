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

const ll MOD = 998244353;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, ans, f = 1;
	cin >> n;
	ans = n;
	for (int i = 1; i <= n; i++)
		ans = ans * i % MOD;
	for (int i = n; i >= 1; i--) {
		ans = (ans + MOD - f) % MOD;
		f = f * i % MOD;
	}
	ans = (ans + 1) % MOD;
	cout << ans;
}
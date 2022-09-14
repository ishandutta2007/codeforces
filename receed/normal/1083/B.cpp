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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (ll i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, ans = 0;
	string s, t;
	cin >> n >> k >> s >> t;
	ll r = 1;
	for (int i = 0; i < n; i++) {
		r *= 2;
		if (s[i] == 'b')
			r--;
		if (t[i] == 'a')
			r--;
		ans += min(r, k);
		r = min(r, (ll) 1e11);
	}	
	cout << ans;
}
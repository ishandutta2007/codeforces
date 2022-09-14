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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<ll> b(n, n);
	rep(i, n)
		for (int j = 1; j < 15; j++)
			if (i + 2 * j < n && s[i] == s[i + j] && s[i] == s[i + 2 * j]) {
				b[i] = i + 2 * j;
				break;				
			}
	ll cm = n;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		cm = min(cm, b[i]);
		ans += n - cm;
	}
	cout << ans;
}
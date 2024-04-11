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

const int N = 100001;
vector<int> g[N];
ll p[N], s[N], ns[N];
int n;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll ans;
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
	}
	rep(i, n)
		cin >> s[i];
	ans = s[0];
	rep(i, n) {
		if (s[i] != -1 && i != 0) {
			ns[i] = s[i] - s[p[p[i]]];
			if (ns[i] < 0) {
				cout << -1;
				return 0;
			}
			ans += ns[i];
		}
	}
	rep(i, n) {
		if (s[i] != -1 || g[i].empty())
			continue;
		ll mx = 1e9 + 2;
		for (int u : g[i])
			mx = min(mx, ns[u]);
		ans -= mx * ((int) g[i].size() - 1);
	}
	cout << ans;
}
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
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 100002;
int p[N], rc[N], ans[N];

int getp(int v) {
	if (v != p[v])
		p[v] = getp(p[v]);
	return p[v];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k, u, v, c;
	cin >> n >> m >> k;
	vector<int> q(k);
	rep(i, k) {
		cin >> q[i];
		rc[q[i]] = 1;
	}
	for (int i = 1; i <= n; i++)
		p[i] = i;	
	vector<vector<int>> e(m, vector<int>(3));
	rep(i, m)
		cin >> e[i][1] >> e[i][2] >> e[i][0];
	sort(e.begin(), e.end());
	int cn = n, ans;
	for (auto &pp : e) {
		u = getp(pp[1]);
		v = getp(pp[2]);
		if (u == v)
			continue;
		if (rc[u] + rc[v] == k) {
			ans = pp[0];
			break;
		}
		p[v] = u;
		rc[u] += rc[v];
	}
	rep(i, k)
		cout << ans << ' ';
}
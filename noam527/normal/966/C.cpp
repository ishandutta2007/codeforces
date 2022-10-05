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

int n;
vector<ll> a, b[64];
vector<ll> ans, newans;

int largestb(ll x) {
	if (x == 1) return 0;
	return 1 + largestb(x / 2);
}

bool can(ll x, ll y) {
//	cout << "xy: " << x << " " << y << " ";
	while (x != (x & -x)) x -= (x & -x);
//	cout << (y & x) << endl;
	if (y & x) return true;
	return false;
}

void updans(int x) {
	if (b[x].size() == 0) return;
//	cout << "x " << x << " sz " << b[x].size() << " by now " << ans.size() << endl;
//	cout << "x " << x << endl;
//	for (const auto &i : ans) cout << i << " "; cout << endl;
	newans.clear();
	int nxt = 0;
	ll xo = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (nxt < b[x].size() && !can(b[x][nxt], xo)) {
			newans.push_back(b[x][nxt]);
			xo ^= b[x][nxt];
			nxt++;
		}
		newans.push_back(ans[i]);
		xo ^= ans[i];
	}
	if (nxt == b[x].size() - 1 && !can(b[x][nxt], xo)) {
		newans.push_back(b[x][nxt]);
		xo ^= b[x][nxt];
		nxt++;
	}
	if (nxt != b[x].size()) {
		cout << "No" << endl;
		exit(0);
	}
	ans = newans;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, b[largestb(i)].push_back(i);
	for (int i = 63; i >= 0; i--) updans(i);
	cout << "Yes" << endl;
	for (const auto &i : ans) cout << i << " "; cout << endl;
}
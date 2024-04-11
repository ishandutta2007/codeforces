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
	ll n, k, ans = 0;
	cin >> n >> k;
	vector<pair<ll, ll>> a(n);
	rep(i, n)
		cin >> a[i].second >> a[i].first;
	sort(rall(a));
	multiset<ll> q;
	ll cs = 0;
	for (auto &p : a) {
		q.insert(p.second);
		cs += p.second;
		while (q.size() > k) {
			cs -= *q.begin();
			q.erase(q.begin());
		}
		ans = max(ans, cs * p.first);
	}
	cout << ans;
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<ll> a;
ll W;

void solve() {
	cin >> n;
	W = 0;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		W += i;
	}
	multiset<ll> aa;
	for (auto &i : a)
		aa.insert(i);
	multiset<ll> cur;
	cur.insert(W);
	while (cur.size()) {
		ll x = *cur.rbegin();
		cur.erase(cur.find(x));
		if (aa.count(x)) {
			aa.erase(aa.find(x));
		}
		else {
			if (x < *aa.rbegin()) {
				cout << "NO\n";
				return;
			}
			cur.insert(x / 2);
			cur.insert((x + 1) / 2);
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}
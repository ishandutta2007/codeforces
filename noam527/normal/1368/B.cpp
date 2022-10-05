#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll pw(ll b, ll e) {
	ll res = 1;
	while (e--) res *= b;
	return res;
}

ll prod(const vector<ll> a) {
	ll res = 1;
	for (const auto &i : a) res *= i;
	return res;
}

const string S = "codeforces";

ll k;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> k;
	ll st = 1;
	while (pw(st, 10) < k) st++;
	if (pw(st, 10) == k) {
		for (const auto &i : S)
			cout << string(st, i);
		cout << endl;
		return 0;
	}
	st--;
	vector<ll> cnt(S.size(), st);
	int nxt = 0;
	while (prod(cnt) < k){
		cnt[nxt++]++;
	}
	for (int i = 0; i < S.size(); i++)
		cout << string(cnt[i], S[i]);
}
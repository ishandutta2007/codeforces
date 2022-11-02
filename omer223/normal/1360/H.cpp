#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

int n, m;

string toStr(ll x) {
	string ret = "";
	foru(i, 0, m) {
		ret.pb((x & 1 ? '1' : '0'));
		x >>= 1;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

ll toBin(const string& s) {
	ll tot = 0, mul = 1;
	for (int i = m - 1; i >= 0; i--) {
		if (s[i] == '1')tot += mul;
		mul <<= 1;
	}
	return tot;
}

void solve() {
	cin >> n >> m;
	string s;
	set<ll> mem, vis;
	ll med = (((1LL << m) - 1) >> 1);
	foru(i, 0, n) {
		cin >> s;
		mem.insert(toBin(s));
	}
	bool even = 1;
	for (ll x : mem) {
		if (even) {
			if (x <= med) {
				med++;
				while (vis.find(med) != vis.end())med++;
			}
		}
		else {
			if (x >= med) {
				med--;
				while (vis.find(med) != vis.end())med--;
			}
		}
		even = !even;
		vis.insert(x);
	}
	cout << toStr(med) << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
ll init, l, r, t, use, add;
bitset<sz> can, vis;

void solveHard() {
	ll rem = t;
	if (use - 1 + add <= r) {
		cout << "Yes\n";
		return;
	}
	foru(i, 0, use) {
		if (i <= r && i + add <= r)can[i] = 1;
	}
	if (init < use && !can[init]) {
		cout << "No\n";
		return;
	}//assume not in danger zone
	else if (init < use)init += add;
	while (rem>0) {
		if (vis[init%use]) {
			cout << "Yes\n";
			return;
		}
		vis[init%use] = 1;
		ll curDowns = (init - (init%use)) / use;
		rem -= curDowns;
		init %= use;
		if (rem <= 0) {
			cout << "Yes\n";
			return;
		}
		else if (can[init]) {
			init += add;
		}
		else {
			cout << "No\n";
			return;
		}
	}
}


int main() {
	fast;
	cin >> init >> l >> r >> t >> use >> add;
	init -= l;
	r -= l;
	if (use >= add) {
		bool f = 0;
		if (init + add <= r) {
			init += add; f = 1;
		}
		if (init - use < 0)cout << "No" << '\n';
		else {
			ll d = add - use;
			if (d == 0)cout << "Yes\n";
			else {
				init -= use;
				if (init < 0)cout << "No\n";
				else {
					t--;
					ll bnd = -init / d;
					if (t <= bnd)cout << "Yes\n";
					else cout << "No\n";
				}
			}
		}
		return 0;
	}
	else {
		solveHard();
	}
	return 0;
}
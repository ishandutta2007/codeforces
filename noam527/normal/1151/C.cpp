#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

ll sumodd(ll x) {
	x %= md;
	return x * x % md;
}

ll sumodd(ll l, ll r) {
	return (sumodd(r) - sumodd(l - 1) + md) % md;
}

ll sumeven(ll l, ll r) {
	return (sumodd(l, r) + r - l + 1) % md;
}

ll calc(ll x) {
	if (x == 0) return 0;
	ll st[2], len = 1, rtn = 0;
	st[0] = st[1] = 1;
	int type = 0;
	while (len <= x) {
		if (type == 0) {
			rtn += sumodd(st[0], st[0] + min(x - len, len - 1));
			st[0] += len;
		}
		else {
			rtn += sumeven(st[1], st[1] + min(x - len, len - 1));
			st[1] += len;
		}
		len *= 2;
		type ^= 1;
	}
	return rtn % md;
}

ll l, r;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> l >> r;
	cout << (calc(r) - calc(l - 1) + md) % md << '\n';
}
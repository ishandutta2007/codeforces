#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
using namespace std;

vector<int> p;
vector<ll> factors;

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

ll lcm(ll x, ll y) {
	return x / gcd(x, y) * y;
}

void sieve() {
	vector<bool> s(1e6 + 3, true);
	int i;
	for (i = 2; i * i < s.size(); i++) {
		if (s[i]) {
			p.push_back(i);
			for (int j = i * i; j < s.size(); j += i) s[j] = false;
		}
	}
	for (; i < s.size(); i++) if (s[i]) p.push_back(i);
}

void factorize2(vector<pair<ll, ll>> &f, int ind = 0, ll val = 1) {
	if (ind == f.size()) {
		factors.push_back(val);
		return;
	}
	for (int i = 0; i <= f[ind].second; i++) {
		factorize2(f, ind + 1, val);
		val *= f[ind].first;
	}
}

vector<pair<ll, ll>> factorize1(ll n) {
	vector<pair<ll, ll>> rtn;
	for (auto i : p) {
		if (n % i == 0) {
			rtn.push_back({ i, 0 });
			while (!(n % i)) last(rtn, 1).second++, n /= i;
		}
	}
	if (n != 1) rtn.push_back({ n, 1 });
	return rtn;
}

int main() {
	ll x, y, ans = 0;
	fast;
	cin >> x >> y;
	sieve();
	vector<pair<ll, ll>> temp = factorize1(x);
	factorize2(temp);
	sort(factors.begin(), factors.end());
	//for (auto i : factors) cout << i << " "; cout << endl;
	ll at = 0, mnn, mnat;
	while (y > 0) {
		//cout << y << " " << at << " " << ans << endl;
		mnn = 9e18;
		ll l;
		for (int i = at + 1; i < factors.size(); i++) {
			l = lcm(factors[at], factors[i]);
			if (y % l <= mnn)
				mnn = y % l, mnat = i;
		}
		if (mnn != 9e18) {
			ans += mnn / factors[at];
			y -= mnn, at = mnat;
		}
		else
			ans += (ll)y / factors[at], y = 0;
	}
	cout << ans << endl;
}
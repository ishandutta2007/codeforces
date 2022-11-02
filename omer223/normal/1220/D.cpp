#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n;

vector<ll> foo(const vector<ll>& v, ll logMult) {
	if (v.empty())return vector<ll>{};
	vector<ll> delOdds, delEvens;
	for (ll x : v) {
		if (x & 1)delOdds.pb(x*logMult);
		else delEvens.pb(x*logMult);
	}
	vector<ll> e;
	for (ll x : delEvens)e.pb((x / logMult) / 2);
	vector<ll> ret = foo(e, logMult << 1);
	for (ll x : ret)delOdds.pb(x);
	if (delOdds.size() < delEvens.size())return delOdds;
	else return delEvens;
}

int main() {
	fast;
	cin >> n;
	vector<ll> v(n);
	foru(i, 0, n)cin >> v[i];
	vector<ll> ret = foo(v, 1);
	cout <<ret.size() << '\n';
	for (ll x : ret)cout << x << ' ';
	return 0;
}
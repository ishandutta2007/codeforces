#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

bool isprime(ll x) {
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a != b + 1) cout << "NO" << endl;
		else if (!isprime(a + b)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

}
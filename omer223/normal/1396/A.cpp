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
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
ll a[sz];
ll n;

void solve() {
	ll n, x, y, z;
}
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	if (n == 1) {
		cout << 1 << " " << 1 << endl;
		cout << -a[0] << endl;
		foru(i, 0, 2) {
			cout << 1 << " " << 1 << endl;
			cout << 0 << endl;
		}
		return 0;
	}
	cout << 1 << " " << n << endl;
	foru(i, 0, n) {
		ll x = 0, y = 0;
		extgcd(n, n - 1, x, y);
		cout << -n*x*a[i] << " ";
		a[i] -= n*x*a[i];
	}
	cout << endl;
	cout << 1 << " " << n - 1 << endl;
	foru(i, 0, n - 1)cout << -a[i] << " ";
	cout << endl;
	cout << n << " " << n << endl;
	cout << -a[n-1] << endl;
	return 0;
}
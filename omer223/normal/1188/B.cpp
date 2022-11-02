#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


int main() {
	fast;
	ll n, p, k;
	cin >> n >> p >> k;
	map<ll, ll> mem;
	foru(i, 0, n) {
		ll x;
		cin >> x;
		ll y = x * x;
		y %= p;
		y *= y;
		y %= p;
		y -= ((k * x) % p);
		y += p;
		y %= p;
		mem[y]++;
	}
	ll tot = 0;
	for (auto ii : mem)tot += ((ii.ss - 1) * ii.ss) / 2;
	cout << tot;
	return 0;
}
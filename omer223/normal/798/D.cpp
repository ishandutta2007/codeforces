#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <map>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
 
const int sz = 1e5 + 5;
int n;
bitset<sz> use;
int a[sz], b[sz], ind[sz];
 
int main() {
	fast;
	cin >> n;
	foru(i, 0, n)
		cin >> a[i];
	foru(i, 0, n)
		cin >> b[i], ind[i] = i;
	sort(ind, ind + n,
		[&](const int& lhs, const int& rhs) -> bool
	{
		return a[lhs] > a[rhs];
	}
	);
	use[ind[0]] = 1;
	for (int i = 1; i < n - 1 + (n & 1); i += 2) {
		if (b[ind[i]] > b[ind[i + 1]])
			use[ind[i]] = 1;
		else
			use[ind[i + 1]] = 1;
	}
	if (!(n & 1))
		use[ind[n - 1]] = 1;
	cout << use.count() << '\n';
	foru(i, 0, n)
		if (use[i])cout << i + 1 << ' ';
	return 0;
}
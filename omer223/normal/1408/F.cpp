#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

vector<pii> v;

void solve(int l, int r) {
	if (l + 1 == r) {
		v.pb({ l,r });
		return;
	}
	int len = (r - l + 1);
	solve(l, l + (len >> 1) - 1);
	solve(l + (len >> 1), r);
	foru(i, l, l + (len >> 1))v.pb({ i,i + (len >> 1) });
}

int main() {
	fast;
	int n;
	cin >> n;
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	int mul = 1;
	while ((mul << 1) <= n) {
		mul <<= 1;
	}
	solve(1, mul);
	if (mul != n)solve(n - mul + 1, n);
	cout << v.size() << endl;
	for (pii x : v)cout << x.first << " " << x.second << endl;
	return 0;
}
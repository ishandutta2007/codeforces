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

const int sz = 3e2;
ll a[sz], n;

void solve() {
	cin >> n;
	ll sm = 0, mx=0;
	foru(i, 0, n) {
		cin >> a[i]; sm += a[i];
		mx = max(mx, a[i]);
	}
	if (sm & 1 || n==1 || 2*mx>sm) {
		cout << "T" << endl;
		return;
	}
	else {
		cout << "HL" << endl;
		return;
	}
	
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
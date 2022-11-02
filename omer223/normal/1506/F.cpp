#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
int n;
pii p[sz];

void solve() {
	cin >> n;
	foru(i, 0, n) 
		cin >> p[i].ff;
	foru(i, 0, n)
		cin >> p[i].ss;
	int rmc = 0;
	ll tot = 0;
	pii cur = { 1,1 };
	sort(p, p + n);
	foru(i, 0, n) {
		if (i == 0 && p[i].ff == 1 && p[i].ss == 1)
			continue;
		int nrmc = p[i].ff - p[i].ss;
		if (abs(nrmc) & 1) {
			if (!(rmc & 1))rmc++;
			tot += (nrmc - rmc) / 2;
		}
		else {
			if(nrmc!=rmc)tot += (nrmc - rmc + 1) / 2;
			else tot += (p[i].ff - cur.ff);
		}
		cur = p[i];
		rmc = cur.ff - cur.ss;
	}
	cout << tot << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1;
const ll LINF = (ll) 1e18 + 1;
const ld EPS = 1e-9;

int n;

void run() {
	ll k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	
	ll cnt256 = min(k2, min(k5, k6));
	k2 -= cnt256;
	ll cnt32 = min(k2, k3);
	ll ans = cnt32 * 32 + cnt256 * 256;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	run();
	
	return 0;
}
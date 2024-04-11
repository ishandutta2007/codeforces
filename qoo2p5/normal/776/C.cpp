#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = 1e-8;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) x.size()

const int N = (int) 1e5 + 123;

int n, k;
ll a[N], p[N];

void run() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	partial_sum(a, a + n, p);
	
	ll ans = 0;
	map<ll, int> cnt;
	
	for (int i = 0; i < n; i++) {
		cnt[p[i]]++;
	}
	
	for (int l = 0; l < n; l++) {
		ll x = 1;
		set<ll> was;
		for (int it = 0; it <= 100; it++) {
			if (abs(x) > LINF / 10) {
				break;
			}
			
			if (abs(k) > 1 || !was.count(x)) {
				ll v = (l == 0 ? 0 : p[l - 1]);
				ans += cnt[x + v];
			}
			
			if (abs(k) <= 1) was.insert(x);
			x *= k;
		}
		cnt[p[l]]--;
	}
	
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}
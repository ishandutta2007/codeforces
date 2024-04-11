#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 2e5 + 123;

ll n;
ll x, s;
int m, k;
ll a[N], b[N], c[N], d[N];

void run() {
	cin >> n >> m >> k;
	cin >> x >> s;
	vector<pair<ll, ll>> q;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		q.push_back({b[i], a[i]});
	}
	q.push_back({0, x});
	sort(q.begin(), q.end());
	ll cur_min = LINF;
	for (int i = 0; i < (int) q.size(); i++) {
		cur_min = min(cur_min, q[i].second);
		q[i].second = cur_min;
	}
	
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	
	ll ans = n * x;
	
	for (int i = 0; i < m; i++) {
		if (b[i] <= s) {
            mini(ans, n * a[i]);
		}
	}
	
	for (int i = 0; i < k; i++) {
		if (d[i] > s) {
			continue;
		}
		
		ll rest = s - d[i];
		int best = ub(q.begin(), q.end(), mp(rest, LINF)) - 1;
		ll need = max(0LL, n - c[i]);
		mini(ans, need * q[best].second);
	}
	
	cout << ans << "\n";
}
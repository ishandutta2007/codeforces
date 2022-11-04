#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef double ld;
  
const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ll MOD = (ll) 1e9 + 7;
const ld EPS = 1e-12;
  
#define sz(x) (int) (x).size()
#define mp make_pair
#define pb push_back
#define rep(i, s, t) for (int i = s; i < t; i++)
#define all(x) (x).begin(), (x).end()
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
  
template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return 1;
    }
    return 0;
}
  
template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return 1;
    }
    return 0;
}
  
void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}
  
ll sum(ll x, ll y) {
    add(x, y);
    return x;
}
  
void run();
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
 
// SOLUTION //

const int N = (int) 2e5 + 123;
//#define int long long
int n, m, k;
ll c[N];
int a, b;
int x[N], y[N];
 
void run() {
	cin >> n >> m >> k;
	rep(i, 0, n) cin >> c[i];
	cin >> a;
	rep(i, 0, a) {
		cin >> x[i];
		x[i]--;
	}
	cin >> b;
	rep(i, 0, b) {
		cin >> y[i];
		y[i]--;
	}
	sort(x, x + a);
	sort(y, y + b);
	
	vector<int> com;
	rep(i, 0, a) {
		if (binary_search(y, y + b, x[i])) com.pb(x[i]);
	}
	
	int have = sz(com);
	
	ll ans = LINF;
	
	vector<pair<ll, int>> q;
	rep(i, 0, have) {
		q.pb({c[com[i]], com[i]});
	}
	sort(all(q));
	
	ll sum = 0;
	
	set<pair<ll, int>> onlya, onlyb, use, rest;
	
	rep(i, 0, a) {
		if (!binary_search(all(com), x[i])) onlya.insert({c[x[i]], x[i]});
	}
	rep(i, 0, b) {
		if (!binary_search(all(com), y[i])) onlyb.insert({c[y[i]], y[i]});
	}
	
	while (sz(onlya) > k) {
		onlya.erase(--onlya.end());
	}
	
	while (sz(onlyb) > k) {
		onlyb.erase(--onlyb.end());
	}
	
	for (auto el : onlya) sum += el.first;
	for (auto el : onlyb) sum += el.first;
	
	rep(i, 0, n) {
		if (!onlya.count({c[i], i}) && !onlyb.count({c[i], i}) && !binary_search(all(q), mp(c[i], i))) {
			rest.insert({c[i], i});
		}
	}
	
	rep(i, 0, have + 1) {
		while (sz(onlya) + i > k && sz(onlya) > 0) {
			auto best = *onlya.rbegin();
			sum -= best.first;
			rest.insert(best);
			onlya.erase(best);
		}
		
		while (sz(onlyb) + i > k && sz(onlyb) > 0) {
			auto best = *onlyb.rbegin();
			sum -= best.first;
			rest.insert(best);
			onlyb.erase(best);
		}
		
		while (sz(onlya) + sz(onlyb) + sz(use) + i > m && sz(use)) {
			auto worst = *use.rbegin();
			use.erase(worst);
			rest.insert(worst);
			sum -= worst.first;
		}
		
		while (sz(onlya) + sz(onlyb) + sz(use) + i < m && sz(rest) > 0) {
			auto best = *rest.begin();
			rest.erase(best);
			use.insert(best);
			sum += best.first;
		}
		
		while (sz(rest) > 0 && sz(use) > 0) {
			auto worst = *use.rbegin();
			auto best = *rest.begin();
			if (worst.first > best.first) {
				use.erase(worst);
				rest.insert(worst);
				use.insert(best);
				rest.erase(best);
				sum -= worst.first;
				sum += best.first;
			} else break;
		}
		
		if (sz(onlya) + sz(onlyb) + sz(use) + i == m && i + min(sz(onlya), sz(onlyb)) >= k) {
			mini(ans, sum);
		}
		
		if (i == have) break;
		
		sum += q[i].first;
	}
	
	cout << (ans == LINF ? -1 : ans) << "\n";
}
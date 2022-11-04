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
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
 
// SOLUTION //

const ll C = (ll) 5e12 + 123;
const int N = (int) 1e5 + 123;
const int L = 40;

int n;
ll a, b, h, w;
vector<int> X;
ll dp[N];

bool check(int use) {
	fill(dp, dp + N, -1);
	ll all = 1;
	rep(i, 0, use) {
		all *= X[i];
		mini(all, C);
	}
	
	dp[1] = all;
	
	rep(i, 0, use) {
		for (int j = N - 2; j >= 0; j--) {
			if (dp[j] == -1) continue;
			
			ll to = j * 1LL * X[i];
			if (to >= N - 1) {
				maxi(dp[N - 1], all / to);
			} else {
				maxi(dp[to], all / to);
			}
		}
	}
	
	rep(i, 1, N) {
		if (dp[i] == -1) continue;
		ll hh = h * i;
		ll ww = w * dp[i];
		if ((hh >= a && ww >= b) || (hh >= b && ww >= a)) return 1;
	}
	
	return 0;
}
 
void run() {
	cin >> a >> b >> h >> w >> n;
	{
		vector<int> q;
		rep(i, 0, n) {
			int x;
			cin >> x;
			q.pb(x);
		}
		sort(all(q));
		reverse(all(q));
		rep(i, 0, min(n, L)) {
			X.pb(q[i]);
		}
		n = min(n, L);
	}
	
	int left = -1;
	int right = n + 1;
	
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	
	cout << (right == n + 1 ? -1 : right) << "\n";
}
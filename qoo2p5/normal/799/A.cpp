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
 
void run() {
	ll n, t, k, d;
	cin >> n >> t >> k >> d;
	ll t1 = (n + k - 1) / k * t;
	ll t2;
	{
		ll left = d - 1;
		ll right = INF;
		
		while (right - left > 1) {
			ll mid = (left + right) / 2;
			ll cnt = (mid - d) / t + mid / t;
			cnt *= k;
			if (cnt >= n) right = mid;
			else left = mid;
		}
		
		t2 = right;
	}
	
	cout << (t2 < t1 ? "YES\n" : "NO\n");
}
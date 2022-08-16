#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

ll a, b, c, d;

ll _norm(ll r) {
    return r*(r+1)/2;
}
ll norm(ll l, ll r) {
    l = max(l, 1ll);
    return _norm(r)-_norm(l-1);
}
ll sum_times(ll x, ll cnt) {
    x = d*(x/d);
    ll l = x-(cnt-1)*d;
    ll r = x;
    return d*norm(l/d, r/d);
}
ll num_before(ll x) {
    if (x < 0) return 0;
    return x/d+1;
}
ll value(ll x) {
    ll used = num_before(x);
    ll done = num_before(x-c-1);
    ll ongoing = used-done;

    ll done_sum = done*(-a + b*c);
    ll ongoing_sum = ongoing*(-a) + b*(ongoing*x-sum_times(x, ongoing));
    return done_sum + ongoing_sum;
}
ll value_attacks(ll x) {
    return value(d*(x-1));
}
ll slow(ll x) {
    ll ongoing = 0;
    ll ans = 0;
    for (ll i = 0; i <= x; i++) {
        ans += ongoing*b;
        if (i%d == 0) {
            ans -= a;
            ongoing++;
        }
        if (i >= c && (i-c)%d == 0) {
            ongoing--;
        }
    }
    return ans;
}

const ll INF = 1e6+10;
void solve(){
    cin >> a >> b >> c >> d;
    if (a > c*b) {
        cout << "-1\n";
        return;
    }
    ll ans = value(0);
    ll lo = 0, hi = INF, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        ll left = value_attacks(mid);
        ll right = value_attacks(mid+1);
        ans = min(ans, left);
        ans = min(ans, right);
        if (left <= right) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    for (ll x = max(1ll, lo-10); x <= lo+10; x++) {
        ans = min(ans, value(x));
    }
    cout << -ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}
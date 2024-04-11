#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 8e5+10, MOD = 1e9+7;

template <class T> using min_pq = std::priority_queue<T, vector<T>, greater<T>>;

int n;
ar<ll, 2> a[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a[i] = {x+y, x-y};
    }
    sort(a, a+n);

    priority_queue<ll> p1; p1.push(0);
    min_pq<ll> p2; p2.push(0);

    ll ans=0;
    for (int i = 0; i < n; i++) {
        ll x = a[i][0], y = a[i][1];
        swap(x, y);

        ans += max<ll>({p1.top()-x-y, x-p2.top()-y, 0ll});
        if (!sz(p1) || x < p2.top()+y) p1.push(x+y), p1.push(x+y), p2.push(p1.top()-2*y), p1.pop();
        else p2.push(x-y), p2.push(x-y), p1.push(p2.top()+2*y), p2.pop();
    }
    cout << ans/2 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
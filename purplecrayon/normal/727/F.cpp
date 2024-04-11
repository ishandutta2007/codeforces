#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 7.5e2+10, MOD = 998244353;
const int M = 2e5+10;
const ll INF = 1e18+10;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

int n, m;
ll a[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> v;
    for (int i = 0; i <= n; i++) {
        // minimum mood s.t. removing i items keeps it all positive

        auto check = [&](ll x) {
            min_pq<ll> pq;
            ll sum = x;
            int need = 0;
            for (int j = 0; j < n; j++) {
                sum += a[j];
                pq.push(a[j]);
                while (sum < 0) need++, sum -= pq.top(), pq.pop();
            }
            return need <= i;
        };

        ll lo = -1, hi = INF, mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            if (check(mid)) hi = mid;
            else lo = mid;
            mid = (lo + hi) / 2;
        }
        v.push_back(hi);
    }
    // v is decreasing
    reverse(v.begin(), v.end());
    while (m--) {
        ll x; cin >> x;
        int ans = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
        cout << n - ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
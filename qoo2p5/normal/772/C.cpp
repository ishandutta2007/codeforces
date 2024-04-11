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

template<typename A, typename B> A sum(A x, B y) {
    x += y;
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

template<typename A, typename B> void add(A &x, B y) {
    x += y;
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
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

// == BEGIN CODE == //

const int N = (int) 2e5 + 123;

ll n, m;
bool used[N];
ll dp[N];
ll from[N];
ll ph[N];
vector<ll> nums[N];

ll power(ll x, ll y, ll mod) {
    if (y == 0) {
        return 1;
    }
    
    if (y & 1) {
        return power(x, y - 1, mod) * 1LL * x % mod;
    } else {
        ll t = power(x, y / 2, mod);
        return t * 1LL * t % mod;
    }
}

ll rev(ll x, ll mod) {
    return power(x, ph[mod] - 1, mod);
}

ll phi(ll m) {
    vector<pair<ll, ll>> cur;
    for(ll i = 2; i * i <= m; i++) {
        int p = 0;
        while(m%i == 0) p++, m /= i;
        if(p) cur.pb(mp(i, p));
    }
    if(m != 1) cur.pb(mp(m, 1));
    ll ans = 1;
    for(auto &i : cur) {
        ans *= i.first - 1;
        for(int j = 1; j < i.second; j++) ans *= i.first;
    }
    return ans;
}

void run() {
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        int x;
        cin >> x;
        used[x] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        if (m % i != 0) continue;
        ph[i] = phi(i);
    }
    
    for (ll i = 0; i < m; i++) {
        ll g = __gcd(i, m);
        if (!used[i]) nums[g].pb(i);
    }
    
    fill(from, from + m, -1);
    
    dp[m] = sz(nums[m]);
    for (ll i = m - 1; i >= 1; i--) {
        if (m % i != 0) continue;
        
        dp[i] = sz(nums[i]);
        
        for (ll to = i + i; to <= m; to += i) {
            if (m % to != 0) continue;
            
            if (maxi(dp[i], sz(nums[i]) + dp[to])) {
                from[i] = to;
            }
        }
    }
    
    cout << dp[1] << "\n";
    ll cur = 1;
    vector<ll> need = nums[cur];
    while (from[cur] != -1) {
        cur = from[cur];
        for (ll el : nums[cur]) {
            need.pb(el);
        }
    }
    
    vector<ll> res;
    res.push_back(need[0]);
    
    for (int i = 1; i < sz(need); i++) {
        ll x = need[i - 1];
        ll y = need[i];
        ll g = __gcd(x, m);
        ll w = (y / g * rev(x / g, m / g)) % m;
        assert((x * w) % m == y);
        res.push_back(w);
    }
    
    for (ll el : res) {
        cout << el << " ";
    }
    cout << "\n";
}
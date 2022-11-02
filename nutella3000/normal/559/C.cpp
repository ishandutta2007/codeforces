#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int mod = 1e9 + 7;
const int max_h = 2e5 + 5;

int binpow(int a, int b) {
    int res = 1;
    for(;b;b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}


int fact[max_h], rfact[max_h];

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * rfact[k] % mod * rfact[n - k] % mod;    
}

int h, w, n;


void solve() {
    fact[0] = rfact[0] = 1;
    for(int i = 1;i < max_h;i++) {
        fact[i] = fact[i - 1] * i % mod;
        rfact[i] = binpow(fact[i], mod - 2);
    }

    cin >> h >> w >> n;
    vector<pii> a(n + 1);
    a[n] = {h - 1, w - 1};
    for(int i = 0;i < n;i++) {
        cin >> a[i].f >> a[i].s;
        a[i].f--;
        a[i].s--;
    }

    sort(all(a), [](pii v1, pii v2) {return v1.f + v1.s < v2.f + v2.s;});

    vector<int> dp(n + 1);

    for(int i = 0;i <= n;i++) {
        int x = a[i].f, y = a[i].s;

        dp[i] += C(x + y, x);

        //cout << dp[i] << endl;
        for(int j = 0;j < i;j++) {
            dp[i] -= dp[j] * C(x + y - a[j].f - a[j].s, x - a[j].f) % mod;
        }
        dp[i] = (dp[i] % mod + mod) % mod;
    }

    cout << dp[n];
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}
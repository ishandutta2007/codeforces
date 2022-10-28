#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 95542721, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
vector<pair<ll, int>> get_pf_big(ll n){
    vector<pair<ll, int>> r;
    for (ll i = 2; i*i <= n; i++) if (n%i == 0){
        r.emplace_back(i, 0);
        while (n%i == 0) r.back().second++, n /= i;
    }
    if (n>1) r.emplace_back(n, 1);
    return r;
}

int n;
ll a[MAXN];


void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans=n+1;
    auto test = [&](ll x) {
        auto c = get_pf_big(x);
        for (auto _p : c) {
            ll p = _p.first;

            ll cur=0;
            for (int i = 0; i < n; i++){
                if (a[i] < p) cur += p-a[i]%p;
                else cur += min(a[i]%p, p-a[i]%p);
            }
            ans = min(ans, cur);
        }
    };

    for (int rep = 0; rep < 40; rep++) {
        int c = rnd(0, n-1);
        test(a[c]-1), test(a[c]), test(a[c]+1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
ll a[nax];
vector<ll> x;
int n, m;

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++){
        ll w; cin >> w;
        x.pb(w);
    }
    sort(x.begin(), x.end());
    ll ans = 0;
    ll przed = 0;
    ll za = 0;
    for(int i=1;i<=n;i++){
        ll cord = 100 * (i - 1);
        if(cord < x[0]) przed += a[i];
        if(cord > x.back()) za += a[i];
    }
    ans = max(przed, za);
    int from = 1;
    for(int i=0;i<(int)x.size()-1;i++){
        int lo = x[i];
        int hi = x[i + 1];
        while(from <= n && (from - 1) * 100 <= lo) from++;
        if(from > n) break;
        if((from - 1) * 100 >= hi) continue;
        int to = from;
        while(to < n && to * 100 < hi) to += 1;
        // [from, to]
        vector<tuple<int, int, ll> > ev;
        for(int j=from;j<=to;j++){
            ll reward = a[j];
            int pos = (j - 1) * 100;
            int zaMna = hi - pos;
            int przedeMna = pos - lo;

            int pocz = max(lo, pos - zaMna);
            int kon = min(hi, pos + przedeMna);

            ev.pb(make_tuple(pocz * 3 + 1, 1, reward));
            ev.pb(make_tuple(kon * 3 - 1, -1, reward));
        }
        sort(ev.begin(), ev.end());
        ll bal = 0;
        ll best = 0;
        for(auto [x, y, z] : ev){
            bal += z * y;
            best = max(best, bal);
        }
        ans = max(ans, best);
        from = to;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}
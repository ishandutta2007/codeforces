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
const ll INF = 1e9+10;

void solve(){
    int n, m, cap, o; cin >> n >> m >> cap >> o;
    vector<ar<ll, 3>> a(n);
    for (auto& it : a) cin >> it[0] >> it[1] >> it[2];
    sort(a.begin(), a.end());
    a.push_back({m, 0, INF});

    multiset<ar<ll, 2>> s; s.insert({0, o});
    ll cur=0, mx=o, ans=0;
    for (auto c : a) {
        ll d=c[0]-cur;
        while (d > 0) {
            if (!sz(s)){ cout << -1 << '\n'; return; }
            auto cv = *s.begin(); s.erase(s.begin());
            if (cv[1] < d) {
                ans += cv[0]*cv[1], d -= cv[1], mx -= cv[1];
            } else {
                ans += cv[0]*d, mx -= d, s.insert({cv[0], cv[1]-d});
                d=0;
            } 
        }
        s.insert({c[2], c[1]}), mx += c[1];
        while (mx > cap) {
            auto cv = *prev(s.end()); s.erase(prev(s.end()));
            if (mx - cv[1] >= cap) mx -= cv[1];
            else s.insert({cv[0], cv[1]-mx+cap}), mx = cap;
        }
        cur = c[0];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}
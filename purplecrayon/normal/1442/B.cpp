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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& it : a) cin >> it, --it;
    vector<int> b(k); for (auto& it : b) cin >> it, --it;

    vector<int> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]] = i;

    vector<int> spec(n, 0);
    for (int c : b) spec[loc[c]] = 1;

    set<int> pos;
    for (int i = 0; i < n; i++) pos.insert(i);

    ll ans=1;
    for (int c : b){
        c = loc[c];

        int c_bound=0, to_rem=-1;
        auto test_bound = [&](auto it) -> void {
            if (it == pos.end() || spec[*it]) return;
            c_bound++, to_rem = *it;
        };

        assert(pos.count(c));
        auto it = pos.find(c);
        test_bound(next(it));
        if (it != pos.begin())
            test_bound(prev(it));

        if (!c_bound){ cout << 0 << '\n'; return; }

        ans = ans*c_bound%MOD, pos.erase(to_rem);
        spec[c] = 0;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}
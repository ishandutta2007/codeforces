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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

void solve(){
    int m, n, k, t; cin >> m >> n >> k >> t;
    vector<int> a(m); for (auto& it : a) cin >> it;
    sort(a.rbegin(), a.rend());
    vector<int> l(k), r(k), d(k);
    for (int i = 0; i < k; i++) cin >> l[i] >> r[i] >> d[i];


    auto v = [&](int x) -> bool {
        int mn = INF;
        for (int i = 0; i < x; i++) mn = min(mn, a[i]);

        vector<ar<int, 2>> c;
        for (int i = 0; i < k; i++) if (d[i] > mn)
            c.push_back({l[i], r[i]});

        //calc required time
        sort(c.begin(), c.end());
        int lr = 0, ans = 0;
        for (auto y : c) {
            if (y[0] <= lr) ans += max(y[1]-lr, 0), lr = max(lr, y[1]);
            else ans += y[1]-y[0]+1, lr = y[1];
        }
        return n+1+2*ans <= t;
    };

    int lo = -1, hi = m+1, mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (v(mid)) lo = mid;
        else hi = mid;
        mid = (lo + hi)/2;
    }
    cout << lo << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
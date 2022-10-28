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
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    vector<ll> ans(n);
    auto v = [&](int x) -> bool {
        //return true if x works, construct ans
        if (x == 0){
            ans=a;
            sort(ans.begin(), ans.end());
            return 1;
        }
        multiset<ll> s;
        for (auto& it : a) s.insert(it);
        ans.assign(n, -1); int c=-1;
        for (int i = 1; i < n-1 && (i+1)/2 <= x; i += 2){
            ans[i] = *s.begin();
            s.erase(s.begin());
            c=i;
        }
        if (sz(s) != n-x) return false;
        for (int i = 1; i < n; i++) if (ans[i] != -1){
            auto it = s.upper_bound(ans[i]);
            if (it == s.end()) return false;
            ans[i-1] = *it;
            s.erase(it);
        }
        assert(c < n-1);
        auto it = s.upper_bound(ans[c]);
        if (it == s.end()) return false;
        ans[c+1] = *it;
        s.erase(it);

        for (int i = c+2; i < n; i++){
            ans[i] = *s.begin();
            s.erase(s.begin());
        }
        ll cv=0;
        for (int i = 1; i < n-1; i++){
            cv += ans[i] < ans[i-1] && ans[i] < ans[i+1];
        }
        assert(cv == x);
        //cerr << cv << '\n';
        return true;
    };
    int lo=-1, hi=n+1, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (v(mid)) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    assert(v(lo));
    cout << lo << '\n';
    for (auto& it : ans) cout << it << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}
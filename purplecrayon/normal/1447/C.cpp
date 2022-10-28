#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; ll w; cin >> n >> w; ll ts=0;
    vector<pair<ll, int>> a(n); for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second=i, ts += a[i].first;
    sort(a.begin(), a.end());
    while (n && a.back().first > w) ts -= a.back().first, a.pop_back(), n--;
    if (!n){ cout << "-1\n"; return; }
    ll need=(w+1)/2;
    if (ts < need) { cout << "-1\n"; return; }
    if (a.back().first >= need){ cout << "1\n" << (a.back().second+1) << '\n'; }
    else {
        vector<int> res;
        ll s=0; int c=n-1;
        while (s < need) res.push_back(a[c].second), s += a[c].first, c--;
        cout << sz(res) << '\n';
        for (auto it : res) cout << (it+1) << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}
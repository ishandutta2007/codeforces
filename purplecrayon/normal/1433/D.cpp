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
const int MAXN = 11, MAXM = 11, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    int mn=min_element(a.begin(), a.end())-a.begin(), mx=max_element(a.begin(), a.end())-a.begin();
    if (a[mn]==a[mx]){ cout << no; return; }
    cout << yes;
    for (int i = 0; i < n; i++) if (i != mn) {
        if (a[i] != a[mn]) cout << (i+1) << ' ' << (mn+1) << '\n';
        else cout << (i+1) << ' ' << (mx+1) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}
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
const int MAXN = 1e5+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> p(n), c(n), a(n, 1);
    vector<int> ans; ans.reserve(n);
    for (int i = 0; i < n; i++){
        cin >> p[i] >> c[i], --p[i], a[i] &= c[i];
        if (p[i] != -2) a[p[i]] &= c[i];
    }
    for (int i = 0; i < n; i++) if (a[i]) ans.push_back(i);
    if (ans.empty()){ cout << "-1\n"; return; }
    sort(ans.begin(), ans.end());
    for (auto& it : ans) cout << (it+1) << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
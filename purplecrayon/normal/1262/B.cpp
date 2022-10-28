#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXM = 3e3+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll LINF = 1e18+10;

void solve(){
    int n; cin >> n; set<int> s; for (int i = 1; i <= n; i++) s.insert(i);
    vector<int> a(n); for (auto& it : a) cin >> it, s.erase(it);
    vector<int> ans(n); ans[0]=a[0]; 
    for (int i = 1; i < n; i++){
        if (a[i] != a[i-1]) ans[i] = a[i];
        else {
            if (!sz(s) || *s.begin() > a[i]) { cout << "-1\n"; return; }
            ans[i] = *s.begin(); s.erase(s.begin());
        }
    }
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t; 
    while (t--) solve();
}
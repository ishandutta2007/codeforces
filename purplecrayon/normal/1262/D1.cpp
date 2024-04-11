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
    int n; cin >> n; vector<pair<int, int>> a(n); vector<int> oa(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = -i, oa[i] = a[i].first;
    sort(a.rbegin(), a.rend()); int q; cin >> q;
    vector<vector<pair<int, int>>> qs(n); vector<int> ans(q);
    for (int qt=0; qt < q; qt++){
        int k, pos; cin >> k >> pos, --k, --pos;
        qs[k].push_back({pos, qt});
    }
    oset<int> s;
    for (int i = 0; i < n; i++){
        s.insert(-a[i].second);// cout << "INS: " << a[i].second << '\n';
        for (auto it : qs[i]){
            ans[it.second] = oa[*s.find_by_order(it.first)];
        }
    }
    for (auto it : ans) cout << it << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}
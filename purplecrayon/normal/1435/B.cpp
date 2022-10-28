#include <bits/stdc++.h>
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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g1(n, vector<int>(m)), g2(m, vector<int>(n));
    map<int, int> r, c;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin >> g1[i][j], c[g1[i][j]]=j;
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) cin >> g2[i][j], r[g2[i][j]]=j;
    }
    // for (auto& it : r) cout << it.first << ' ' << it.second << ' ' << c[it.first] << '\n'; cout << '\n';
    // return;
    vector<vector<int>> ans(n, vector<int>(m));
    for (auto& it : r) ans[it.second][c[it.first]] = it.first;
    for (auto x : ans){
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}
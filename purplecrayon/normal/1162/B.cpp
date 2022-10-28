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
const int MAXN = 5e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n", poss="Possible", imp = "Impossible";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> b[i][j];
    auto good = [&](int i, int j) -> bool {
        return ((!i || (a[i-1][j] < a[i][j] && b[i-1][j] < b[i][j])) && (!j || (a[i][j-1] < a[i][j] && b[i][j-1] < b[i][j])));
    };
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
            if (!good(i, j)){ cout << imp; return; }
        }
    }
    cout << poss;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
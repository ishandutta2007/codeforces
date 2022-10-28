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
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<string> g(n);
    for (auto& it : g) cin >> it;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) if (g[i][j]=='.'){
            vector<pair<int, int>> pos{{i, j}, {i+1, j-1}, {i+1, j}, {i+1, j+1}, {i+2, j}};
            bool bad=0;
            for (auto nxt : pos) if (!bad) {
                bad |= nxt.first < 0 || nxt.first >= n || nxt.second < 0 || nxt.second >= n;
            }
            for (auto nxt : pos) if (!bad) {
                bad |= g[nxt.first][nxt.second] != '.';
            }
            if (bad){ cout << no; return; }
            for (auto nxt : pos) {
                g[nxt.first][nxt.second] = '#';
            }
        }
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
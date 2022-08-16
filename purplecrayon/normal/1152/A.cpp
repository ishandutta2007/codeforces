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
const int MAXN = 2.5e2+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vector<int> ca(2), cb(2);
    while (n--){ int c; cin >> c; ca[c&1]++; }
    while (m--){ int c; cin >> c; cb[c&1]++; }
    cout << (min(ca[0], cb[1])+min(ca[1], cb[0]));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
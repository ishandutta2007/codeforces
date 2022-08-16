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

void add_self(ll& a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
}
void solve(){
    int n; string s; cin >> n >> s;
    
    ar<ll, 2> dp{0, 0}; ll ans=0;
    auto ad = [&](int c, ll amt){
        if (c == 0) add_self(dp[0], amt);
        else if (c == 1) add_self(dp[1], amt*dp[0]%MOD);
        else if (c == 2) add_self(ans, amt*dp[1]%MOD);
        else assert(false);
    };
    const ll I3=(MOD+1)/3;
    for (auto c : s) {
        if (c == '?') for (int i = 2; i >= 0; i--) ad(i, I3);
        else ad(c-'a', 1ll);
    }
    for (char c : s) if (c == '?') ans=ans*3%MOD;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
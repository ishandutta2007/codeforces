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

string dp[MAXM][1<<MAXN];
void solve(){
    //dp[i][mask] -> x in mask things have already been chosen bad -> i is the index
    //m*(1<<n)*26*100
    int n, m; cin >> n >> m;
    vector<string> v(n);
    vector<int> al[ALP]; for (auto& it : al) it.resize(m);
    for (int x=0; x < n; x++) {
        auto& it = v[x]; cin >> it;
        for (int i = 0; i < m; i++) for (int j = 0; j < ALP; j++) if (it[i]-'a' != j) al[j][i] ^= (1<<x);
    }
    dp[0][0]="";
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < (1<<n); j++){
            dp[i][j]="?";
            for (int k = 0; k < ALP; k++) if ((al[k][i-1]&j) == al[k][i-1] && dp[i-1][al[k][i-1]^j] != "?"){
                dp[i][j] = dp[i-1][al[k][i-1]^j]+char('a'+k);
                break;
            }
        }
    }
    for (int j = 0; j < (1<<n); j++) if (dp[m][j] != "?") { cout << dp[m][j] << '\n'; return; }
    cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}
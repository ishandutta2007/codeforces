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
const int MAXN = 1e6+10, MAXM = 11, MAXL = 21, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

bool col[MAXN];
int nxt[MAXN][MAXL];
void solve(){
    int n, m; cin >> n >> m; n *= m;
    for (int i = 0; i < n; i++) { char c; cin >> c; col[i]=c-'0'; }
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'U') nxt[i][0]=i-m;
        else if (c == 'D') nxt[i][0]=i+m;
        else if (c == 'L') nxt[i][0]=i-1;
        else if (c == 'R') nxt[i][0]=i+1;
        else assert(false);
    }
    for (int k = 1; k < MAXL; k++) for (int i = 0; i < n; i++) nxt[i][k]=nxt[nxt[i][k-1]][k-1];
    map<int, ar<bool, 2>> mp;
    for (int i = 0; i < n; i++){
        int c=i;
        for (int k = MAXL-1; k >= 0; k--) if (n&(1<<k)) c=nxt[c][k];
        mp[c][col[i]]=1;
    }
    cout << sz(mp) << ' '; int ans=0;
    for (auto& it : mp) ans+=it.second[0];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}
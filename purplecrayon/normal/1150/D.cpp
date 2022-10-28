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

void smin(int& a, int b){ a = min(a, b); }

int dp[MAXN][MAXN][MAXN], nxt[MAXM][ALP];

void solve(){
    int n, q; string s; cin >> n >> q >> s;
    // vector<vector<int>> nxt(n, vector<int>(ALP, 1e9));
    for (int i = n-1; i >= 0; i--){
        fill(nxt[i], nxt[i]+ALP, 1e9);
        for (int j = 0; j < ALP && i < n-1; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][s[i]-'a']=i;
    }
    // for (int i = 0; i < n; i++) {
    //     for (auto& it : nxt[i]) cout << it << ' ';
    //     cout << '\n';
    // }
    auto getNxt = [&](int a, char c){
        if (a >= n) return int(1e9);
        // cout << a << ' ' << (c-'a') << ' ' << nxt[a][c-'a'] << '\n';
        return nxt[a][c-'a'];
    };
    
    vector<char> t[3]; for (auto& it : t) it.reserve(MAXN);
    dp[0][0][0] = 0;
    
    vector<int> x; int id[3];
    auto ad = [&](int a, char c){
        x.clear(); for (int i = 0; i < 3; i++) if (i != a) x.push_back(i);
        t[a].push_back(c);
        for (int i = 0; i <= sz(t[x[0]]); i++) for (int j = 0; j <= sz(t[x[1]]); j++){
            id[a] = sz(t[a]); id[x[0]] = i, id[x[1]] = j;
            auto& cur = dp[id[0]][id[1]][id[2]];
            cur = 1e9;
            if (i) { //take x[0]
                int nid[3] = {id[0], id[1], id[2]}; nid[x[0]]--;
                // cout << nid[0] << ' ' << nid[1] << ' ' << nid[2] << '\n';
                smin(cur, getNxt(dp[nid[0]][nid[1]][nid[2]], t[x[0]][i-1])+1);
            }
            if (j) { //take x[1]
                int nid[3] = {id[0], id[1], id[2]}; nid[x[1]]--;
                smin(cur, getNxt(dp[nid[0]][nid[1]][nid[2]], t[x[1]][j-1])+1);
            }
            //take cur
            {
                int nid[3] = {id[0], id[1], id[2]}; nid[a]--; //cout << nid[0] << ' ' << nid[1] << ' ' << nid[2] << ' ' << dp[nid[0]][nid[1]][nid[2]] << ' '  << c << ' ' << getNxt(dp[nid[0]][nid[1]][nid[2]], c) << '\n';
                smin(cur, getNxt(dp[nid[0]][nid[1]][nid[2]], c)+1);
            }
            // cout << id[0] << ' ' << id[1] << ' ' << id[2] << ' ' << cur << ' ' << dp[id[0]][id[1]][id[2]] << '\n';
        }
    };
    
    while (q--){
        char ty; cin >> ty;
        if (ty == '+'){ //push_back
            int a; char c; cin >> a >> c, --a;
            ad(a, c);
        } else if (ty == '-') {
            int a; cin >> a, --a;
            t[a].pop_back();
        } else assert(false);
        // cout << dp[1][0][0] << '\n';
        cout << (dp[sz(t[0])][sz(t[1])][sz(t[2])] <= n ? yes : no);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
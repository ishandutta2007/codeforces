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
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

vector<ar<int, 4>> dp[4][4][1<<9];

void gen(){ //generate solutions for all 2x2 cases, 2x3 cases, and 3x3 cases
    for (auto& x : {make_pair(2, 2), make_pair(2, 3), make_pair(3, 3), make_pair(3, 2)}){
        int n=x.first, m=x.second;
        auto flip = [&](int& bm, int i, int j) -> void {
            bm ^= 1<<(i*m+j);
        };
        queue<int> q; q.push(0);
        while (sz(q)){
            int c=q.front(); q.pop();
            for (int i = 0; i+2 <= n; i++) for (int j = 0; j+2 <= m; j++){
                for (auto f : {i, i+1}) for (auto g : {j, j+1}){
                    int nxt=c; flip(nxt, i, j), flip(nxt, i+1, j), flip(nxt, i, j+1), flip(nxt, i+1, j+1), flip(nxt, f, g);
                    if (nxt && dp[n][m][nxt].empty()){
                        dp[n][m][nxt] = dp[n][m][c];
                        dp[n][m][nxt].push_back({i, j, f, g});
                        // cout << bitset<4>(c) << ' ' << bitset<4>(nxt) << ' ' << sz(dp[n][m][c]) << ' ' << sz(dp[n][m][nxt]) << '\n';
                        q.push(nxt);
                    }
                }
            }
            
        }
        for (int i = 1; i < (1<<(n*m)); i++) assert(sz(dp[n][m][i])&&sz(dp[n][m][i])<=n*m);
    }
}
int n, m;
bool g[MAXN][MAXN];
vector<ar<int, 2>> ops;
void tile(int i, int j, int tn, int tm){
    int bm=0;
    for (int k = 0; k < tn; k++) for (int l = 0; l < tm; l++){
        int id=k*tm+l;
        bm ^= g[i+k][j+l]<<id;
    }
    for (auto it : dp[tn][tm][bm]){
        for (int k : {it[0], it[0]+1}) for (int l : {it[1], it[1]+1}) if (k != it[2] || l != it[3]) {
            ops.push_back({k+i, l+j});
        }
        assert(sz(ops)%3 == 0);
    }
}

void rec(int i){
    assert(i);
    if (i < 0) return;
    else if (i == 2){
        if (m&1){
            //one 3x3, then a bunch of 3x2's
            tile(i-2, 0, 3, 3);
            for (int j = 3; j < m; j+=2) tile(i-2, j, 3, 2);
        } else {
            //a bunch of 3x2's
            for (int j = 0; j < m; j+=2) tile(i-2, j, 3, 2);
        }
        return;
    }
    
    if (m&1){
        //one 2x3, then a bunch of 2x2's
        tile(i-1, 0, 2, 3);
        for (int j = 3; j < m; j+=2) tile(i-1, j, 2, 2);
    } else {
        //a bunch of 2x2's
        for (int j = 0; j < m; j+=2) tile(i-1, j, 2, 2);
    }
    rec(i-2);
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { char c; cin >> c; g[i][j]=(c=='1'); }
    ops.clear(); rec(n-1);
    cout << sz(ops)/3 << '\n'; assert(sz(ops)/3 <= n*m);
    for (int i = 0; i < sz(ops); i+=3){
        auto ts = [&](int i){ return to_string(ops[i][0]+1)+" "+to_string(ops[i][1]+1); };
        cout << ts(i) << ' ' << ts(i+1) << ' ' << ts(i+2) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; gen();
    while (t--) solve();
}
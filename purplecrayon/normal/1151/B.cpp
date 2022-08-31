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
const int MAXN = 5e2+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int a[MAXN][MAXN];
void solve(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    bool has[MAXN][2];
    for (int b = 0; b < MAXB; b++){
        memset(has, 0, sizeof(has));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) has[i][(a[i][j]>>b)&1]=1;
        int c=0, bad=1;
        for (int i = 0; i < n; i++) 
            if (!has[i][0] || !has[i][1]) c ^= has[i][1];
            else bad=0;
        if (!bad || c){
            cout << "TAK\n";
            for (int i = 0; i < n; i++){
                if (!has[i][0] || !has[i][1]) cout << 1 << ' ';
                else {
                    if (!c) { 
                        for (int j = 0; j < m; j++) if (a[i][j]&(1<<b)) { cout << (j+1) << ' '; break; }
                        c=1;
                    } else {
                        for (int j = 0; j < m; j++) if (!(a[i][j]&(1<<b))){ cout << (j+1) << ' '; break; }
                    }
                }
            }
            return;
        }
    }
    cout << "NIE\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
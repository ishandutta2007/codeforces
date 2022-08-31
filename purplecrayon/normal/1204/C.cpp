#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

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

int adj[MAXN][MAXN];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) adj[i][j] = (i==j?0:INF);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c; cin >> c; if (c-'0') adj[i][j] = 1;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); 
            }
        }
    } //floyd-warshall
    int p; cin >> p;
    vector<int> a(p); for (auto& it : a) cin >> it, --it;
    vector<int> ans; ans.push_back(0);
    for (int i = 1; i < p; i++) if (adj[a[ans.back()]][a[i]] !=  i-ans.back()) ans.push_back(i-1);
    if (ans.back() != p-1) ans.push_back(p-1);
    cout << sz(ans) << '\n';
    for (auto it : ans) cout << (a[it]+1) << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
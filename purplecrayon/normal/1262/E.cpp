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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

template <typename T>
void pr(vector<vector<T>>& v){
    for (int i = 0; i < sz(v); i++){
        for (int j = 0; j < sz(v[0]); j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char c; cin >> c; g[i][j]=(c=='.');
    }
    vector<vector<int>> d(n, vector<int>(m, 1e9));
    queue<ar<int, 2>> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j]) q.push({i, j}), d[i][j]=0;
    for (int i = 0; i < n; i++) {
        if (!g[i][m-1]) q.push({i, m-1}), d[i][m-1]=1;
        if (!g[i][0]) q.push({i, 0}), d[i][0]=1;
    }
    for (int j = 1; j < m-1; j++){
        if (!g[n-1][j]) q.push({n-1, j}), d[n-1][j]=1;
        if (!g[0][j]) q.push({0, j}), d[0][j]=1;
    }
    while (sz(q)){
        auto c=q.front(); q.pop();
        for (int h = -1; h <= 1; h++) for (int k = -1; k <= 1; k++) if (h || k){
            int ni=c[0]+h, nj=c[1]+k;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && d[ni][nj] >= 1e9){
                d[ni][nj]=d[c[0]][c[1]]+1;
                q.push({ni, nj});
            }
        }
    }
    vector<vector<bool>> cg(n, vector<bool>(m));
    auto construct = [&](int t) -> void {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cg[i][j] = (d[i][j] <= t);
    };
    vector<vector<int>> nd(n, vector<int>(m));
    auto v = [&](int t) -> bool {
        construct(t);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) nd[i][j] = 1e9;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!cg[i][j]) q.push({i, j}), nd[i][j]=0;
        while (sz(q)){
            auto c=q.front(); q.pop();
            for (int h = -1; h <= 1; h++) for (int k = -1; k <= 1; k++) if (h || k){
                int ni=c[0]+h, nj=c[1]+k;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && nd[ni][nj] >= 1e9){
                    nd[ni][nj]=nd[c[0]][c[1]]+1;
                    q.push({ni, nj});
                }
            }
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j] != (nd[i][j] > t)) return false;
        return true;
    };
    int lo=-1, hi=1e6, mid=(lo+hi)/2;
    while (lo < mid && mid < hi){
        if (v(mid)) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    cout << lo << '\n';
    construct(lo);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cout << (cg[i][j]?'.':'X');
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
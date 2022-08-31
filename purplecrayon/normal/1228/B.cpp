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
const int MAXN = 1e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int st[MAXN][MAXN];
void solve(){
    int n, m; cin >> n >> m;
    vector<int> r(n), c(m); memset(st, -1, sizeof(st));
    for (auto& it : r) cin >> it; for (auto& it : c) cin >> it;
    for (int i = 0; i < n; i++){
        int x = r[i];
        for (int j = 0; j < x; j++) st[i][j] = 1;
        if (x < m) st[i][x] = 0;
    }
    for (int j = 0; j < m; j++){
        int x = c[j];
        for (int i = 0; i < x; i++){
            if (st[i][j] == 0) { cout << "0\n"; return; }
            st[i][j] = 1;
        }
        if (x < n){
            if (st[x][j] == 1) { cout << "0\n"; return; }
            st[x][j] = 0;
        }
    }
    ll ans=1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (st[i][j] == -1) ans = (2*ans)%MOD;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}
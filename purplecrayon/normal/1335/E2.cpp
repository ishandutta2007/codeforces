#include "bits/stdc++.h"
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it, --it;
    const int MAXC = 200;
    vector<int> ps[MAXC];
    for (int i = 0; i < MAXC; i++){
        ps[i].assign(n, 0);
        for (int j = 0; j < n; j++) ps[i][j] = (a[j]==i)+(j?ps[i][j-1]:0);
    }
    vector<int> loc[MAXC];
    for (int i = 0; i < n; i++) loc[a[i]].push_back(i);
    int ans=0;
    for (int col = 0; col < MAXC; col++) ans = max(ans, ps[col][n-1]);
    for (int col = 0; col < MAXC; col++){
        for (int i = 0, j = sz(loc[col])-1; i < j; i++, j--){
            int c=0, l = loc[col][i]+1, r = loc[col][j]-1;
            if (l <= r) for (int b = 0; b < MAXC; b++){
                c = max(c, ps[b][r]-(l?ps[b][l-1]:0));
            }
            // cout << l << ' ' << r << ' ' << col << ' ' << c << '\n';
            ans = max(ans, 2*(i+1)+c);
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}
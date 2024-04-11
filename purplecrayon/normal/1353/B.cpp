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
    int n, k; cin >> n >> k;
    min_pq<int> a; priority_queue<int> b;
    int sa=0, sb=0;
    for (int i = 0; i < n; i++){
        int c; cin >> c;
        a.push(c); sa+=c;
    }
    for (int i = 0; i < n; i++){
        int c; cin >> c;
        b.push(c); sb+=c;
    }
    int ans=sa;
    for (int i = 0; i < k; i++){
        int ca=a.top(); a.pop(); sa -= ca;
        int cb=b.top(); b.pop(); sb -= cb;
        a.push(cb); sa += cb;
        b.push(ca); sb += ca;
        ans = max(ans, sa);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}
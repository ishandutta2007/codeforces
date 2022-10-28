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
    priority_queue<pair<int, int>> pq;
    auto ins = [&](int l, int r){
        int len=r-l+1;
        if (len<=0) return;
        pq.emplace(len, -l);
    };
    auto get = [&](){
        auto c = pq.top(); pq.pop();
        c.second = -c.second;
        return c;
    };
    vector<int> ans(n);
    int v=1; ins(0, n-1);
    while (sz(pq)){
        auto c = get();
        int l = c.second, r = c.second+c.first-1, mid=-1;
        if ((r-l+1)&1){
            mid = (l+r)/2;
        } else {
            mid = (l+r-1)/2;
        }
        ans[mid]=v;
        ins(l, mid-1), ins(mid+1, r);
        v++;
    }
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}
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

int TT, ct=0;
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt=0;
    vector<vector<int>> idx(k);
    for (int i = 0; i < n; i++){
        idx[i%k].push_back(s[i]-'0');
        cnt+=s[i]-'0';
    }
    auto get = [&](vector<int>& v){
        int ans=cnt, mn=1, ps=0;
        for (int i = 0; i < sz(v); i++){
            ps += v[i];
            ans = min(ans, cnt-2*ps+i+mn);
            mn = min(mn, 2*ps-i);
            /*
            int cs=0;
            for (int j = i; j < sz(v); j++){
                cs += v[j];
                ans = min(ans, cnt-cs+j-i+1-cs);
                //cnt-2*(ps[i]-ps[j])+i-j -> min
                //cnt-2*ps[i]-2*ps[j]+i-j
                //-2*ps[j]-j + cnt-2*ps[i]+i
                
                //cnt-2*cs+j-i
                //cnt-2*(ps[i]-ps[j])+i-j
                //-2*ps[i]+2*ps[j]
            }
            */
        }
        return ans;
    };
    int ans=n;
    for (int i = 0; i < k; i++){
        ans=min(ans, get(idx[i]));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; TT=t;
    while (t--) ct++, solve();
}
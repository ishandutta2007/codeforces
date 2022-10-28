#include "bits/stdc++.h"
using namespace std;

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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<bool> suff[2], pre[2];
    for (auto x : {0,1}){
        suff[x].assign(n, false), pre[x].assign(n, false);
        for (int i = 0; i < n; i++){
            if (i) pre[x][i] = pre[x][i-1];
            pre[x][i] = pre[x][i] || (s[i]-'0' == x);
        }
        for (int i = n-1; i >= 0; i--){
            if (i < n-1) suff[x][i] = suff[x][i+1];
            suff[x][i] = suff[x][i] || (s[i]-'0' == x);
        }
    }
    while (q--){
        int l, r; cin >> l >> r, --l, --r;
        bool bad=1;
        if (l && pre[s[l]-'0'][l-1]) bad=0;
        if (r<n-1 && suff[s[r]-'0'][r+1]) bad=0;
        cout << (bad?no:yes);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}
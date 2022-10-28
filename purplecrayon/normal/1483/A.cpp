#include "bits/stdc++.h"
using namespace std;
 
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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m);
    for (auto& c : a){
        int k; cin >> k;
        c.resize(k);

        for (auto& it : c) cin >> it, --it;
    }
    vector<int> cnt(n), ans(m);
    for (int i = 0; i < m; i++){
        if (sz(a[i]) == 1) {
            cnt[a[i][0]]++;
            ans[i] = a[i][0];
        }
    }
    for (int i = 0; i < m; i++) if (sz(a[i]) > 1){
        int c=a[i][0];
        for (int v : a[i]) if (cnt[v] < cnt[c]) c=v;
        ans[i] = c; cnt[c]++;
    }
    if (*max_element(cnt.begin(), cnt.end()) > (m+1)/2) { cout << no; return; }
    cout << yes;
    for (int i = 0; i < m; i++) cout << ans[i]+1 << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}
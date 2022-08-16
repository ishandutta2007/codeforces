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
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> p(n), mx(m), s(n);
    for (auto& it : p) cin >> it;
    for (int i = 0; i < n; i++){
        int a; cin >> a, --a; s[i] = a;
        mx[a] = max(mx[a], p[i]);
    }
    int ans=0;
    for (int i = 0; i < k; i++){
        int c; cin >> c, --c;
        if (mx[s[c]] != p[c]) ans++;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
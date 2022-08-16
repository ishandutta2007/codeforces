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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n); 
    for (auto& it : a) cin >> it, --it;

    vector<vector<int>> loc(n);
    for (int i = 0; i < n; i++) loc[a[i]].push_back(i);


    int ans=0;
    for (int i = 0; i < n; i++) if (sz(loc[i])) {
        ans++; int cur=1;
        for (int j = 1; j < sz(loc[i]); j++){
            cur = max(0, cur-(loc[i][j]-loc[i][j-1]-1));
            ans += cur < 2, cur += cur < 2;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
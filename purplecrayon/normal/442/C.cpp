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
const int MAXN = 2e2+10, MAXM = 4e4+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    vector<ll> b(n, 0);
    
    int j = 0;
    ll ans=0;
    for (int i = 0; i < n; i++) {
        for (; j >= 2 && b[j-2] >= b[j-1] && a[i] >= b[j-1]; j--) {
            ans += min(b[j-2], a[i]);
        }
        b[j++] = a[i];
    }
    sort(b.begin(), b.begin()+j);
    for (int i = 0; i < j-2; i++) ans += b[i];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}
#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

int n;
ll a[MAXN], ps[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i], ps[i] = a[i] + (i ? ps[i-1] : 0);
    }
    ll ans=0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n-1; j++) {
            if (ps[j] > 2*a[i] + ps[i]) break;
            if (ps[j]-ps[i] == (a[i]^a[j+1])) ans++;
        }
        for (int j = i-1; j > 0; j--) {
            if (ps[i-1] > 2*a[i] + ps[j-1]) break;
            if (ps[i-1] > 2*a[j-1] + ps[j-1] && (ps[i-1]-ps[j-1])==(a[i]^a[j-1])) ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
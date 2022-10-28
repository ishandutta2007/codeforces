#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e6+10, ALP = 26, MAXL = 20, INF = 1e9+10, MOD = 1e9+7;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int aa; cin >> aa; a.push_back(aa);
    }
    ll ps = 0; int ans = -1;
    for (int i = 0; i < n; i++){
        ps += a[i];
        if (ps%x) ans = max(ans, i+1);
    }
    ps = 0;
    for (int i = n-1; i >= 0; i--){
        ps += a[i];
        if (ps%x) ans = max(ans, n-i);
    }
    cout << ans << "\n";
}
int main(){
    int t=1; cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

ll a[MAXN], b[MAXN];

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll mn1 = a[0], mn2 = b[0];
    for (int i = 0; i < n; i++) mn1 = min(mn1, a[i]), mn2 = min(mn2, b[i]);
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll d1 = a[i]-mn1, d2 = b[i]-mn2;
        ans += max(d1, d2);
    }
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}
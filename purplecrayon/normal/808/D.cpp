#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n;
ll a[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sm = accumulate(a, a+n, 0ll);
    if (sm&1) {
        cout << "NO\n";
        return;
    }
    sm /= 2;

    for (int rep = 0; rep < 2; rep++) {
        map<ll, int> cnt;
        for (int i = 0; i < n; i++) cnt[a[i]]++;
        ll ps = 0;
        if (cnt[sm]) {
            cout << "YES\n";
            return;
        }
        for (int i = 0; i < n; i++) {
            ps += a[i];
            cnt[a[i]]--;

            if (cnt[sm-ps]) {
                cout << "YES\n";
                return;
            }
        }
        reverse(a, a+n);
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<int> b(n); for (auto& c : b) cin >> c;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = n-2; i >= 0; i--) a[i] += a[i+1], b[i] += b[i+1];

    for (int i = 0; ; i++) {
        int cur_take = (n+i)-(n+i)/4;
        ll me = 0, he = b[max(0, n-cur_take)];
        if (cur_take >= i) me = 100*i+a[n-(cur_take-i)];
        else me = 100*cur_take;
        if (me >= he){ cout << i << '\n'; return; }
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}
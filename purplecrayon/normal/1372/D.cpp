#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

int n;
ll a[MAXN], dp[MAXN];

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n==1) { cout << a[0]; return; }
    vector<int> v;
    for (int nnn = 0; nnn < 2; nnn++){
        for (int i = 0; i < n; i+=2) v.push_back(a[i]);
        for (int i = 1; i < n; i+=2) v.push_back(a[i]);
    }
    int len = (n+1)>>1;
    ll sm = 0;
    for (int i = 0; i < len; i++) sm+=v[i];
    ll ans = sm;
    for (int i = 1; i+len-1 < (int)v.size(); i++){
        sm-=v[i-1]; sm+=v[i+len-1];
        ans = max(ans, sm);
    }
    cout << ans << "\n";
}
int main(){
    int t=1;// cin >> t;
    while (t--) solve();
}
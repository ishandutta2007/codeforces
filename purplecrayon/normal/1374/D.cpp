#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 2e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

ll a[MAXN];
map<ll, int> mp;

void solve(){
    int n; ll k; cin >> n >> k; mp.clear();
    for (int i = 0; i < n; i++){ 
        cin >> a[i], a[i]%=k, a[i]=(k-a[i])%k;
        if (a[i]) mp[a[i]]++; 
    }
    ll ans = 0;
    for (auto it : mp) ans = max((it.second-1)*k+it.first+1, ans);
    cout << ans << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}
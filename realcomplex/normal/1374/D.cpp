#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    map<int, int> cc;
    ll x;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x;
        if(x % k == 0) continue;
        x = k - (x % k);
        ans = max(ans, cc[x] * 1ll * k + x + 1);
        cc[x] ++ ;
    }
    cout << ans << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        solve();
    }
    return 0;
}
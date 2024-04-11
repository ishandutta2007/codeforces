#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = (ll)1e9 + 7;

int main(){
    fastIO;
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; i ++ ){
        ans = (ans * 1ll * i) % MOD;
    }
    ll pwr = 1;
    for(int i = 1; i < n; i ++ )
        pwr = (pwr * 2ll) % MOD;
    ans = (ans - pwr + MOD) % MOD;
    cout << ans;
    return 0;
}
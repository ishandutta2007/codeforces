#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        ll n, r;
        cin >> n >> r;
        ll ans = 0;
        if(n <= r) ans ++ ;
        ll k = min(n - 1, r);
        ans += k * 1ll * (k + 1) / 2ll;
        cout << ans << "\n";
    }
    return 0;
}
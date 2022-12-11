#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)2e5 + 9;
const ll MOD = 998244353;

int main(){
    fastIO;
    int n;
    cin >> n;
    ll a[n];
    ll vs;
    for(ll i = 0 ; i < n; i ++ ){
        cin >> a[i];
        vs = n - i;
        a[i] = (a[i] * 1ll * (i + 1));
        a[i] = (a[i] * 1ll * vs);
    }
    sort(a, a + n);
    ll b[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> b[i];
    }
    sort(b, b + n);
    ll res = 0;
    for(int i = 0 ; i < n; i ++ )
        a[i] %= MOD, b[i] %= MOD;
        
    for(int i = 0 ; i < n; i ++ ){
        res += (a[i] * 1ll * b[n - i - 1]) % MOD;
        res %= MOD;
    }
    cout << res;
    return 0;
}
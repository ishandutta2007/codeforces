#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int MOD = 998244353;

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int X[N];

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> X[i];
        if(X[i] == 1){
            cnt ++ ;
        }
    }
    if(cnt == 0 || cnt == n){
        cout << "0\n";
        return;
    }
    int has = 0;
    int li = n - cnt + 1;
    int ri = cnt;
    for(int i = 1; i <= n - cnt; i ++ ){
        if(X[i] == 1) has ++ ;
    }
    ll P = n * 1ll * (n - 1) / 2ll;
    P %= MOD;
    int res = 0;
    int C;
    int q;
    for(int iq = 1; iq <= has; iq ++ ){
        C = has - iq + 1;
        q = (C * 1ll * C) % MOD;
        q = (q * 1ll * powr(P, MOD - 2)) % MOD;
        q = powr(q, MOD - 2) % MOD;
        res = (res + q) % MOD;
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}
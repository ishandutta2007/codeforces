#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    ll f = 1, p2 = 1;
    for (int i = 2; i <= n; i++){
        f = (f*i)%MOD; p2 = (2*p2)%MOD;
    }
    cout << (f-p2+MOD)%MOD;
}

int main(){
    int t; t=1;
    while (t--) solve();
}
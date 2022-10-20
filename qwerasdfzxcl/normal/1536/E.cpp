#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
char matrix[2020][2020];

ll pw(ll a, int e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%s", matrix[i]);
    int cnt = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) if (matrix[i][j]=='#') cnt++;
    }
    ll ans = pw(2, cnt);
    if (cnt==n*m) ans--;
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
int n, dp1[2020][4040], dp2[2020][4040];
string S, T;

ll myabs(ll x){
    if (x<0) return -x;
    return x;
}

void solve(){
    int n;
    cin >> n >> S >> T;
    for (int i=1;i<n;i+=2){
        if (S[i]=='0') S[i] = '1';
        else if (S[i]=='1') S[i] = '0';

        if (T[i]=='0') T[i] = '1';
        else if (T[i]=='1') T[i] = '0';
    }
    string::iterator s = S.begin() - 1, t = T.begin() - 1;

    dp1[0][n] =  dp2[n+1][n] = 1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=n*2;j++){
            if (s[i]!='0' && t[i]!='1') dp1[i][j+1] = (dp1[i][j+1]+dp1[i-1][j])%MOD;
            if (s[i]!='0' && t[i]!='0') dp1[i][j] = (dp1[i][j]+dp1[i-1][j])%MOD;
            if (s[i]!='1' && t[i]!='1') dp1[i][j] = (dp1[i][j]+dp1[i-1][j])%MOD;
            if (s[i]!='1' && t[i]!='0') dp1[i][j-1] = (dp1[i][j-1]+dp1[i-1][j])%MOD;
        }
    }

    for (int i=n;i;i--){
        for (int j=0;j<=n*2;j++){
            if (s[i]!='0' && t[i]!='1') dp2[i][j+1] = (dp2[i][j+1]+dp2[i+1][j])%MOD;
            if (s[i]!='0' && t[i]!='0') dp2[i][j] = (dp2[i][j]+dp2[i+1][j])%MOD;
            if (s[i]!='1' && t[i]!='1') dp2[i][j] = (dp2[i][j]+dp2[i+1][j])%MOD;
            if (s[i]!='1' && t[i]!='0') dp2[i][j-1] = (dp2[i][j-1]+dp2[i+1][j])%MOD;
        }
    }

    ll ans = 0;
    for (int i=1;i<=n-1;i++){
        for (int j=-n;j<=n;j++){
            ans = (ans + myabs((ll)j * dp1[i][j+n] %MOD * dp2[i+1][-j+n] %MOD)) %MOD;
        }
    }

    printf("%lld\n", ans);

    for (int i=0;i<=n+1;i++){
        fill(dp1[i], dp1[i]+n*2+1, 0);
        fill(dp2[i], dp2[i]+n*2+1, 0);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
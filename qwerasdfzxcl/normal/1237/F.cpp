#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll mpow(ll x, ll y){
    if(!y) return 1;
    if(y%2) return mpow(x, y-1) * x % MOD;
    ll tmp = mpow(x, y/2);
    return tmp * tmp % MOD;
}

int n, m, k, rn, rm;
bool chk1[3602], chk2[3602];
ll DP1[3602][3602], DP2[3602][3602];
ll fact[100002], factInv[100002];
ll ans;

ll comb(ll x, ll y){
    if(x<y) return 0;
    return fact[x] * factInv[y] % MOD * factInv[x-y] % MOD;
}

void input();
void operate();

int main(){
    input();
    operate();
}

void input(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++) chk1[i] = 1;
    for(int j=1; j<=m; j++) chk2[j] = 1;
    for(int i=1; i<=k; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        chk1[x1] = chk1[x2] = 0;
        chk2[y1] = chk2[y2] = 0;
    }

    for(int i=1; i<=n; i++) if(chk1[i]) rn++;
    for(int i=1; i<=m; i++) if(chk2[i]) rm++;
}

void operate(){
    fact[0] = 1;
    for(int i=1; i<=100000; i++) fact[i] = fact[i-1] * i % MOD;
    factInv[100000] = mpow(fact[100000], MOD-2);
    for(int i=99999; i>=0; i--) factInv[i] = factInv[i+1] * (i+1) % MOD;

    DP1[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            DP1[i][j] = DP1[i-1][j];
            if(j && chk1[i] && chk1[i-1]) DP1[i][j] = (DP1[i][j] + DP1[i-2][j-1]) % MOD;
        }
    }
    DP2[0][0] = 1;
    for(int i=1; i<=m; i++){
        for(int j=0; j<=m; j++){
            DP2[i][j] = DP2[i-1][j];
            if(j && chk2[i] && chk2[i-1]) DP2[i][j] = (DP2[i][j] + DP2[i-2][j-1]) % MOD;
        }
    }

    for(int i=0; i<=m; i++){ ///  
        for(int j=0; j<=n; j++){ ///  
            ll c1 = DP1[n][i] * comb(rn-2*i, j) % MOD;
            ll c2 = DP2[m][j] * comb(rm-2*j, i) % MOD;
            ll c3 = fact[i] * fact[j] % MOD;
            ans += c1 * c2 % MOD * c3 % MOD;
            ans %= MOD;
        }
    }
    printf("%lld", ans);
}
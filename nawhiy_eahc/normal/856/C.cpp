#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll mpow(ll x, ll y){
    if(!y) return 1;
    if(y&1) return mpow(x, y-1) * x % MOD;
    ll tmp = mpow(x, y/2);
    return tmp * tmp % MOD;
}

ll modInverse(ll x){
    return mpow(x, MOD-2);
}

int testcase;
int n;
int a[2002];

int s, t;
vector<int> odd, even;

ll fact[5002];
ll factInverse[5002];
ll ans;

ll DP[2][2002][11]; /// DP[i][j][k]: i odd  , j plus  mod k  
ll DP2[2][2002][11];

void init();
ll comb(ll x, ll y){
    if(y<0 || x<y) return 0;
    return fact[x] * factInverse[y] % MOD * factInverse[x-y] % MOD;
}

int main(){
    init();
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &n);
        odd.clear(), even.clear();
        odd.push_back(-1), even.push_back(-1);
        for(int i=1; i<=n; i++){
            int tmp;
            scanf("%d", &tmp);
            a[i] = 0;
            bool chk = 0;
            while(tmp){
                if(!chk) a[i] += tmp%10;
                else a[i] -= tmp%10;
                chk = !chk, tmp /= 10;
            }
            if(!chk) a[i] *= -1;
            a[i] += 1100000;
            a[i] %= 11;

            if(chk) odd.push_back(a[i]);
            else even.push_back(a[i]);
        }

        s = (int)odd.size()-1;
        t = (int)even.size()-1;
        memset(DP, 0, sizeof(DP));
        memset(DP2, 0, sizeof(DP2));
        DP[0][0][0] = 1;
        DP2[0][0][0] = 1;

        for(int i=1; i<=s; i++){ ///  DP .
            for(int j=0; j<=s; j++){
                for(int k=0; k<11; k++){
                    /// minus
                    DP[1][j][k] += DP[0][j][(k+odd[i])%11];
                    DP[1][j][k] %= MOD;
                    /// plus
                    if(!j) continue;
                    DP[1][j][k] += DP[0][j-1][(k+11-odd[i])%11];
                    DP[1][j][k] %= MOD;
                }
            }

            for(int j=0; j<=s; j++) for(int k=0; k<11; k++){
                DP[0][j][k] = DP[1][j][k];
                DP[1][j][k] = 0;
            }
        }

        for(int i=1; i<=t; i++){ /// DP2 .
            for(int j=0; j<=t; j++){
                for(int k=0; k<11; k++){
                    /// minus
                    DP2[1][j][k] += DP2[0][j][(k+even[i])%11];
                    DP2[1][j][k] %= MOD;
                    /// plus
                    if(!j) continue;
                    DP2[1][j][k] += DP2[0][j-1][(k+11-even[i])%11];
                    DP2[1][j][k] %= MOD;
                }
            }

            for(int j=0; j<=t; j++) for(int k=0; k<11; k++){
                DP2[0][j][k] = DP2[1][j][k];
                DP2[1][j][k] = 0;
            }
        }

        ans = 0;
        for(int d=0; d<=t; d++){ ///   (+)  .  d .
            if(s==0 && d<t) continue;
            for(int e=0; e<11; e++){ ///    .  e .
                ll c1 = DP[0][(s+1)/2][e];
                ll c2 = DP2[0][d][(11-e)%11]; ///     11-e  .
                ll c3 = fact[d+s/2] * factInverse[s/2] % MOD; ///  plus  d, minus  t-d  .
                ll c4 = s==0 ? fact[t-d] : (fact[(t-d)+(s-1)/2] * factInverse[(s-1)/2]) % MOD;
                ans += c1*c2%MOD*c3%MOD*c4%MOD;
                ans %= MOD;
            }
        }

        ans *= fact[s/2];
        ans %= MOD;
        ans *= fact[(s+1)/2];
        ans %= MOD;
        printf("%lld\n", ans);
    }
}

void init(){
    fact[0] = 1;
    for(int i=1; i<=5000; i++) fact[i] = fact[i-1] * i % MOD;
    factInverse[5000] = modInverse(fact[5000]);
    for(int i=4999; i>=0; i--) factInverse[i] = factInverse[i+1] * (i+1) % MOD;
}
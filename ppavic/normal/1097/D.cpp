#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 52;
const int K = 1e4 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;

vector < pair < ll, ll >  > v;

ll n;
ll k, dp[N][K], inv[2 * N];

ll fastpot(ll x, ll y){
    ll sol = 1, base = x;
    for(; y ; y /= 2LL){
        if(y % 2) sol = sol * base % MOD;
        base = base * base % MOD;
    }
    return sol;
}

int main(){
    scanf("%lld %lld", &n, &k);
    for(ll i = 2;i * i <= n;i++){
        if(n % i) continue;
        ll k = 0;
        while(n % i == 0){
            k++; n/= i;
        }
        v.PB({i, k});
    }
    for(int i = 0;i<100;i++){
        inv[i] = fastpot(i, MOD - 2);
    }
    if(n != 1) v.PB({n, 1});
    ll ans = 1;
    for(int i = 0;i<v.size();i++){
        memset(dp, 0, sizeof(dp));
        dp[v[i].Y][0] = 1;
        for(int kk = 0;kk<k;kk++){
            for(int j = 0;j<=v[i].Y;j++){
                for(int z = 0;z<=j;z++){
                    dp[z][kk + 1] += dp[j][kk] * inv[j + 1] % MOD;
                    dp[z][kk + 1] %= MOD;
                }
            }
        }
        ll exp = 0;
        for(int j = 0;j<=v[i].Y;j++){
            exp += fastpot(v[i].X % MOD, j) * dp[j][k] % MOD;
            exp %= MOD;
        }
        ans = (ans * exp) % MOD;
    }
    printf("%d\n", ans);
    return 0;

}
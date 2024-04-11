#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int> pii;
typedef pair < int, pii> pip;
typedef pair < pii, int> ppi;
typedef vector < int> vi;

const int N = 405;
const int M = 1e6 + 500;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int LOG = 20;
const int OFF = (1 << LOG);
const double PI = 3.1415926535;
const double EPS = 1e-9;

ll n;
ll dp[N][N];

ll f(ll n, ll k){
    if(dp[n][k] != -1) return dp[n][k];
    if(k < 0) return 0;
    if(k == 0) return 1;
    if(n == 1) return int(k == 1);
    ll ret = 0;
    for(int j = 0;j<=k - 1;j++){ // 1
        ret += f(n - 1, j) * f(n - 1, k - j - 1) % MOD;
        ret %= MOD;
    }
    for(int j = 0;j<=k;j++){ // 4
        ret += f(n - 1, j) * f(n - 1, k - j)  % MOD * (2 * k + 1) % MOD;
        ret %= MOD;
    }
    for(int j = 0;j<=k + 1;j++){ // 2
        ret += f(n - 1, j) * f(n - 1, k + 1 - j) % MOD * k % MOD * (k + 1) % MOD;
        ret %= MOD;
    }
    return dp[n][k] = ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%I64d", &n);
    printf("%I64d\n", f(n, 1));

}
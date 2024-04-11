#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first 
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int MOD = 998244353;

int unit[N];
int fac[N];
int fac2[N];
bool vis[N];
int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int pick(int n, int k){
    int res = fac[n];
    res = (res * 1ll * powr(fac[k], MOD - 2)) % MOD;
    res = (res * 1ll * powr(fac[n - k], MOD - 2)) % MOD;
    return res;
}

int f(int n, int k){ // pick k adjacent pairs from n
    return pick(n - k, k);
}

void solve(){
    int n;
    cin >> n;
    unit[0]=1;
    fac[0] = 1;
    fac2[0] = 1;
    for(int q = 1; q <= n; q ++ ){
        fac2[q] = (fac2[q - 1] * 1ll * (4 * q - 2)) % MOD;
    }
    for(int i = 1; i <= n; i ++ ){
        unit[i] = unit[i - 1];
        if(i > 1) unit[i] = (unit[i] + (unit[i - 2] * 1ll * (i - 1)) % MOD) % MOD;
        fac[i]=(fac[i-1] * 1ll * i) % MOD;
    }
    int res = 0;
    int cur;
    for(int quad = 0; quad * 4 <= n; quad ++ ){
        cur = f(n, quad * 2);
        cur = (cur * 1ll * fac2[quad]) % MOD;
        cur = (cur * 1ll * unit[n - quad * 4]) % MOD;
        res = (res + cur) % MOD;
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ) solve();
    return 0;
}
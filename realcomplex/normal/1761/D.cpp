#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e6 + 10;
const int MOD = (int)1e9 + 7;
int fac[N];
int inv[N];

int powr(int n, int k){
    if(k == 0) return 1;
    int p = powr(n, k / 2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1) p = (p * 1ll * n) % MOD;
    return p;
}

int pick(int n, int k){
    if(k < 0) return 1;
    if(k > n) return 0;
    int res = fac[n];
    res = (res * 1ll * inv[k]) % MOD;
    res = (res * 1ll * inv[n - k]) % MOD;
    return res;
}

void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
}
int g(int x){
    return __builtin_popcount(x);
}
int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    fac[0]=1;
    inv[0]=1;
    inv[1] = 1;
    for(int i = 1; i < N; i ++ ){
        fac[i]=(fac[i-1]*1ll*i)%MOD;
        if(i > 1){
            inv[i] = (MOD - (MOD/i) * 1ll * inv[MOD % i] % MOD) % MOD;
        }
    }
    for(int i = 1; i < N ; i ++){
        inv[i] = (inv[i] * 1ll * inv[i - 1]) % MOD;
    }
    int sz;
    int pos;
    int res;
    int ret = 0;
    if(k == 0){
        cout << powr(3, n) << "\n";
        return 0;
    }
    for(int a = 1; a <= k && a - 1 <= n - k; a ++ ){
        sz = pick(k - 1, a - 1);
        pos = pick(n - k, a - 1);

        add(ret, (((sz * 1ll * pos) % MOD) * 1ll * powr(3, n - 2 * a + 1))% MOD);
        pos = pick(n - k, a);
        add(ret, (((sz * 1ll * pos) % MOD) * 1ll * powr(3, n - 2 * a))% MOD);
    }
    cout << ret << "\n";
    return 0;
}
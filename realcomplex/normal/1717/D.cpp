#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
int pwr[N];
int fac[N];

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

int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    fac[0]=1;
    for(int i = 1; i <= n; i ++ ){
        fac[i]=(fac[i-1]*1ll*i)%MOD;
    }
    int soln = 0;
    for(int i = 0 ; i <= min(n, k); i ++ ){
        soln = (soln + pick(n, i)) % MOD;
    }
    cout << soln << "\n";
    return 0;
}
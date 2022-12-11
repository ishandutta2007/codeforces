#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = 998244353;
const int N = (int)3e5 + 10;
int fac[N];
int powr(int n, int k){
    if(k == 0)
        return 1;
    int p = powr(n,k/2);
    p = (p * 1ll * p) % MOD;
    if(k % 2 == 1)
        p = (p * 1ll * n) % MOD;
    return p;
}

int main(){
    fastIO;
    fac[0]=1;
    for(int i = 1; i < N;i ++ ){
        fac[i]=(fac[i-1]*1ll*i)%MOD;
    }
    int n;
    cin >> n;
    vector<ll> aa(2*n);
    for(int i = 0; i < 2*n; i ++ ){
        cin >> aa[i];
    }
    sort(aa.begin(), aa.end());
    ll sum = 0;
    for(int i = 0 ; i < 2 * n; i ++ ){
        if(i < n) sum -= aa[i];
        else sum += aa[i];
    }
    sum %= MOD;
    ll cn = fac[n*2];
    cn = (cn * 1ll * powr(fac[n], MOD-2)) % MOD;
    cn = (cn * 1ll * powr(fac[n], MOD-2)) % MOD;
    cout << (sum * 1ll * cn) % MOD << "\n";
    return 0;
}
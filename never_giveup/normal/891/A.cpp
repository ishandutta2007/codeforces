#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;

typedef long long ll;

typedef long double ld;

int ARND = 239, BRND = 281, CRND = 5812, XRND = 512823, YRND = 5128, MODRND = 1e9 + 993;

int myrand(){
    int ZRND = (XRND * (ll)ARND + YRND * (ll)BRND + CRND) % MODRND;
    XRND = YRND;
    YRND = ZRND;
    return ZRND;
}

const ll llinf = 2e18 + 100;

const int mod = 1e9 + 7;

int bpow(int x, ll y){
    if (y == 0)
        return 1;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % mod;
    if (y & 1)
        ret = (ret * (ll)x) % mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, mod - 2)) % mod;
}

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300;

int n;

int answer = inf;

int a[maxn];

int main()
{
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int z = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], z += (a[i] == 1);
    if (z){
        cout << n - z;
        return 0;
    }
    for (int i = 0; i < n; i++){
        int g = a[i];
        if (g == 1){
            answer = 0;
        }
        for (int j = i + 1; j < n; j++){
            g = __gcd(g, a[j]);
            if (g == 1)
                answer = min(answer, j - i);
        }
    }
    if (answer == inf)
        cout << -1;
    else
        cout << answer + n - 1;
}
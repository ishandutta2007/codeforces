#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int mod = 1e9 + 7;
const int nax = 1e6 + 5;
ll n, m, k;

ll pp(ll a, ll b){
    if(b == 0) return 1;
    ll ans = pp(a,b/2);
    ans*=ans;
    ans%=mod;
    if(b&1){
        ans *= a;
        ans %= mod;
    }
    return ans;
}

ll f[nax];
ll iw[nax];

void prep(){
    f[0] = 1;
    iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = f[i - 1] * i;
        f[i] %= mod;
        iw[i] = pp(f[i], mod - 2);
    }
}

ll nk(ll n, ll k){
    ll res = f[n];
    res *= iw[k];
    res %= mod;
    res *= iw[n - k];
    res %= mod;
    return res;
}

ll pepe[nax];

void solve(){
    cin >> n >> m >> k;
    ll mno = 1;
    ll ans = 0;
    if (n == m){
        ll ans = k * n;
        ans %= mod;
        cout << ans << "\n";
        return;
    }
    m=n-m;
    for(int i=1;i<=n;i++){
        mno *= pp(2, mod - 2);
        mno %= mod;
        if(i < m) continue;
        ll cur = nk(i-1, m-1);
        ll wynik = mno * cur;
        wynik %= mod;
        wynik *= k;
        wynik %= mod;
        wynik *= (n - i);
        wynik %= mod;
        ans += wynik;
        ans %= mod;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
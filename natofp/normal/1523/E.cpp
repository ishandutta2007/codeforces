#include <bits/stdc++.h>
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

const int nax = 1e5 + 5;
const int mod = 1e9 + 7;

ll pp(ll a, ll b){
    if(b == 0) return 1;
    ll ans = pp(a, b / 2);
    ans *= ans;
    ans %= mod;
    if(b & 1) ans *= a;
    ans %= mod;
    return ans;
}

ll inv(ll a){
    return pp(a, mod - 2);
}

ll f[nax];
ll inw[nax];

void prep(){
    f[0] = 1;
    inw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = f[i - 1] * i;
        f[i] %= mod;
        inw[i] = inv(f[i]);
    }
}

ll binom(ll n, ll k){
    ll ans = f[n];
    ans *= inw[k];
    ans %= mod;
    ans *= inw[n - k];
    ans %= mod;
    return ans;
}

ll p[nax];

void solve(){
    int n,k; cin >> n >> k;
    ll naj = 1 + (n - 1) / k;
    for(int i=0;i<nax;i++) p[i] = 0;
    for(int i=1;i<=naj;i++){
        // >= i
        ll szansa = f[n] * inw[n - i];
        szansa %= mod;
        szansa = inv(szansa);
        szansa %= mod;
        // szansa na konkretna sekwencje dlugosci i
        szansa *= f[i];
        szansa %= mod;

        ll ile = binom(n - (i - 1) * (k - 1), i);
        ile *= szansa;
        ile %= mod;
        p[i] = ile;
        p[i] %= mod;
    }
    ll ans = 0;
    for(int i=1;i<=naj;i++){
        ll ss = p[i] - p[i + 1];
        ss += mod;
        ss %= mod;
        ans += ss * i;
        ans %= mod;
    }
    cout << (ans + 1) % mod << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
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
#define mt make_tuple

using namespace std;

const int nax = 6e5 + 5;
const int mod = 1e9 + 7;

ll pp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

ll inv(ll a){
    return pp(a, mod - 2);
}

ll f[nax];
ll iw[nax];

void prep(){
    f[0] = iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = f[i - 1] * i;
        f[i] %= mod;
        iw[i] = inv(f[i]);
    }
}

ll nk(int n, int k){
    ll ans = f[n];
    ans *= iw[k];
    ans %= mod;
    ans *= iw[n - k];
    ans %= mod;
    return ans;
}

int a[nax];
int n;

void solve(){
    prep();
    cin >> n;
    for(int i=0;i<=n;i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i=0;i<=n;i++){
        /*for(int j=0;j<a[i];j++){
            ans += nk(i + j, i);
            ans %= mod;
        }*/
        ans += nk(i + a[i], i + 1);
        ans %= mod;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}
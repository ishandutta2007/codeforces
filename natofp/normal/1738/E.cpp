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

const int nax = 5e5 + 5;
int a[nax];
int n;
const int mod = 998244353;

ll pp(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}

ll f[nax];
ll iw[nax];

void prep(){
    f[0] = iw[0] = 1;
    for(int i=1;i<nax;i++){
        f[i] = (f[i - 1] * i) % mod;
        iw[i] = pp(f[i], mod - 2);
    }
}

ll binom(ll n, ll k){
    if(k < 0 || n < 0 || k > n) return 0LL;
    ll ans = f[n];
    ans *= iw[k];
    ans %= mod;
    ans *= iw[n - k];
    ans %= mod;
    return ans;
}

ll calc_options(ll one, ll two){
    ll ans = 0;
    for(int i=0;i<=min(one, two)+1;i++){
        ans += binom(one + 1, i) * binom(two + 1, i);
        ans %= mod;
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int l = 1;
    int r = n;
    ll z1 = 0;
    ll z2 = 0;
    while(l <= r && a[l] == 0){
        l++; z1++;
    }
    while(l <= r && a[r] == 0){
        r--; z2++;
    }
    if(l > r){
        cout << pp(2, n - 1) << "\n";
        return;
    }
    ll res = 1;
    while(l <= r){
        if(l == r) break;
        ll s1 = a[l];
        ll s2 = a[r];
        l++;
        r--;
        while(s1 != s2 && l <= r){
            if(s1 < s2){
                s1 += a[l];
                l++;
            }
            else{
                s2 += a[r];
                r--;
            }
        }
        if(s1 == s2){
            int b1 = 0;
            int b2 = 0;
            while(l <= r){
                if(a[l] == 0){
                    b1++;
                    l++;
                }
                else if(a[r] == 0){
                    b2++;
                    r--;
                }
                else break;
            }
            if(l > r){
                // srodek zer
                res *= pp(2, b1 + b2 + 1);
                res %= mod;
                break;
            }
            else{
                res *= calc_options(b1, b2);
                res %= mod;
            }
        }
        else{
            // chyba nic?
            break;
        }
    }
    // domnozyc !

    ll xd = 0;
    for(int i=0;i<=min(z1, z2);i++){
        ll cur = binom(z1, i) * binom(z2, i);
        cur %= mod;
        xd += cur;
        xd %= mod;
    }
    res *= xd;
    res %= mod;
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
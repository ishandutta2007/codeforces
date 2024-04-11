#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
ll n,m,k,T,q;

ll FAC[100001] = {0};
ll INV[100001] = {0};

ll KPOW[100001] = {0};
bool KC[100001] = {0};

ll mod(ll i){
    if(i < 0)return mod(big-mod(-i));
    if(i < big)return i;
    return i%big;
}

ll upp(ll i, ll j){
    if(j == k && i < 100001){
        if(KC[i])return KPOW[i];
    }
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    ll ans;
    if(j%2 == 0){
        ans = mod(h*h);
    }
    else{
        ans= mod(mod(h*h)*i);
    }
    if(j == k && i < 100001){
        KC[i] = 1;
        KPOW[i] = ans;
    }
    return ans;
}

ll bin(ll i, ll j){
    if(i < j || j < 0 || i < 0)return 0;
    return mod(mod(FAC[i]*INV[i-j])*INV[j]);
}

ll bigbin(ll i, ll j){
    ll num = 1;
    for(int c1 = 0; c1 < j; c1++){
        num *= (i-c1);
        num = mod(num);
    }
    return mod(num*INV[j]);
}

ll f(ll l){
    ll mi = 1;
    ll ans = 0;
    for(int c1 = l; c1 > 0; c1--){
        ans += mi*bin(l,l-c1)*upp(c1,k);
        mi *= -1;
        ans = mod(ans);
    }
    return ans;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    ll t = 1;
    for(int c1 = 0; c1 < 10001; c1++){
        FAC[c1] = t;
        INV[c1] = upp(t,big-2);
        t *= c1+1;
        t = mod(t);
    }

    cin >> n >> k;
    ll ans = 0;
    for(int c1 = 1; c1 <= k; c1++){
       // cout << bigbin(n,c1) << " " << upp(2,n-c1) << " " << f(c1) << "\n";
        ans += mod(bigbin(n,c1)*upp(2,n-c1))*f(c1);
        ans = mod(ans);
    }
    cout << ans << "\n";
    return 0;
}
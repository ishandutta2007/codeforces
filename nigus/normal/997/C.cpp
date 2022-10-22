#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;



ll n,m,k,T;

ll FAC[1000001] = {0};
ll INV[1000001] = {0};

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0){
        return (h*h)%mod;
    }
    return (((h*h)%mod)*i)%mod;
}

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    ll enu = FAC[i];
    ll den = (INV[j]*INV[i-j])%mod;
    return (enu*den)%mod;
}

ll three[1000001] = {0};

void setup(){
    ll t = 1;
    for(int c1 = 0; c1 < 1000001; c1++){
        FAC[c1] = t;
        t*=c1+1;
        t%=mod;
    }
    INV[1000000] = upp(FAC[1000000],mod-2);
    for(int c1 = 999999; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1]*(c1+1))%mod;
    }
    t = 1;
    for(int c1 = 0; c1 < 1000001; c1++){
        three[c1] = t;
        t*=3;
        t%=mod;
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;
    setup();
    cin >> n;
    ll NX = 0;
    for(int c1 = 0; c1 < n-1; c1++){
        NX += three[c1];
        NX %= mod;
    }
    NX *= upp(three[n-1],mod-2);
    NX %= mod;
    NX *= 2;
    NX %= mod;

    ll f1 = upp(3,n*n-n+1);

    ll ans = f1;
    for(int c1 = 1; c1 < n; c1++){
        f1 *= NX;
        f1 %= mod;
        ans += f1;
        ans %= mod;
    }


    ll ans2 = 0;
    ll mi = -1;
    for(int c1 = 1; c1 <= n; c1++){

        ll temp = (bin(n,c1)*(mod+mi))%mod;
        ll sx = three[n-c1];
        ll thing = upp(sx-1,n)-upp(sx,n);
        thing += 10*mod;
        thing %= mod;
        ans2 += (temp*thing)%mod;
        mi *= -1;
    }
    ans2 *= 3;
    ans2 %= mod;

   // cout << ans << " " << ans2 << " " << NX << "\n";

    cout << (2*ans-ans2+10*mod)%mod << "\n";

    return 0;
}
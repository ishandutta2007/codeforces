#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 5001;

ll upp(ll i, ll j){
    if(j==0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%mod;
    return (((h * h)%mod)*i)%mod;
}

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll bin(ll i, ll j){
    if(i < j || j < 0 || i < 0)return 0;
    ll a = (FAC[i] * INV[j])%mod;
    return (a*INV[i-j])%mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        INV[c1] = upp(t, mod-2);
        t *= ll(c1+1);
        t %= mod;
    }

    cin >> n >> k;
    string s;

    cin >> s;

    if(k == 0){
        cout << "1\n";
        return 0;
    }

    vi ones;
    rep(c1,0,n){
        if(s[c1] == '1')ones.push_back(c1);
    }

    ll ans = 0;
    ll o = sz(ones);
    if(o < k){
        ans = 1;
    }
    rep(c1,0,o-k+1){
        ll z2 = ones[c1+k-1] - ones[c1] + 1;
        if(c1 == 0){
            z2 += ones[0];
        }
        else{
            z2 += ones[c1]-ones[c1-1]-1;
        }
        ll z = z2;
        if(c1 == o-k){
            z += n-1-ones[c1+k-1];
        }
        else{
            z += ones[c1+k]-1-ones[c1+k-1];
        }
        ans += bin(z, k);
        if(c1 > 0){
            ans += mod - bin(z2-1, k-1);
        }
        ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}
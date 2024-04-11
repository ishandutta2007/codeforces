#pragma GCC optimize("O3")   //
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

const ll MAXN = 400001;


ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0){
        return (h*h)%big;
    }
    return (((h*h)%big)*i)%big;
}

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    return(((FAC[i]*INV[j])%big)*INV[i-j])%big;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        INV[c1] = upp(t,big-2);
        t *= ll(c1+1);
        t %= big;
    }

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        ll ans = 0;
        rep(c2,1,n+1){
            ll c1 = c2;
            if(n-c1*k+c1+k-1 < 0)break;
            a = bin(n-c1*k+c1+k-1, c1);
            b = bin(n,c1);


            b = upp(b,big-2);
            ans += a*b;
            ans %= big;
        }
        cout << (ans+1)%big << "\n";
    }

    return 0;
}
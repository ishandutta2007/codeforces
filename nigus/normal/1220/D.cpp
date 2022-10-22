#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 300001;



ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

vl A;

ll TP[66] = {0};
vl ANS;

vector<vl> TT(66, vl());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    ll g = 1;
    cin >> n;
    rep(c1,0,n){
        cin >> a;
        if(c1 == 0){
            g = a;
        }
        else{
            g = gcd(g,a);
        }
        A.push_back(a);
    }

    rep(c1,0,n){
        //A[c1] /= g;
    }

    ll ans = n;

    rep(c1,0,n){
        a = 0;
        b = A[c1];
        while(A[c1]%2 == 0){
            A[c1] /= 2;
            a++;
        }
        //cerr << a << "\n";
        TT[a].push_back(b);
        TP[a]++;
    }


    ll r = 0;
    rep(c1,0,65){
        if(n-TP[c1] < ans){
            ans = n-TP[c1];
            r = c1;
        }
        //ans = min(ans, n-TP[c1]);
    }
    cout << ans << "\n";

    rep(c1,0,65){
        if(c1 == r)continue;
        rep(c2,0,sz(TT[c1])){
            cout << TT[c1][c2] << " ";
        }
    }
    cout << "\n";

    return 0;
}
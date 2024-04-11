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

const int MAXN = 100001;
const int MAXT = 100001;

ll xo(ll a, ll b, bool sub){
    ll res = 0;
    ll hej = 1;
    rep(c1,0,60){
        ll temp = 0;
        temp += a%k;
        if(sub){
            temp -= b%k;
        }
        else{
            temp += b%k;
        }
        temp += k;
        temp %= k;
        res += temp*hej;
        hej *= k;
        a /= k;
        b /= k;
        if(a == 0 && b == 0)break;
    }
    return res;
}

int ask(ll x){
    cout << x << "\n";
    fflush(stdout);
    int r;
    cin >> r;
    return r;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> k;
        ll tot = 0;
        rep(c1,0,n){
            ll x = c1;
            int r = ask(xo(x, tot, 1));
            if(r == 1)break;
            tot = xo(tot, xo(x, tot, 1), 0);
        }
    }

    return 0;
}
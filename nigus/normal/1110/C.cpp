#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

unordered_map<ll,ll> M;

ll hard[25] = {1
,1
,5
,1
,21
,1
,85
,73
,341
,89
,1365
,1
,5461
,4681
,21845
,1
,87381
,1
,349525
,299593
,1398101
,178481
,5592405
,1082401
,22369621};

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

ll brute(ll x){

    ll ans = 0;
    for(int c1 = 1; c1 < x; c1++){
        ans = max(ans, gcd((x^c1), (x&c1)));
    }
    return ans;
}

ll two(ll x){
    ll t = 2;
    while(t <= x){
        t *= 2;
    }
    return t-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;


    ll t = 2;
    for(ll c1 = 0; c1 < 26; c1++){
        if(c1 > 0)M[t-1] = hard[c1-1];
       // if(c1 > 0)cerr << M[t-1] << "\n";
        t *= 2;
    }

    cin >> q;
    for(int c1 = 0; c1 < q; c1++){
        cin >> a;

        if(M.find(a) != M.end()){
            cout << M[a] << "\n";
        }
        else{
            cout << two(a) << "\n";
        }
    }

    return 0;
}
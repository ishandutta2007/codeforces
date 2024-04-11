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
 
const int MAXN = 2000006;
 
ll x;

ll LOG(ll m){
    if(m == 0)return 1;
    ll res = 0;
    while(m > 0){
        res++;
        m /= 10;
    }
    return res;
}

map<ll,ll> DP;

ll dp(ll m){
    //cerr << m << "\n";
    if(LOG(m) == n)return 0;
    if(LOG(m) > n)return big;
    if(DP.find(m) != DP.end())return DP[m];
    vector<bool> digs(10, 0);
    ll m2 = m;
    while(m2 > 0){
        digs[m2%10] = 1;
        m2 /= 10;
    }
    ll res = big;
    rep(d,2,10){
        if(digs[d]){
            res = min(res, 1+dp(m*ll(d)));
        }
    }

    DP[m] = res;
    return res;

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c,d,e;
    cin >> n >> x;
    
    ll ans = dp(x);
    if(ans > 128119){
        cout << "-1\n";

    }else{
        cout << ans << "\n";
    }

    return 0;
}
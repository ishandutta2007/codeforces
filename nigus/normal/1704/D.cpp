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

const ll MAXN = 200006;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        vector<pll> X;
        rep(c1,0,n){
            vl A;
            ll x = 0;
            rep(c2,0,m){
                cin >> a;
                x += ll(c2+1)*a;
            }
            X.push_back({x,c1});
        }
        sort(all(X));
        cout << X.back().second+1 << " " << X.back().first-X[0].first << "\n";
    }

    return 0;
}
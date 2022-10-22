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

const int MAXN = 200001;

ll solve(ll i, ll x){
    if(i == 1)return 0;
    if(x%2 == 1)return x/2;
    ll h1 = i/2;
    ll h2 = i-h1;
    if(h1 == h2)return h1 + solve(h1, x/2);
    return h1 + solve(h2, (x/2+1)%h2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> q;
    rep(c1,0,q){
        cin >> a;
        if(a == n){
            cout << solve(n, 0)+1 << "\n";
        }
        else{
            cout << solve(n, a)+1 << "\n";
        }
    }

    return 0;
}
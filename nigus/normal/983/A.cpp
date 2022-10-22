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

ll n,m,q,p;
ll T;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> T;
    //T = 100000;
    for(int c4 = 0; c4 < T; c4++){
        cin >> p >> q >> b;
        //p = 12;
        //q = (1 << 60);
        //b = 2;
        q /= gcd(p,q);
        ll g = gcd(q,b);
        while(g > 1 && q > 1){
            q /= g;
            if(q%g != 0){
                g = gcd(q,b);
            }
        }
        if(q == 1 || p == 0){
            cout << "Finite\n";
        }
        else{
            cout << "Infinite\n";
        }
    }

    return 0;
}
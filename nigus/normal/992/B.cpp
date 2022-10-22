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

ll n,m,k,q,T;

ll l,r,x,y;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> l >> r >> x >> y;

    ll ans = 0;

    if(y%x != 0){
        cout << "0\n";
        return 0;
    }
    for(ll c1 = 1; c1*c1 <= y/x; c1++){
        if((y/x)%c1 == 0){
            a = c1;
            b = (y/x)/c1;
            if(gcd(a,b) == 1 && (min(x*a,x*b) >= l && max(x*a,x*b) <= r)){
                ans += 1 + (a != b);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
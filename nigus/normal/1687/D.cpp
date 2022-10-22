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
 
const ll MAXN = 2000006;
 
vl A;

set<ll> S;

ll geq(ll x){
    auto it = S.lower_bound(x);
    if(it == S.end())return -1;
    if((*it) < x)it++;
    if(it == S.end())return -1;
    return (*it);
}

ll leq(ll x){
    auto it = S.lower_bound(x);
    if(it == S.end()){
        it--;
        if((*it) <= x)return (*it);
        return -1;
    }
    if(it == S.begin()){
        if((*it) <= x)return (*it);
        return -1;
    }

    if((*it) > x)it--;

    return (*it);
}

ll solve(ll d){
    ll L = max(0ll, d*d-A[0]);
    ll R = d*d-A[0] + d;

    ll bucket = d;


    R = d*d+d-leq(A[0]+d);


  //  cerr <<d << "  : "<< L << " " << R << "   hmm\n";
    if(R < L)return big*big;
   // cerr <<d << "  : "<< L << " " << R << "   hmm\n";
    ll start = d*d+d+1;
    ll inc = 2*d+2;
    ll offset = A[0]-d*d;


    for(ll d2 = 1; d2 <= MAXN; d2++){
        if(start+offset > A[n-1])break;

        ll x = geq(start+offset);
        ll y = leq(start+inc+offset-1);
        if(x == -1)continue;
        ll goal = (d+d2)*(d+d2);

        L = max(L, goal-x);
        R = min(R, goal+d+d2-y);


        if(L > R)return big*big;


        start += inc;
        inc += 2;
    }

    

    return L;

}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
 
    ll a,b,c,d,e;
    
    cin >> n;

    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        S.insert(a);
    }

    ll ans = big*big;

    for(ll d = 0; d <= MAXN; d++){
        ll temp = solve(d);
        if(temp < ans){
            ans = temp;
            break;
        }
    }
    cout << ans << "\n";
 
    return 0;
}
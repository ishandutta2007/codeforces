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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (ll(DD(eng))*1000000000 + ll(DD(eng)))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

bool mark[1000000] = {0};

unordered_map<ll,ll> M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    ll x;
    bool even = 0;
    bool odd = 0;
    cin >> n;
    vl A;
    rep(c1,0,n){
        cin >> a;
        if(a%2==0)even=1;
        if(a%2==1)odd=1;
        A.push_back(a);
    }
    if(odd && even){
        sort(all(A));
    }
    rep(c1,0,n){
        cout << A[c1] << " ";
    }

    return 0;
}
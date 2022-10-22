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

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 1001;

vl A;

string win[2] = {"sjfnb", "cslnb"};
bool flipped = 0;

bool valid(){
    rep(c1,0,n){
        if(A[c1] < 0 || (c1 > 0 && A[c1] == A[c1-1])){
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }
    sort(all(A));
    rep(c1,1,n){
        if(!flipped && A[c1] == A[c1-1]){
            flipped = 1;
            A[c1-1]--;
        }
    }

    if(!valid()){
        cout << win[flipped] << "\n";
        return 0;
    }

    ll moves = 0;
    rep(c1,0,n){
        moves += A[c1]-ll(c1);
    }

    cout << win[1^flipped^(moves%2)] << "\n";

    return 0;
}
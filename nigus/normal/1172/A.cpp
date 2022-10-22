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

const ll MAXN = 300001;

vl A,B;
queue<ll> Q;

bool bag[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;
    ll worst = 0;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        bag[a] = 1;
       // if(a != 0)worst = max(worst, c1-a+2);

    }
    //ll clean = n+worst;
    rep(c1,0,n){
        cin >> a;
        B.push_back(a);
        Q.push(a);
        if(a != 0)worst = max(worst, c1-a+2);
     //   cerr << c1-a+2 << "  " << a << "\n";
    }
    ll clean = n+worst;
    ll good = n-B[n-1];
    bool yes = 1;
    rep(c1,0,good){
        if(B[sz(B)-1] == n)break;
        if(bag[B[sz(B)-1]+1]){
            bag[B[c1]] = 1;
            B.push_back(B[sz(B)-1]+1);
        }
        else{
            yes = 0;
            break;
        }
    }
    rep(c1,0,n){
        if(c1+good >= sz(B)){
            yes = 0;
            break;
        }
        if(B[c1+good] != c1+1){
            yes = 0;
            break;
        }
    }
    if(!yes){
        good = big;
    }

    cout << min(good, clean) << "\n";




    return 0;
}
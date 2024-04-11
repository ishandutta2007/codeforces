#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

const int MAXN = 2001;

ll F[1000001] = {0};

vector<pii> A;

bool asc(vi & B){
    rep(c1,1,sz(B)){
        if(B[c1] > B[c1-1])return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    ll ans = n*n;
    rep(c1,0,n){
        cin >> b;
        vi B;
        rep(c2,0,b){
            cin >> a;
           // a = random2()%1000001;
            B.push_back(a);
        }
        if(!asc(B)){
            A.push_back({B[0], B[b-1]});
            F[B[0]]++;
        }
    }
    rep(c1,1,1000001){
        F[c1] += F[c1-1];
    }

    trav(y, A){
        ans -= F[y.second];
    }

    cout << ans << "\n";

    return 0;
}
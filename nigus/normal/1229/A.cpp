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

const ll MAXN = 7001;

ll A[MAXN] = {0};
ll B[MAXN] = {0};
bool better[MAXN][MAXN] = {0};

ll ans = 0;

bool gone[MAXN] = {0};
ll lft = 0;

int BB[MAXN] = {0};

bool rm(){
    if(lft == 0)return 0;
    ll rid = -1;
    rep(c1,0,n){
        if(BB[c1] == lft-1 && !gone[c1]){
            rid = c1;
            break;
        }
    }
    if(rid == -1)return 0;
    gone[rid] = 1;
    ans -= B[rid];
    lft--;
    rep(c1,0,n){
        if(better[c1][rid])BB[c1]--;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        A[c1] = a;
    }
    rep(c1,0,n){
        cin >> a;
        B[c1] = a;
        ans += a;
    }

    rep(c1,0,n){
        rep(c2,0,n){
            if((A[c1]|A[c2]) > A[c2])better[c1][c2] = 1;
            BB[c1] += better[c1][c2];
        }
    }

    lft = n;

    while(1){
        if(!rm())break;
    }


    cout << ans << "\n";


    return 0;
}
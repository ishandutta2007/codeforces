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

vector<vl> C(MAXN, vl());

ll FAC[MAXN] = {0};
ll TWO[MAXN] = {0};

ll dfs(ll i, ll par){
    ll ans = FAC[sz(C[i])];
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            ans *= dfs(a,i);
            ans %= mod;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    ll t1 = 1;
    ll t2 = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t1;
        TWO[c1] = t2;
        t1 *= c1+1;
        t2 *= 2;
        t1 %= mod;
        t2 %= mod;
    }
    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    ll ans = dfs(0,-1);
    ans *= n;
    ans %= mod;
    cout << ans << "\n";

    return 0;
}
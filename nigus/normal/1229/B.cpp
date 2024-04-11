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

const ll MAXN = 100001;

vector<vi> C(MAXN, vi());
ll X[MAXN] ={0};

ll M[MAXN] = {0};

ll MM(ll i){
    if(i == -1)return -1;
    return M[i];
}

int BL[MAXN][17] = {0};
ll GL[MAXN][17] = {0};

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

vi ind;

void dfs(int i, int par){
    BL[i][0] = par;
    GL[i][0] = X[i];
    M[i] = MM(par)+1;
    ind.push_back(i);

    rep(c1,0,sz(C[i])){
        int a = C[i][c1];
        if(a != par){
            dfs(a,i);
        }
    }
}

ll solve(ll i, ll x){
    if(i == -1)return 0;
    ll good = -1;
    per(c1,17,0){
        if((x == 0 && GL[i][c1] == 0) || (x != 0 && GL[i][c1]%x == 0)){
            good = BL[i][c1];
            break;
        }

    }
    ll res = (MM(i) - MM(good)) * x;
    res %= big;
    if(good != -1)res += solve(good, gcd(x,X[good]));
    return res % big;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
       // X[c1] = 1000000000000;
        cin >> X[c1];
    }
    rep(c1,0,n-1){
        cin >> a >> b;
        //a = c1+1;
       // b = c1+2;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs(0,-1);

    rep(c2,0,n){
        int i = ind[c2];
        rep(c1,1,17){
            if(BL[i][c1-1] == -1){
                BL[i][c1] = -1;
                GL[i][c1] = GL[i][c1-1];
            }
            else{
                ll j = BL[i][c1-1];
                BL[i][c1] = BL[j][c1-1];
                GL[i][c1] = gcd(GL[i][c1-1], GL[j][c1-1]);
            }
        }
    }

    ll ans = 0;
    rep(c1,0,n){
        ans += solve(c1,X[c1]);
        ans %= big;
    }
    cout << ans << "\n";

    return 0;
}
#pragma GCC optimize("O3")   //
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vector<vi> C(MAXN, vi());
ll par[MAXN] = {0};
set<int> pars;

vi dpars;
ll root;

void dfs(ll i, ll p){
    trav(j, C[i]){
        if(j != p){
            par[j] = (par[i]^1);
            dfs(j,i);
        }
    }
    if(sz(C[i]) == 1){
       // cerr << i+1 << " " << p+1 << "  fds\n ";
        pars.insert(p);
        dpars.push_back(par[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    root = 0;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        if(sz(C[a]) > 1){
            root = a;
        }
        if(sz(C[b]) > 1){
            root = b;
        }
    }
    dfs(root,-1);
    sort(all(dpars));
    if(dpars[0] == dpars.back()){
        cout << "1 ";
    }
    else{
        cout << "3 ";
    }
    cout << n-1 - (sz(dpars) - sz(pars)) << "\n";

    return 0;
}
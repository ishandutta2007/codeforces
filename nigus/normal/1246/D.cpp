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

const int MAXN = 100001;

ll PAR[MAXN] = {0};
vector<vi> C(MAXN, vi());

vi bamb;
vi ops;

ll ST[MAXN] = {0};

void dfs1(ll i){
    trav(y,C[i]){
        dfs1(y);
        ST[i] = max(ST[y],ST[i]);
    }
    ST[i]++;
    return;
}

bool comp(ll i, ll j){
    return ST[i] < ST[j];
}

void dfs2(ll i){
    sort(all(C[i]), comp);
   // reverse(all(C[i])); ////
  //  ll tots = 0;

    bamb.push_back(i);
    ll prev = 0;
    trav(y, C[i]){
        dfs2(y);
        rep(c1,0,prev){
            ops.push_back(y);
        }
        prev = ST[y];
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    PAR[0] = -1;
    rep(c1,0,n-1){
        cin >> a;
        PAR[c1+1] = a;
        C[a].push_back(c1+1);
    }

    dfs1(0);
    dfs2(0);

    rep(c1,0,n){
        cout << bamb[c1] << " ";
    }
    cout << "\n";
    cout << sz(ops) << "\n";
    rep(c1,0,sz(ops)){
        cout << ops[c1] << " ";
    }
    cout << "\n";

    return 0;
}
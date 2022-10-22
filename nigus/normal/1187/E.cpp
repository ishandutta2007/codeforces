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

const int MAXN = 200001;

vector<vi> C(MAXN, vi());
vector<set<int> > LEF(MAXN, set<int>());


unordered_map<ll,ll> M;
ll SS[MAXN] = {0};
ll PAR[MAXN] = {0};
ll TOTSUM[MAXN] = {0};

void dfs1(int i, int par){
    SS[i] = 1;
    PAR[i] = par;
    trav(y,C[i]){
        if(y != par){
            dfs1(y,i);
            SS[i] += SS[y];
        }
    }
}

ll ss(ll i, ll from){
    if(from == -1)return n;
    if(from == PAR[i])return SS[i];
    return n-SS[from];
}


//vi upd;

vector<vi> upd(MAXN, vi());

ll dp(ll i, ll from){
    ll h = i*(MAXN+1)+from+1;
    if(M.find(h) != M.end())return M[h];

    trav(y, LEF[i]){
        if(y != from){
            TOTSUM[i] += dp(y, i);
            upd[i].push_back(y);
        }
    }
    rep(c1,0,sz(upd[i])){
        LEF[i].erase(upd[i][c1]);
    }
    upd[i].clear();
    ll sum = TOTSUM[i];
    ll h2 = from*(MAXN+1)+i+1;
    if(M.find(h2) != M.end())sum -= M[h2];
    M[h] = ss(i, from) + sum;

    return M[h];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n;


    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        LEF[a].insert(b);
        LEF[b].insert(a);
    }
    dfs1(0,-1);
    ll ans = 0;
    rep(c1,0,n){
      //  cerr << c1 << ": " << dp(c1,-1) << "\n";
        ans = max(ans, dp(c1, -1));
    }
    cout << ans << "\n";

    return 0;
}
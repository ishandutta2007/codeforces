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

const ll MAXN = 300001;

vector<vl> C(MAXN, vl());
vl W;
ll s;

bool mark[MAXN] = {0};
ll deg2[MAXN] = {0};
ll nothing = 0;
bool oned[MAXN] = {0};
bool R[MAXN] = {0};

void solve(ll i){
    mark[i] = 1;
    rep(c1,0,sz(C[i])){
        int a = C[i][c1];
        if(!mark[a])deg2[a]--;

        if(a == s){
            return;
        }
        if(!mark[a] && deg2[a] == 1){
            solve(a);
        }
    }
    return;
}

ll dfs(ll i, ll par){
    ll ans = 0;
    oned[i] = 1;
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(mark[a] && a != par){
            ans = max(ans,dfs(a,i));
        }
    }
    return ans + W[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    rep(c1,0,n){
        cin >> a;
        W.push_back(a);
        //nothing += a;
    }
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
        deg2[a]++;
        deg2[b]++;
    }
    cin >> s;
    s--;

    rep(c1,0,n){
        if(deg2[c1] == 1 && !mark[c1] && c1 != s){
            solve(c1);
        }
    }

    nothing = 0;
    rep(c1,0,n){
        if(!mark[c1])nothing += W[c1];
    }

    ll ans = nothing;
    rep(c1,0,n){
        if(mark[c1] && !oned[c1]){

            bool repp = 0;
            rep(c2,0,sz(C[c1])){
                a = C[c1][c2];
                if(!mark[a])repp = 1;
            }

            if(repp)ans = max(ans, nothing + dfs(c1,-1));
        }
    }

    cout << ans << "\n";

    return 0;
}
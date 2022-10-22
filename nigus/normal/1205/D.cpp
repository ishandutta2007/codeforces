#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b - 1; i >= a; i--)
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

const int MAXN = 1001;

vector<vl> C(MAXN,vl());
vector<vl> SS(MAXN,vl());
ll root = -1;
ll root2 = -1;

bool small[MAXN] = {0};

ll S = 0;

ll dfs1(ll i, ll par){
    ll ans = 1;
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            ans += dfs1(a,i);
        }
    }
    return ans;
}

ll ANS[MAXN] = {0};
ll now0 = 1;
ll now1 = 1;


void dfs2(ll i, ll par, bool small){
    if(small){
        ANS[i] = now0;
        now0++;
    }
    else{
        ANS[i] = S*now1+now1;
        now1++;
    }
    cout << par+1 << " " << i+1 << " " << ANS[i]-ANS[par] << "\n";
    rep(c1,0,sz(C[i])){
        ll a = C[i][c1];
        if(a != par){
            dfs2(a,i,small);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    rep(c1,0,n){
        ll mast = 0;
        ll third = -1;
        rep(c2,0,sz(C[c1])){
            SS[c1].push_back(dfs1(C[c1][c2],c1));
            if(SS[c1][c2] > n/3)third = c2;
            mast = max(mast, SS[c1][c2]);
        }
        if(mast <= n/2 && root == -1){
            root = c1;
            if(third != -1){
                root2 = C[c1][third];
                S = SS[root][third];
            }
            else{
                root2 = -1;
            }
        }
    }

    if(root2 != -1){
        small[root2] = 1;
    }
    else{
        ll tot = 0;
        ll x = 0;
        while(tot < n/3){
            small[C[root][x]] = 1;
            tot += SS[root][x];
            x++;
        }
        S = tot;
    }

    rep(c1,0,sz(C[root])){
        dfs2(C[root][c1],root,small[C[root][c1]]);
    }

    return 0;
}
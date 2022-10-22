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

vl D;
vi ind;

vector<pll> E;

ll par[MAXN] = {0};

bool comp(ll i, ll j){
    return D[i] > D[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    rep(c1,0,n){
        cin >> a;
        D.push_back(a);
        ind.push_back(c1);
    }

    sort(all(ind),comp);

    rep(c1,0,n-1){
        E.push_back({ind[c1]*2+1, ind[c1+1]*2+1});
    }

    bool tree = 0;

    ll now = ind[n-1]*2+1;
    ll dep = 0;

    rep(c1,0,n){
        a = ind[c1];
        if(D[a] < n-c1){
            par[2*a+2] = ind[c1+D[a]-1]*2+1;
        }
        else{

            while(n-c1-1+dep >= D[a]){
                now = par[now];
                dep--;
            }

            par[2*a+2] = now;
            now = 2*a+2;
            dep++;
        }
    }

    rep(c1,0,n){
        E.push_back({2*c1+2, par[2*c1+2]});
    }

    rep(c1,0,sz(E)){
        cout << E[c1].first << " " << E[c1].second << "\n";
    }

    return 0;
}

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

const int MAXN = 400006;

ll upp(ll i, ll j){
    if(j == 0)return 1;
    ll h = upp(i,j/2);
    if(j%2 == 0)return (h*h)%big;
    return (((h*h)%big)*i)%big;
}

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    ll x = (FAC[i] * INV[j])%big;
    return (x * INV[i-j])%big;
}

vector<vi> C(MAXN, vi());

ll SS[MAXN] = {0};
ll PAR[MAXN] = {0};
ll MIN[MAXN] = {0};

void dfs1(int i, int par){
    SS[i] = 1;
    PAR[i] = par;
    trav(y, C[i]){
        if(y != par){
            dfs1(y, i);
            SS[i] += SS[y];
        }
    }
}

ll ss(int i, int j){
    if(j == PAR[i])return n-SS[i];
    return SS[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t = 1;
    rep(c1,0,MAXN){
        FAC[c1] = t;
        t *= ll(c1+1);
        t %= big;
    }
    INV[MAXN-1] = upp(FAC[MAXN-1], big-2);
    for(ll c1 = MAXN-2; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1] * (c1+1))%big;
    }

    cin >> n >> k;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs1(0, -1);

    rep(c1,0,n){
        trav(y, C[c1]){
            MIN[c1] += bin(ss(c1, y), k);
            MIN[c1] %= big;
        }
    }

    ll ans = 0;
    rep(c1,0,n){
        trav(y, C[c1]){
            ll root = n-ss(c1,y)+1;
            ll mi = MIN[y] + big - bin(ss(y, c1), k);
            mi %= big;
            ll res = bin(ss(c1, y), k) - mi + big;
            res %= big;
            res *= root-1;
            res %= big;

          //  cerr << c1+1 << " -> " << y+1 << ":   " << res << "   " << ss(c1,y) << "\n";

            res *= ss(c1,y);
            res %= big;
            ans += res;
            ans %= big;
        }
    }
    //cerr << ans << "\n";
    rep(c1,0,n){
        ll res = bin(n-1, k-1);
        res += bin(n-1, k) - MIN[c1] + big;
        res %= big;
       // cerr << c1+1 << ": " << res << "\n";
        res *= n;
        ans += res;
        ans %= big;
    }

    cout << ans << "\n";

    return 0;
}
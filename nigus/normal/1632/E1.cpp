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

const int MAXN = 300001;

vector<vi> C(MAXN, vi());

int H[MAXN] = {0};
vi ind;

int H2[MAXN] = {0};
int X[MAXN] = {0};

bool comp(ll i, ll j){
    return H[i] > H[j];
}

void dfs1(int i, int par){
    if(par != -1)H[i] = H[par]+1;
    trav(y, C[i]){
        if(y != par)dfs1(y, i);
    }
}

void dfs2(int i, int par){
    if(par != -1)H2[i] = H2[par]+1;
    trav(y, C[i]){
        if(y != par)dfs2(y, i);
    }
}

int bestc[MAXN] = {0};

int mad = 0;

void solve(int i){
    H2[i] = 0;
    dfs2(i,-1);
    rep(c1,0,n){
        bestc[c1] = 0;
    }
    rep(c1,0,n){
        bestc[H[c1]] = max(bestc[H[c1]], H2[c1]);
    }
    int ma_c = 0;
    for(int d = mad; d > 0; d--){
        int x2 = d-ma_c;
        x2 = max(0, x2);
        X[x2] = min(X[x2], d);
        ma_c = max(ma_c, bestc[d]);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        ind.clear();
        rep(c1,0,n){
            C[c1].clear();
            ind.push_back(c1);
            X[c1+1] = big;
        }
        X[0] = big;
        rep(c1,0,n-1){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);
        }
        H[0] = 0;
        dfs1(0,-1);
        sort(all(ind), comp);
        mad = H[ind[0]];

        rep(c1,1,n+1){
            X[c1] = mad;
        }
        X[0] = mad;
        rep(c1,0,n){
            solve(ind[c1]);
        }

        for(int c1 = n-1; c1 >= 0; c1--){
            X[c1] = min(X[c1], X[c1+1]);
        }

        rep(c1,1,n+1){
            cout << X[c1] << " ";
        }cout << "\n";
    }

    return 0;
}
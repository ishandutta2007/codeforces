#pragma GCC optimize("O3")

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

const int MAXN = 100007;

vector<vi> C(MAXN, vi());

int SS[MAXN] = {0};
int DP[MAXN] = {0};
int PAR[MAXN] = {0};

int color[MAXN] = {0};

void dfs(int i, int par){
    PAR[i] = par;
    SS[i] = 1;
    trav(y, C[i]){
        if(y != par){
            dfs(y, i);
            SS[i] += SS[y];
            DP[i] += DP[y] + (color[i] == color[y]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,n){
        cin >> a;
        color[c1] = a;
    }
    dfs(0,-1);

    rep(c1,0,n){
        if(c1 != 0){
            int rest = DP[0] - DP[c1] - (color[c1] == color[PAR[c1]]);
            if(rest != n - SS[c1] - 1)continue;
        }
        bool bad = 0;
        trav(y, C[c1]){
            if(y != PAR[c1]){
                if(DP[y] != SS[y]-1)bad = 1;
            }
        }
        if(!bad){
            cout << "YES\n" << c1+1 << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
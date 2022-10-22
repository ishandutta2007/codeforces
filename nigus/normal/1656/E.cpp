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

const int MAXN = 500001;

vector<vi> C(MAXN, vi());

bool col[MAXN] = {0};

void dfs(int i, int par){
    trav(y, C[i]){
        if(y != par){
            col[y] = (1^col[i]);
            dfs(y, i);
        }
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
        col[0] = 0;
        rep(c1,0,n){
            C[c1].clear();
        }
        rep(c1,0,n-1){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);
        }
        dfs(0,-1);
        rep(c1,0,n){
            if(col[c1] == 0){
                cout << sz(C[c1]) << " ";
            }
            else{
                cout << -sz(C[c1]) << " ";
            }
        }cout << "\n";

    }


    return 0;
}
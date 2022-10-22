#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef gp_hash_table<int,int> umap;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const ll MAXN = 200001;

vector<vi> C(MAXN, vi());

ll ans = 0;

bool dfs(int i, int par){
    int x = 0;
    trav(y, C[i]){
        if(y != par){
            x += dfs(y, i);
        }
    }
    if(x == 0)return 1;
    ans += x-1;
    return 0;
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
 
    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        rep(c1,0,n){
            C[c1].clear();
        }
        ans = 1;
        rep(c1,0,n-1){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);
        }
        dfs(0,-1);
        cout << ans << "\n";
    }

    return 0;
}
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

const int MAXN = 400007;

vector<vi> C(MAXN, vi());
bool seen[MAXN] = {0};

void dfs(int i){
    seen[i] = 1;
    trav(y, C[i]){
        if(!seen[y])dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m >> k;
    rep(c1,0,k){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b+n);
        C[b+n].push_back(a);
    }
    int ans = -1;
    rep(c1,0,n+m){
        if(!seen[c1]){
            ans++;
            dfs(c1);
        }
    }
    cout << ans << "\n";

    return 0;
}
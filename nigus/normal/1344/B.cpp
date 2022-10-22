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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

bool inbounds(ll i, ll j){
    return i>=0 && j >= 0 && i < n && j <m ;
}

bool grid[1001][1001] = {0};

ll DX[4] = {0,0,1,-1};
ll DY[4] = {-1,1,0,0};

bool zr = 0;
bool zc = 0;

bool validate(){
    rep(c1,0,n){
        bool prevb = 0;
        int segs = 0;
        rep(c2,0,m){
            if(grid[c1][c2]){
                if(!prevb)segs++;
                prevb = 1;
            }
            else{
                prevb = 0;
            }
        }
        if(segs>1)return 0;
        if(segs==0)zr = 1;
    }

    rep(c1,0,m){
        bool prevb = 0;
        int segs = 0;
        rep(c2,0,n){
            if(grid[c2][c1]){
                if(!prevb)segs++;
                prevb = 1;
            }
            else{
                prevb = 0;
            }
        }
        if(segs>1)return 0;
        if(segs==0)zc = 1;
    }
    return 1;
}

bool mark[1001][1001] = {0};

void dfs(ll i, ll j){
    if(mark[i][j])return;
    mark[i][j] = 1;
    rep(c1,0,4){
        ll i2 = i+DX[c1];
        ll j2 = j+DY[c1];
        if(inbounds(i2,j2) && grid[i2][j2] && !mark[i2][j2]){
            dfs(i2,j2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> m;

    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            grid[c1][c2] = (s[c2] == '#');
        }
    }

    if(!validate()){
        cout << "-1\n";
        return 0;
    }

    if((zc^zr) == 1){
        cout << "-1\n";
        return 0;
    }

    ll ans = 0;
    rep(c1,0,n){
        rep(c2,0,m){
            if(grid[c1][c2] && !mark[c1][c2]){
                ans++;
                dfs(c1,c2);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
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

const int MAXN = 2000001;

int DX[4] ={0,0,-1,1};
int DY[4] = {1,-1,0,0};

int grid[301][301] = {0};

bool inbounds(ll i, ll j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int nonz(ll i, ll j){
    int res = 0;
    rep(c1,0,4){
        ll i2 = i+DX[c1];
        ll j2 = j+DY[c1];
        if(inbounds(i2,j2) && grid[i2][j2] != 0)res++;
    }
    return res;
}

void extra(){
    rep(c1,0,n){
        rep(c2,0,m){
            if(grid[c1][c2] != 0){
                ll z = nonz(c1,c2);
                if(z < grid[c1][c2]){

                    rep(c3,0,4){
                        ll i2 = c1+DX[c3];
                        ll j2 = c2+DY[c3];
                        if(inbounds(i2,j2) && grid[i2][j2] == 0 && z < grid[c1][c2]){
                            z++;
                            grid[i2][j2] = 1;
                        }
                    }

                }
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        rep(c1,0,n){
            rep(c2,0,m){
                cin >> a;
                grid[c1][c2] = a;
            }
        }
        extra();
        bool fail = 0;
        rep(c1,0,n){
            rep(c2,0,m){
                if(grid[c1][c2] > 0){
                    ll z = nonz(c1,c2);
                    if(z < grid[c1][c2])fail = 1;
                    if(z > grid[c1][c2])grid[c1][c2] = z;
                }
            }
        }
        if(fail){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            rep(c1,0,n){
                rep(c2,0,m){
                    cout << grid[c1][c2] << " ";
                }cout << "\n";
            }
        }
    }

    return 0;
}
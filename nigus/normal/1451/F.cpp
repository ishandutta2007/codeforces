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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}


ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 101;

int grid[MAXN][MAXN] = {0};

bool nim[3*MAXN] = {0};
bool mis[3*MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> T;

    rep(c4,0,T){
        cin >> n >> m;
        rep(c1,0,n){
            rep(c2,0,m){
                cin >> a;
                grid[c1][c2] = a;
            }
        }


        for(int siz = n+m-1; siz >= 0; siz--){
            int ma = 0;
            int xo = 0;
            rep(c1,0,n){
                rep(c2,0,m){
                    if(c1+c2 == siz){
                        xo ^= grid[c1][c2];
                        ma = max(ma, grid[c1][c2]);
                    }
                }
            }
            nim[siz] = (xo != 0);
            mis[siz] = !((xo == 0 && ma > 1) || (xo == 1 && ma == 1));

            if(siz < n+m-1){
                bool nw = 0;
                bool ms = 0;
                if((nim[siz+1] && !mis[siz]) || (mis[siz+1] && mis[siz])){
                    ms = 1;
                }
                else{
                    ms = 0;
                }
                if((nim[siz+1] && !nim[siz]) || (mis[siz+1] && nim[siz])){
                    nw = 1;
                }
                else{
                    nw = 0;
                }
                nim[siz] = max(nim[siz],nw);
                mis[siz] = max(mis[siz],ms);
            }

        }

        if(nim[0]){
            cout << "Ashish\n";
        }
        else{
            cout << "Jeel\n";
        }

}


    return 0;
}
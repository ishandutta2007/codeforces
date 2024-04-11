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

const int MAXN = 1002;

ll A[MAXN][MAXN] = {0};

bool parity[MAXN][MAXN] = {0};
int DX[4] = {0,0,-1,1};
int DY[4] = {1,-1,0,0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}

ll xo = 0;

void mark(int i, int j){
    xo ^= A[i][j];
    rep(c1,0,4){
        int i2 = i+DX[c1];
        int j2 = j+DY[c1];
        if(inbounds(i2,j2)){
            parity[i2][j2] ^= 1;
        }
    }
}

void turn(){
    rep(c1,0,n){
        rep(c2,0,n/2){
            swap(A[c1][c2], A[c1][n-c2-1]);
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
        rep(c1,0,n){
            rep(c2,0,n){
                cin >> a;
                A[c1][c2] = a;
                parity[c1][c2] = 0;
            }
        }

        xo = 0;
        rep(c1,0,n){
            int start = c1%2;
            for(int c2 = start; c2 < n; c2 += 2){
                if(c1 == 0){
                    mark(c1,c2);
                }
                else{
                    if(parity[c1-1][c2] == 0)mark(c1,c2);
                }
            }
        }

        /*
        rep(c1,0,n){
            rep(c2,0,n){
                cerr << parity[c1][c2];
            }cerr << "\n";
        }
        */

        turn();
        ll ans = xo;
        xo = 0;
        rep(c1,0,n){
            rep(c2,0,n){
                parity[c1][c2] = 0;
            }
        }
        rep(c1,0,n){
            int start = c1%2;
            for(int c2 = start; c2 < n; c2 += 2){
                if(c1 == 0){
                    mark(c1,c2);
                }
                else{
                    if(parity[c1-1][c2] == 0)mark(c1,c2);
                }
            }
        }
        cout << (ans^xo) << "\n";


    }


    return 0;
}
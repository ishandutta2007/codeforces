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

const int MAXN = 300001;

int grid[301][301] = {0};
bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}


int danger(int i, int j){
    if(grid[i][j]  == 0)return 0;
    bool yes1 = 1;
    rep(c1,0,3){
        int i2 = i-c1+1;
        int j2 = j;
        if(!inbounds(i2,j2)){
            yes1 = 0;
            break;
        }
        if(grid[i2][j2] != grid[i][j]){
            yes1 = 0;
            break;
        }
    }
    bool yes2 = 1;
    rep(c1,0,3){
        int i2 = i;
        int j2 = j-c1+1;
        if(!inbounds(i2,j2)){
            yes2 = 0;
            break;
        }
        if(grid[i2][j2] != grid[i][j]){
            yes2 = 0;
            break;
        }
    }
    return (yes1 + yes2);
}

string abc = ".XO";

int X[3] = {0};
int Y[3] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        rep(c1,0,3){
            X[c1] = 0;
            Y[c1] = 0;
        }
        rep(c1,0,n){
            string s;
            cin >> s;
            rep(c2,0,n){
                if(s[c2] == 'X'){
                    grid[c1][c2] = 1;

                    X[(c1+c2)%3]++;
                }
                if(s[c2] == 'O'){
                    grid[c1][c2] = 2;
                }
                if(s[c2] == '.')grid[c1][c2] = 0;
            }
        }

        int x = -1;
        int bestx = 1234565655;

        rep(c1,0,3){
            if(X[c1] < bestx){
                bestx = X[c1];
                x = c1;
            }
        }

        rep(c1,0,n){
            rep(c2,0,n){
                if(((c1+c2)%3 == x) && grid[c1][c2] == 1){
                    grid[c1][c2] = 2;
                }
                cout << abc[grid[c1][c2]];
            }cout << "\n";
        }


    }


    return 0;
}
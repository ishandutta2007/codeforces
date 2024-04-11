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

int grid[2001][2001] = {0};

string ab = ".*";

int DX[4] = {0,1,0,-1};
int DY[4] = {1,0,-1,0};

int DX2[8] = {0,1,0,-1,1,1,-1,-1};
int DY2[8] = {1,0,-1,0,1,-1,1,-1};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool free(int i, int j){
    return inbounds(i,j) && (grid[i][j] == 0);
}

bool bad(int i, int j){
    if(grid[i][j] == 0)return 0;
    rep(c1,0,4){
        int i2 = i + DX[c1];
        int j2 = j + DY[c1];
        int i3 = i + DX[(c1+1)%4];
        int j3 = j + DY[(c1+1)%4];
        int i4 = i2+i3-i;
        int j4 = j2+j3-j;
        if(free(i2,j2) && free(i3,j3) && free(i4,j4))return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    cin >> n >> m;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            if(s[c2] == '*'){
                grid[c1][c2] = 1;
            }
        }
    }

    queue<pii> Q;
    rep(c1,0,n){
        rep(c2,0,m){
            if(bad(c1,c2))Q.push({c1,c2});
        }
    }

    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        int i = p.first;
        int j = p.second;
        if(grid[i][j] == 1){
            grid[i][j] = 0;
            rep(c1,0,8){
                int i2 = i + DX2[c1];
                int j2 = j + DY2[c1];
                if(inbounds(i2,j2) && bad(i2,j2))Q.push({i2,j2});
            }
        }
    }
    rep(c1,0,n){
        rep(c2,0,m){
            cout << ab[grid[c1][c2]];
        }cout << "\n";
    }

    return 0;
}
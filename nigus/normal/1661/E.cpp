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

const int MAXN = 500101;

int L,R;
bool limit = 0;

bool inbounds(int i, int j){

    if(limit && (j < L || j > R))return 0;

    return i >= 0 && j >= 0 && i < n && j < m;
}

int DX[4] = {0,1,0,-1};
int DY[4] = {1,0,-1,0};

bool grid[3][MAXN];

bool zero(int i, int j){
    return (!inbounds(i, j)) || (!grid[i][j]);
}

bool one(int i, int j){
    return (inbounds(i, j)) && (grid[i][j]);
}

int corner(int i, int j, int d){
    int i2 = i+DX[d];
    int j2 = j+DY[d];
    int i3 = i+DX[(d+1)%4];
    int j3 = j+DY[(d+1)%4];
    int i4 = i+DX[(d+1)%4]+DX[d];
    int j4 = j+DY[(d+1)%4]+DY[d];
    return (grid[i][j] && zero(i2,j2) && zero(i3,j3)) - (!grid[i][j] && one(i2,j2) && one(i3,j3) && one(i4,j4));
}

int corner_sum(int i, int j){
    int res = 0;
    rep(c1,0,4){
        res += corner(i,j,c1);
    }
    return res;
}

int CS[MAXN] = {0};
int lef[MAXN] = {0};
int holes = 0;
int RH[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    n = 3;
    rep(c1,0,n){
        string s;
        cin >> s;
        rep(c2,0,m){
            grid[c1][c2] = (s[c2] == '1');
        }
    }

    CS[0] = 0;
    rep(c1,0,m){
        RH[c1] = -1;
        ll dx = 0;
        rep(c2,0,n){
            dx += corner_sum(c2,c1);
        }
        CS[c1+1] = dx+CS[c1];
    }

    int last = -1;
    rep(c1,0,m){
        if(!grid[2][c1] || !grid[0][c1]){
            last = -1;
        }
        else{
            if(grid[1][c1]){
                if(last != -1 && last != c1-1){
                    RH[c1-1] = holes;
                    lef[holes] = last;
                    holes++;
                }
                last = c1;
            }
        }
    }

    RH[m] = holes;
    for(int c1 = m-1; c1 >= 0; c1--){
        if(RH[c1] == -1 && RH[c1+1] != -1)RH[c1] = RH[c1+1];
    }

    cin >> q;

    rep(c1,0,q){
        cin >> L >> R;
        L--;
        R--;

        ll base = CS[R+1]-CS[L];

        rep(c2,0,3){
            base -= corner_sum(c2,L);
            if(L < R)base -= corner_sum(c2,R);
        }
        limit = 1;
        rep(c2,0,3){
            base += corner_sum(c2,L);
            if(L < R)base += corner_sum(c2,R);
        }
        limit = 0;
        base /= 4;

        int rh = RH[R];
        int lh = RH[L];
        int h;
        if(lh == holes){
            h = 0;
        }
        else{
            h = rh-lh-(lef[lh] < L);
        }
        h = max(h, 0);
        cout << base + h << "\n";
    }

    return 0;
}
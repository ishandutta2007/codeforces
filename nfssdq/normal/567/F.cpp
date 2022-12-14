/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL dp[71][71];
vector < int > vc[71][5];
LL go(int l, int r){
    int p = (r-l+1) / 2;
    if(p == 1){
        if(vc[l][2].size() || vc[r][2].size()) return 0;
        REP(i, vc[l][4].size()){
            if(vc[l][4][i] != r) return 0;
        }
        REP(i, vc[r][4].size()){
            if(vc[r][4][i] != l) return 0;
        }
        REP(i, vc[l][0].size()){
            if(vc[l][0][i] != r) return 0;
        }
        REP(i, vc[r][0].size()){
            if(vc[r][0][i] != l) return 0;
        }
        return 1;
    }

    LL &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = 0;


    // both left;
    int fl = 0;
    REP(i, vc[l][0].size()){
        if(vc[l][0][i] != l+1) fl = 1;
    }
    REP(i, vc[l][2].size()){
        if(vc[l][2][i] <= l+1 || vc[l][2][i] > r) fl = 1;
    }
    REP(i, vc[l][4].size()){
        if(vc[l][4][i] < l || vc[l][4][i] > r) fl = 1;
    }
    REP(i, vc[l+1][0].size()){
        if(vc[l+1][0][i] != l) fl = 1;
    }
    REP(i, vc[l+1][2].size()){
        if(vc[l+1][2][i] <= l+1 || vc[l+1][2][i] > r) fl = 1;
    }
    REP(i, vc[l+1][4].size()){
        if(vc[l+1][4][i] < l || vc[l+1][4][i] > r) fl = 1;
    }
    if(fl == 0) ret += go(l + 2, r);

    // left right
    fl = 0;
    REP(i, vc[l][0].size()){
        if(vc[l][0][i] != r) fl = 1;
    }
    REP(i, vc[l][2].size()){
        if(vc[l][2][i] <= l || vc[l][2][i] >= r) fl = 1;
    }
    REP(i, vc[l][4].size()){
        if(vc[l][4][i] < l || vc[l][4][i] > r) fl = 1;
    }
    REP(i, vc[r][0].size()){
        if(vc[r][0][i] != l) fl = 1;
    }
    REP(i, vc[r][2].size()){
        if(vc[r][2][i] <= l || vc[r][2][i] >= r) fl = 1;
    }
    REP(i, vc[r][4].size()){
        if(vc[r][4][i] < l || vc[r][4][i] > r) fl = 1;
    }
    if(fl == 0) ret += go(l + 1, r - 1);

    // both right
    fl = 0;
    REP(i, vc[r-1][0].size()){
        if(vc[r-1][0][i] != r) fl = 1;
    }
    REP(i, vc[r-1][2].size()){
        if(vc[r-1][2][i] < l || vc[r-1][2][i] >= r-1) fl = 1;
    }
    REP(i, vc[r-1][4].size()){
        if(vc[r-1][4][i] < l || vc[r-1][4][i] > r) fl = 1;
    }
    REP(i, vc[r][0].size()){
        if(vc[r][0][i] != r-1) fl = 1;
    }
    REP(i, vc[r][2].size()){
        if(vc[r][2][i] < l || vc[r][2][i] >= r-1) fl = 1;
    }
    REP(i, vc[r][4].size()){
        if(vc[r][4][i] < l || vc[r][4][i] > r) fl = 1;
    }
    if(fl == 0) ret += go(l, r - 2);

    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    REP(i, k){
        int x, y; string s;
        cin >> x >> s >> y;
        if(x == y && (s == ">" || s == "<")){
            cout << 0 << endl;
            return 0;
        }
        if(x == y) continue;
        x--; y--;
        if(s == "="){
            vc[x][0].pb(y);
            vc[y][0].pb(x);
        } else if(s == ">"){
            vc[x][1].pb(y);
            vc[y][2].pb(x);
        } else if(s == "<"){
            vc[x][2].pb(y);
            vc[y][1].pb(x);
        } else if(s == ">="){
            vc[x][3].pb(y);
            vc[y][4].pb(x);
        } else {
            vc[x][4].pb(y);
            vc[y][3].pb(x);
        }
    }


    memset(dp, -1, sizeof dp);
    cout << go(0, n+n-1) << endl;
}
/*
332211
*/
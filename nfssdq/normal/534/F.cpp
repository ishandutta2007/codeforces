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

short dp[11][11][11][11][11][21][32], col[21], row[6], m, n;
vector < int > vc[5];
short go(int x1, int x2, int x3, int x4, int x5, int c, int bp){
    if(c == m){
        if(!x1 && !x2 && !x3 && !x4 && !x5) return 1;
        return 0;
    }
    short &ret = dp[x1][x2][x3][x4][x5][c][bp];
    if(ret != -1) return ret;
    ret = 0;
    int nx1, nx2, nx3, nx4, nx5;
    REP(i, vc[col[c]].size()){
        int p = vc[col[c]][i];
        if((bp & 1<<0) == 0 && (p & 1<<0)){
            if(!x1) continue;
            nx1 = x1-1;
        } else nx1 = x1;
        if((bp & 1<<1) == 0 && (p & 1<<1)){
            if(!x2) continue;
            nx2 = x2-1;
        } else nx2 = x2;
        if((bp & 1<<2) == 0 && (p & 1<<2)){
            if(!x3) continue;
            nx3 = x3-1;
        } else nx3 = x3;
        if((bp & 1<<3) == 0 && (p & 1<<3)){
            if(!x4) continue;
            nx4 = x4-1;
        } else nx4 = x4;
        if((bp & 1<<4) == 0 && (p & 1<<4)){
            if(!x5) continue;
            nx5 = x5-1;
        } else nx5 = x5;

        if(go(nx1, nx2, nx3, nx4, nx5, c+1, p)) return ret = 1;
    }
    return ret;
}
string s[5];
void print(int x1, int x2, int x3, int x4, int x5, int c, int bp){
    if(c == m) return;
    int nx1, nx2, nx3, nx4, nx5;
    REP(i, vc[col[c]].size()){
        int p = vc[col[c]][i];
        if((bp & 1<<0) == 0 && (p & 1<<0)){
            if(!x1) continue;
            nx1 = x1-1;
        } else nx1 = x1;
        if((bp & 1<<1) == 0 && (p & 1<<1)){
            if(!x2) continue;
            nx2 = x2-1;
        } else nx2 = x2;
        if((bp & 1<<2) == 0 && (p & 1<<2)){
            if(!x3) continue;
            nx3 = x3-1;
        } else nx3 = x3;
        if((bp & 1<<3) == 0 && (p & 1<<3)){
            if(!x4) continue;
            nx4 = x4-1;
        } else nx4 = x4;
        if((bp & 1<<4) == 0 && (p & 1<<4)){
            if(!x5) continue;
            nx5 = x5-1;
        } else nx5 = x5;

        if(go(nx1, nx2, nx3, nx4, nx5, c+1, p)){
            REP(j, 5){
                if(p & 1<<j) s[j] += '*';
                else s[j] += '.';
            }
            print(nx1, nx2, nx3, nx4, nx5, c+1, p);
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    REP(i, n) cin >> row[i];
    REP(i, m) cin >> col[i];
    REP(i, 1<<n){
        int cnt = 0;
        REP(j, n){
            if(i & 1<<j){
                if(j == 0 || (i & 1<<(j-1)) == 0) cnt++;
            }
        }
        vc[cnt].pb(i);
    }
    memset(dp, -1, sizeof dp);
    go(row[0], row[1], row[2], row[3], row[4], 0, 0);
    print(row[0], row[1], row[2], row[3], row[4], 0, 0);
    REP(i, n) cout << s[i] << endl;
}
/*
5 20
10 10 10 10 10
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
*/
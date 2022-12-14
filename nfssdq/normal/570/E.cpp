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

LL dp[2][501][501];
char pp[501][501];
int id[2][501][501];
int ar[501][501], mv, n, m;
vector < pair < int, int > > vc[2][501];
void dfs1(int x, int y, int c){
    ar[x][y] = c;
    vc[0][c].pb(mp(x, y));
    id[0][x][y] = vc[0][c].size() - 1;
    if(c == mv) return;
    if(x+1 < n && ar[x+1][y] == 0) dfs1(x+1, y, c + 1);
    if(y+1 < m && ar[x][y+1] == 0) dfs1(x, y+1, c + 1);
}
void dfs2(int x, int y, int c){
    ar[x][y] = c;
    vc[1][c].pb(mp(x, y));
    id[1][x][y] = vc[1][c].size() - 1;
    if(c == mv) return;
    if(x-1 >= 0 && ar[x-1][y] == 0) dfs2(x-1, y, c + 1);
    if(y-1 >= 0 && ar[x][y-1] == 0) dfs2(x, y-1, c + 1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    REP(i, n) cin >> pp[i];

    mv = (n-1) + (m-1);
    mv /= 2;

    dfs1(0, 0, 0);

    set0(ar);
    dfs2(n-1, m-1, 0);

    REP(i, vc[0][mv].size()){
        REP(j, vc[1][mv].size()){
            pair < int, int > p1 = vc[0][mv][i], p2 = vc[1][mv][j];
            if(pp[p1.xx][p1.yy] == pp[p2.xx][p2.yy] && abs(p1.xx-p2.xx)+abs(p1.yy-p2.yy) <= 1){
                dp[0][i][j] = 1;
            }
        }
    }

    int f = 0;
    for(int i = mv - 1; i >= 0; i--){
        f ^= 1;
        for(int j = 0; j < vc[0][i].size(); j++){
            for(int k = 0; k < vc[1][i].size(); k++){
                dp[f][j][k] = 0;
                pair < int, int > p1 = vc[0][i][j], p2 = vc[1][i][k];
                if(pp[p1.xx][p1.yy] != pp[p2.xx][p2.yy]) continue;
                if(p1.xx+1 < n && p2.xx-1 >= 0){
                    dp[f][j][k] += dp[f^1][ id[0][p1.xx+1][p1.yy] ][ id[1][p2.xx-1][p2.yy] ];
                }
                if(p1.xx+1 < n && p2.yy-1 >= 0){
                    dp[f][j][k] += dp[f^1][ id[0][p1.xx+1][p1.yy] ][ id[1][p2.xx][p2.yy-1] ];
                }
                if(p1.yy+1 < m && p2.xx-1 >= 0){
                    dp[f][j][k] += dp[f^1][ id[0][p1.xx][p1.yy+1] ][ id[1][p2.xx-1][p2.yy] ];
                }
                if(p1.yy+1 < m && p2.yy-1 >= 0){
                    dp[f][j][k] += dp[f^1][ id[0][p1.xx][p1.yy+1] ][ id[1][p2.xx][p2.yy-1] ];
                }
                dp[f][j][k] %= mod;
            }
        }
    }

    cout << dp[f][0][0] << endl;
}
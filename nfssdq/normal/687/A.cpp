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

vector < int > vc[100001], vp[2];
int col[100001];
void dfs(int c, int f){
    col[c] = f;
    REP(i, vc[c].size()){
        if(col[vc[c][i]] == -1) dfs(vc[c][i], f ^ 1);
        else {
            if(col[vc[c][i]] != (f ^ 1)){
                cout << -1 << endl;
                exit(0);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(col, -1, sizeof col);
    int n, m; cin >> n >> m;
    FOR(i, 1, m+1) {
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    int fl = 0;
    FOR(i, 1, n+1){
        if(col[i] == -1){
            dfs(i, fl);
            fl ^= 1;
        }
        vp[col[i]].pb(i);
    }
    REP(i, 2){
        cout << vp[i].size() << endl;
        REP(j, vp[i].size()) cout << vp[i][j] << " ";
        cout << endl;
    }
}
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


int ar[101][101], val[101 * 101], vis[101 * 101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int cc = 0;
    FOR(i, 1, n+1) FOR(j, 1, m+1) {
        ar[i][j] = ++cc;
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int r; cin >> r;
            int v = ar[r][1];
            for(int i = 2; i <= m; i++) ar[r][i-1] = ar[r][i];
            ar[r][m] = v;
        } else if(t == 2){
            int c; cin >> c;
            int v = ar[1][c];
            for(int i = 2; i <= n; i++) ar[i-1][c] = ar[i][c];
            ar[n][c] = v;
        } else {
            int r, c, x; cin >> r >> c >> x;
            val[ar[r][c]] = x;
            vis[ar[r][c]] = 1;
        }
    }

    cc = 0;
    FOR(i, 1, n+1){
        FOR(j, 1, m+1){
            cc++;
            if(vis[cc]) cout << val[cc] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
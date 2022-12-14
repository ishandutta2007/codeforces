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

int ar[2][501][501];
char pp[505][505];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, n) cin >> pp[i];
    REP(i, n){
        for(int j = 1; j < m; j++){
            ar[0][i][j] = ar[0][i][j-1];
            if(pp[i][j] == '.' && pp[i][j-1] == '.') ar[0][i][j]++;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            ar[1][i][j] = ar[1][i-1][j];
            if(pp[i][j] == '.' && pp[i-1][j] == '.') ar[1][i][j]++;
        }
    }

    int q; cin >> q;
    while(q--){
        int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        int res = 0;
        for(int i = r1; i <= r2; i++){
            res += ar[0][i][c2] - ar[0][i][c1];
        }
        for(int i = c1; i <= c2; i++){
            res += ar[1][r2][i] - ar[1][r1][i];
        }

        cout << res << "\n";
    }
}
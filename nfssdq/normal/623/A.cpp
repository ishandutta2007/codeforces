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

vector < int > vc[5];
int ar[501][501], val[501];

void go(int c, int v){
    vc[v].pb(c);
    val[c] = v;
    FOR(i, 1, 501){
        if(ar[c][i] && val[i] == 0) go(i, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, m){
        int x, y; cin >> x >> y;
        ar[x][y] = ar[y][x] = 1;
    }

    FOR(i, 1, n+1){
        int fl = 0;
        FOR(j, 1, n+1){
            if(i == j) continue;
            if(ar[i][j] == 0) fl = 1;
        }
        if(fl == 0) val[i] = 2;
    }

    int cnt = 1;
    FOR(i, 1, n+1){
        if(val[i] == 0){
            if(cnt > 3){
                cout << "No" << endl;
                return 0;
            }
            go(i, cnt);
            if(cnt == 1) cnt = 3;
            else cnt = 5;
        }
    }

    REP(i, vc[1].size()){
        REP(j, vc[1].size()){
            if(i == j) continue;
            if(ar[vc[1][i]][vc[1][j]] == 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    REP(i, vc[3].size()){
        REP(j, vc[3].size()){
            if(i == j) continue;
            if(ar[vc[3][i]][vc[3][j]] == 0){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    FOR(i, 1, n+1){
        cout << (char)('a'+val[i]-1);
    }
    cout << endl;
}
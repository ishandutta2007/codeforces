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

char grid[55][55], res[105][105];
vector < pair < int, int > > vc,mov;
int on[55][55];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> grid[i];
    REP(i, n){
        REP(j, n){
            if(grid[i][j] == 'o') vc.pb( mp(i, j) );
        }
    }
    for(int i = -n+1; i < n; i++){
        for(int j = -n+1; j < n; j++){
            if(!i && !j) continue;
            int fl = 0;
            REP(k, vc.size()){
                int x = vc[k].xx + i;
                int y = vc[k].yy + j;
                if(x < 0 || x >= n || y < 0 || y >= n) continue;
                if(grid[x][y] == '.') {
                    fl = 1;
                    break;
                }
            }

            if(fl) continue;

            REP(k, vc.size()){
                int x = vc[k].xx + i;
                int y = vc[k].yy + j;
                if(x < 0 || x >= n || y < 0 || y >= n) continue;
                on[x][y] = 1;
            }

            mov.pb(mp(i, j));
        }
    }

    REP(i, n){
        REP(j, n){
            if(grid[i][j] == 'x' && on[i][j] == 0){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    REP(i, 2*n-1) REP(j, 2*n-1) res[i][j] = '.';

    int px = n-1, py = n-1;

    res[px][py] = 'o';

    REP(i, mov.size()){
        int x , y;
        x = px + mov[i].xx;
        y = py + mov[i].yy;
        res[x][y] = 'x';
    }

    REP(i, 2*n-1) cout << res[i] << endl;
}
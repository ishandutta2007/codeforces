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

#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>
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
#define ALL(A)     A.begin(), A.end()
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


char pp[2005][2005];
int deg[2001][2001], vis[2001][2001];
int nxt[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    REP(i, n) cin >> pp[i];

    queue < pair < int, int > > Q;

    REP(i, n){
        REP(j, m){
            if(pp[i][j] == '*') continue;
            REP(k, 4){
                int cx = i + nxt[k][0];
                int cy = j + nxt[k][1];
                if(cx < 0 || cx >= n || cy < 0 || cy >= m || pp[cx][cy] == '*') continue;
                deg[i][j]++;
            }
            if(deg[i][j] == 1) Q.push(mp(i, j));
        }
    }
    while(!Q.empty()){
        pair < int, int > p1 = Q.front();
        Q.pop();
        if(vis[p1.xx][p1.yy]) continue;
        vis[p1.xx][p1.yy] = 1;
        int cx = -1, cy = -1, fl = 0;
        REP(i, 4){
            cx = p1.xx + nxt[i][0];
            cy = p1.yy + nxt[i][1];
            if(cx < 0 || cx >= n || cy < 0 || cy >= m || pp[cx][cy] != '.') continue;
            if(vis[cx][cy]) continue;
            if(i == 0){
                pp[p1.xx][p1.yy] = 'v';
                pp[cx][cy] = '^';
            } else if(i == 1){
                pp[p1.xx][p1.yy] = '>';
                pp[cx][cy] = '<';
            } else if(i == 2){
                pp[p1.xx][p1.yy] = '^';
                pp[cx][cy] = 'v';
            } else {
                pp[p1.xx][p1.yy] = '<';
                pp[cx][cy] = '>';
            }
            vis[cx][cy] = 1;
            fl = 1;
            break;
        }
        if(fl == 0){
            cout << "Not unique" << endl;
            return 0;
        }
        REP(i, 4){
            int dx = cx + nxt[i][0];
            int dy = cy + nxt[i][1];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m || pp[dx][dy] != '.') continue;
            if(vis[dx][dy]) continue;
            deg[dx][dy]--;
            if(deg[dx][dy] == 1) Q.push(mp(dx, dy));
        }
    }

    int fl = 0;
    REP(i, n) REP(j, m) if(pp[i][j] == '.') fl = 1;
    if(fl) {
       cout << "Not unique" << endl;
        return 0;
    }
    REP(i, n) cout << pp[i] << endl;
}
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

struct dinic_maxflow {

    struct edge {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d) {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;

    int INF = 1500000001 ;

    int n, s, t, d [ 3001 ] , ptr [ 3001 ] , q [ 3001 * 10 ] ;
    vector < edge > e ;
    vector < int > g [ 3001 ] ;

    void add_edge ( int a, int b, int cap ) {
        edge e1 =edge( a, b, cap, 0 ) ;
        edge e2 =edge( b, a, 0 , 0 ) ;
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }

    bool bfs ( ) {
        int qh = 0 , qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1 , sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 ) {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i ) {
                int id = g [ v ] [ i ] ,
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap ) {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }

    int dfs ( int v, int flow ) {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] ) {
            int id = g [ v ] [ ptr [ v ] ] ,
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed ) {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    int dinic ( ) {
        int flow = 0 ;
        for ( ;; ) {
            if ( !bfs () )  break ;
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) ) {
                flow += pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    dinic_maxflow( int _n, int _s, int _t ){
        n = _n; s = _s; t = _t;
    }
};

LL dis[23][23][23][23];
int nxt[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
char ps[23][23];
int n, m, male, female, ar[2][555][3], cnt = 0;
vector < pair < int, int > > vc;
void bfs(int x, int y){
    queue < pair < int, int > > Q;
    Q.push(mp(x, y));
    dis[x][y][x][y] = 0;
    while(!Q.empty()){
        pair < int, int > pp = Q.front();
        Q.pop();
        REP(i, 4){
            int cx = pp.xx + nxt[i][0];
            int cy = pp.yy + nxt[i][1];
            if(cx < 0 || cx >= n || cy < 0 || cy >= m || ps[cx][cy] == '#') continue;
            if(dis[x][y][cx][cy] > dis[x][y][pp.xx][pp.yy] + 1){
                dis[x][y][cx][cy] = dis[x][y][pp.xx][pp.yy] + 1;
                Q.push(mp(cx, cy));
            }
        }
    }
}

bool go(LL m){
    int tot = cnt*2 + male + female + 5, lft = male + cnt, rgt = male + cnt + cnt;
    dinic_maxflow dm = dinic_maxflow(tot, 0, tot - 1);
    for(int i = 1; i <= male; i++){
        dm.add_edge(0, i, 1);
        for(int j = 1; j <= cnt; j++){
            int x = ar[0][i - 1][0] - 1, y = ar[0][i - 1][1] - 1;
            int cx = vc[j - 1].xx, cy = vc[j - 1].yy;
            if(dis[x][y][cx][cy] < 5000 && dis[x][y][cx][cy]*ar[0][i-1][2] <= m) {
                dm.add_edge(i, male + j, 1);
            }
        }
    }
    for(int i = 1; i <= cnt; i++){
        dm.add_edge(male + i, lft + i, 1);
    }
    for(int i = 1; i <= male; i++){
        dm.add_edge(rgt + i, tot - 1, 1);
        for(int j = 1; j <= cnt; j++){
            int x = ar[1][i - 1][0] - 1, y = ar[1][i - 1][1] - 1;
            int cx = vc[j - 1].xx, cy = vc[j - 1].yy;
            if(dis[x][y][cx][cy] < 5000 && dis[x][y][cx][cy]*ar[1][i-1][2] <= m) {
                dm.add_edge(lft + j, rgt + i, 1);
            }
        }
    }
    if(dm.dinic() == male) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> male >> female;
    REP(i, n) cin >> ps[i];
    int r, c, t; cin >> r >> c >> t;
    REP(i, male) REP(j, 3) cin >> ar[0][i][j];
    REP(i, female) REP(j, 3) cin >> ar[1][i][j];

    if(abs(male - female) != 1){
        cout << -1 << endl;
        return 0;
    }

    if(male < female){
        ar[0][male][0] = r; ar[0][male][1] = c; ar[0][male++][2] = t;
    } else {
        ar[1][female][0] = r; ar[1][female][1] = c; ar[1][female++][2] = t;
    }

    REP(i, n) REP(j, m) REP(k, n) REP(l, m) dis[i][j][k][l] = 10000;
    REP(i, n){
        REP(j, m){
            if(ps[i][j] != '#'){
                vc.pb(mp(i, j));
                bfs(i, j);
                cnt++;
            }
        }
    }

    LL lo = 0, hi = 1ll<<45, mid = (lo + hi) / 2ll;
    while(lo < mid){
        if(go(mid))hi = mid;
        else lo = mid + 1;
        mid = (lo + hi) / 2ll;
    }
    for(LL i = max(0ll, mid - 5); i <= mid + 5; i++){
        if(go(i)){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}
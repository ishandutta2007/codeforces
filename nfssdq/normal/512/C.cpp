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

LL isp[100001], ar[233], vis[222];
vector < int > prime;
struct dinic_maxflow {

    struct edge {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d) {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;

    int INF = 1500000001 ;

    int n, s, t, d [ 30001 ] , ptr [ 30001 ] , q [ 30001 * 10 ] ;
    vector < edge > e ;
    vector < int > g [ 30001 ] ;

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
vector < int > vc[222];
vector < vector < int > > res;
vector < int > tmp;
void dfs(int c){
    vis[c] = 1;
    tmp.pb(c);
    REP(i, vc[c].size()){
        if(vis[vc[c][i]] == 0) dfs(vc[c][i]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    for(int i = 2; i <= 20000; i++){
        if(isp[i] == 0){
            for(int j = i*2; j <= 20000; j += i) isp[j] = 1;
            prime.pb(i);
        }
    }
    cin >> a;
    REP(i, a) cin >> ar[i];
    dinic_maxflow dm = dinic_maxflow(a+2, 0, a+1);
    REP(i, a){
        if(ar[i]%2 == 1){
            dm.add_edge(0, i+1, 2);
        } else {
            dm.add_edge(i+1, a+1, 2);
            REP(j, a){
                if(isp[ar[i]+ar[j]]==0) dm.add_edge(j+1, i+1, 1);
            }
        }
    }
    if(dm.dinic() != a){
        cout << "Impossible" << endl;
        return 0;
    }
    REP(i, dm.e.size()){
        b = dm.e[i].a;
        c = dm.e[i].b;
        if(b == 0 || b == a+1 || c == 0 || c == a+1) continue;
        if(ar[b-1]%2 == 0) continue;
        if(dm.e[i].cap == 0 || dm.e[i].flow == 0) continue;
        vc[b].pb(c);
        vc[c].pb(b);
    }
    FOR(i, 1, a + 1){
        if(vis[i] == 0) {
            tmp.clear();
            dfs(i);
            res.pb(tmp);
        }
    }
    cout << res.size() << endl;
    REP(i, res.size()){
        cout << res[i].size();
        REP(j, res[i].size()){
            cout << " " << res[i][j];
        }
        cout << endl;
    }
}
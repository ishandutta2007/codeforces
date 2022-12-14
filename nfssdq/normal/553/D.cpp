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

vector < int > vc[100001];
int vis[100001], isStorage[100001];
double denom[100001], cur[100001];

typedef pair<double,int> pdi;

priority_queue < pdi, vector < pdi >, greater < pdi > >pq;

vector < int > res;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    REP(i, k){
        int v; cin >> v;
        vis[v] = isStorage[v] = 1;
    }
    REP(i, m){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    FOR(i, 1, n + 1){
        if(vis[i]) continue;

        double p = vc[i].size();
        denom[i] = 1.0 / p;

        double cnt = 0.0;
        REP(j, vc[i].size()){
            if(vis[ vc[i][j] ] == 0) cnt += 1.0;
        }
        cnt /= p;

        cur[i] = cnt;
        pq.push( mp(cnt, i) );
    }

    double mx = -1.0;
    int id = 0;

    while(!pq.empty()){
        pdi p = pq.top();
        pq.pop();

        if(vis[p.yy]) continue;
        vis[p.yy] = 1;

        if(p.xx > mx){
            mx = p.xx;
            id = p.yy;
        }

        REP(i, vc[p.yy].size()){
            if(vis[ vc[p.yy][i] ]) continue;

            cur[ vc[p.yy][i] ] -= denom[ vc[p.yy][i] ];
            pq.push( mp(cur[ vc[p.yy][i] ], vc[p.yy][i]) );
        }
    }

    set0(vis);
    REP(i, n + 1) vis[i] = isStorage[i];

    FOR(i, 1, n + 1){
        if(vis[i]) continue;

        double p = vc[i].size();
        denom[i] = 1.0 / p;

        double cnt = 0.0;
        REP(j, vc[i].size()){
            if(vis[ vc[i][j] ] == 0) cnt += 1.0;
        }
        cnt /= p;

        cur[i] = cnt;
        pq.push( mp(cnt, i) );
    }

    while(!pq.empty()){
        pdi p = pq.top();
        pq.pop();

        if(vis[p.yy]) continue;

        if(p.yy == id){
            FOR(i, 1, n + 1) if(vis[i] == 0) res.pb(i);
            break;
        }

        vis[p.yy] = 1;


        if(p.xx > mx){
            mx = p.xx;
            id = p.yy;
        }

        REP(i, vc[p.yy].size()){
            if(vis[ vc[p.yy][i] ]) continue;

            cur[ vc[p.yy][i] ] -= denom[ vc[p.yy][i] ];
            pq.push( mp(cur[ vc[p.yy][i] ], vc[p.yy][i]) );
        }
    }

    cout << res.size() << endl;
    REP(i, res.size()) cout << res[i] << " ";
    cout << endl;
}
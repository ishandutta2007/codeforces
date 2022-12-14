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

vector < LL > vc[300001], vp[300001];
LL edge[300001][3], dis[300001], res[300001];
priority_queue < pair<LL,LL>, vector<pair<LL,LL> >, greater<pair<LL,LL> > >pq;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, m){
        int x, y, v; cin >> x >> y >> v;
        vc[x].pb(y);
        vc[y].pb(x);
        vp[x].pb(i);
        vp[y].pb(i);
        edge[i][0] = x; edge[i][1] = y; edge[i][2] = v;
    }
    int u; cin >> u;
    setinf(dis);
    dis[u] = 0;
    pq.push(mp(0, u));
    memset(res, -1, sizeof res);
    while(!pq.empty()){
        pair < LL, LL > p = pq.top();
        pq.pop();
        REP(i, vc[p.yy].size()){
            if(dis[ vc[p.yy][i] ] > p.xx + edge[ vp[p.yy][i] ][2]){
                dis[ vc[p.yy][i] ] = p.xx + edge[ vp[p.yy][i] ][2];
                res[ vc[p.yy][i] ] = vp[p.yy][i];
                pq.push(mp(dis[ vc[p.yy][i] ], vc[p.yy][i]));
            } else if(dis[ vc[p.yy][i] ] == p.xx + edge[ vp[p.yy][i] ][2]){
                if(edge[ vp[p.yy][i] ][2] <= edge[ res[ vc[p.yy][i] ] ][2]){
                    res[ vc[p.yy][i] ] = vp[p.yy][i];
                }
            }
        }
    }
    LL sum = 0;
    FOR(i, 1, n+1){
        if(res[i] == -1) continue;
        sum += edge[ res[i] ][2];
    }
    cout << sum << endl;
    FOR(i, 1, n+1){
        if(res[i] == -1) continue;
        cout << res[i]+1 << " ";
    }
    cout << endl;
}
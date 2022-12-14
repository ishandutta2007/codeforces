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
#define mod        1000000009ll
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

map< pair<int,int>, int > mm;
set < LL > pq;
pair < int, int > pp[100001];
int out[100001], in[100001], vis[100001];
vector < int > vc[100001], vp[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    LL m; cin >> m;

    FOR(i, 1, m + 1){
        cin >> pp[i].xx >> pp[i].yy;
        mm[ pp[i] ] = i;
    }

    FOR(i, 1, m + 1){
        pair < int, int > np = pp[i];
        np.yy--;

        np.xx--;
        int v = mm[ np ];
        if(v != 0){
            vc[i - 1].pb( v - 1 );
            vp[v - 1].pb(i - 1);
            in[v - 1]++;
            out[i - 1]++;
        }

        np.xx++;
        v = mm[ np ];
        if(v != 0){
            vc[i - 1].pb( v - 1 );
            vp[v - 1].pb(i - 1);
            in[v - 1]++;
            out[i - 1]++;
        }

        np.xx++;
        v = mm[ np ];
        if(v != 0){
            vc[i - 1].pb( v - 1 );
            vp[v - 1].pb(i - 1);
            in[v - 1]++;
            out[i - 1]++;
        }

    }

    REP(i, m) {
        pq.insert(i);
    }

    set < LL >::iterator it;

    LL res = 0, f2 = 1;
    while(!pq.empty()){

        LL v;
        if(f2 == 0){
            it = pq.begin();
            v = (*it);
            pq.erase(it);
        } else {
            it = pq.end(); it--;
            v = (*it);
            pq.erase(it);
        }

        if(vis[v]) continue;

        int fl = 0;
        REP(i, vp[v].size()){
            if(vis[ vp[v][i] ]) continue;
            if(out[ vp[v][i] ] == 1) fl = 1;
        }
        if(fl) continue;

        vis[v] = 1;

        REP(i, vp[v].size()){
            out[ vp[v][i] ]--;
        }
        REP(i, vc[v].size()){
            in[ vc[v][i] ]--;
            pq.insert( vc[v][i] );
        }

        f2 ^= 1;
        res = (res * m + v) % mod;

    }

    cout << res << endl;





}
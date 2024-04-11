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

vector < int > vc[200001], vp[200001], id[200001];
int res[200001], flow[200001], vis[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    FOR(i, 1, b + 1){
        cin >> c >> d >> e;
        vc[c].pb(d);
        vp[c].pb(e);
        id[c].pb(i);
        vc[d].pb(c);
        vp[d].pb(e);
        id[d].pb(-i);
        flow[c] += e; flow[d] += e;
    }
    FOR(i, 2, a) flow[i] /= 2;
    flow[a] = mod*2ll;
    queue < int > Q;
    Q.push(1);
    while(!Q.empty()){
        c = Q.front();
        Q.pop();
        vis[c] = 1;
        REP(i, vc[c].size()){
            d = vc[c][i];
            if(vis[d])continue;
            if(id[c][i] < 0) res[-id[c][i]] = 1;
            flow[d] -= vp[c][i];
            if(flow[d] == 0) Q.push(d);
        }
    }
    FOR(i, 1, b + 1) cout << res[i] << endl;
}
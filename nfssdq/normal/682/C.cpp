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

vector < int > vc[100001], vp[100001];
LL ar[100001], dis[100001], sz[100001];
void dfs(int c, int p, LL d){
    dis[c] = d;
    sz[c] = 1;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs(vc[c][i], c, d + vp[c][i]);
        sz[c] += sz[ vc[c][i] ];
    }
}

int dfs2(int c, int p, LL mn){
    mn = min(mn, dis[c]);
    if(dis[c]-ar[c]-mn > 0) return sz[c];
    int ret = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        ret += dfs2(vc[c][i], c, mn);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1) cin >> ar[i];
    FOR(i, 2, n+1){
        int x, v; cin >> x >> v;
        vc[x].pb(i); vp[x].pb(v);
        vc[i].pb(x); vp[i].pb(v);
    }
    dfs(1, 0, 0);
    cout << dfs2(1, 0, 0) << endl;
}
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

LL ar[2001][2001], vis[2001], n;
vector < LL > vc[2001], vp[2001];
LL dis[2001][2001];
void dfs(LL c, LL p){
    vis[c] = 1;
    set < pair < LL, LL > > S;
    FOR(i, 1, n + 1){
        if(vis[i] == 0) S.insert(mp(ar[c][i], i));
    }
    while(S.size() > 0){
        pair < LL, LL > pp = (*S.begin());
        S.erase(S.begin());
        if(vis[pp.yy] == 1) continue;
        LL b = pp.yy;
        if(p == 0 || ar[p][b] == ar[c][b]+ar[p][c]){
            if(ar[c][b] == 0) continue;
            vc[c].pb(b);
            vp[c].pb(ar[c][b]);
            dfs(b, c);
        }
    }
}
vector < LL > child[2001], cc[2001];
void dfs2(int c){
    child[c].pb(c);
    cc[c].pb(0);
    REP(i, vc[c].size()){
        dfs2(vc[c][i]);
        REP(j, child[vc[c][i]].size()){
            REP(k, child[c].size()){
                dis[ child[c][k] ][ child[ vc[c][i] ][j] ] = cc[ vc[c][i] ][j] + vp[c][i] + cc[c][k];
                dis[ child[ vc[c][i] ][j] ][ child[c][k] ] = cc[ vc[c][i] ][j] + vp[c][i] + cc[c][k];
            }
        }
        REP(j, child[vc[c][i]].size()){
            child[c].pb(child[ vc[c][i] ][j]);
            cc[c].pb(cc[ vc[c][i] ][j] + vp[c][i]);
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        FOR(j, 1, a + 1) cin >> ar[i][j];
    }
    n = a;
    dfs(1, 0);
    FOR(i, 1, a + 1) if(vis[i] == 0) f = 1;
    if(f == 0) dfs2(1);
    FOR(i, 1, a + 1) FOR(j, 1, a + 1) if(dis[i][j] != ar[i][j]) f = 1;
    if(f == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
/*
3
0 1 2
1 0 1
2 1 0
*/
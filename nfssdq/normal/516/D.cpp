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

LL down[100001];
pair < LL, int > dis[100001];
vector < int > vc[100001], vp[100001];
void dfs1(int c, int p){
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs1(vc[c][i], c);
        down[c] = max(down[c], down[vc[c][i]] + vp[c][i]);
    }
}
void dfs2(int c, int p, LL mx){
    dis[c] = mp( max(down[c], mx), c);

    pair < LL, int > pp[2];
    pp[0] = mp(mx, -1);
    pp[1] = mp(0, -1);

    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        if(down[vc[c][i]]+vp[c][i] > pp[0].xx){
            pp[1] = pp[0];
            pp[0] = mp(down[vc[c][i]]+vp[c][i], i);
        } else if(down[vc[c][i]]+vp[c][i] > pp[1].xx){
            pp[1] = mp(down[vc[c][i]]+vp[c][i], i);
        }
    }

    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        if(pp[0].yy == i) dfs2(vc[c][i], c, pp[1].xx+vp[c][i]);
        else dfs2(vc[c][i], c, pp[0].xx+vp[c][i]);
    }
}
int pre[100001];
void dfs3(int c, int p){
    pre[c] = p;
    REP(i, vc[c].size()) {
        if(vc[c][i] == p) continue;
        dfs3(vc[c][i], c);
    }
}
int parent[100001], sz[100001];
int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y){
    int px = Find(x);
    int py = Find(y);
    if(px == py) return;
    parent[px] = py;
    sz[py] += sz[px];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n - 1){
        int a, b, c;
        cin >> a >> b >> c;
        vc[a].pb(b);
        vc[b].pb(a);
        vp[a].pb(c);
        vp[b].pb(c);
    }

    dfs1(1, 0);
    dfs2(1, 0, 0);

    sort(dis + 1, dis + n + 1);

    dfs3(dis[1].yy, 0);

    int Q; cin >> Q;
    while(Q--){
        LL L; cin >> L;

        FOR(i, 1, n + 1){
            parent[i] = i;
            sz[i] = 1;
        }

        int last = n, res = 0;
        for(int i = n; i >= 1; i--){
            for(int j = 0; j < vc[dis[i].yy].size(); j++){
                if(vc[dis[i].yy][j] == pre[dis[i].yy]) continue;
                Union(dis[i].yy, vc[dis[i].yy][j]);
            }
            while(last > i && dis[last].xx - dis[i].xx > L) {
                sz[Find(dis[last].yy)]--;
                last--;
            }
            res = max(res, sz[Find(dis[i].yy)]);
        }
        cout << res << endl;
    }
}
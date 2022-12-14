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

vector < int > adj[200001];
vector < pair < LL, int > >  cost[200001];
int t = 0, numChild[200001];
int lvl[200001], start[200001], endt[200001];
int dfs(int node, int pnt, int dis){
    int child = 1;
    lvl[node] = dis;
    start[node] = ++t;
    REP(i, adj[node].size()){
        if(adj[node][i] == pnt)continue;
        child += dfs(adj[node][i], node, dis + 1);
    }
    endt[node] = ++t;
    return numChild[node] = child;
}

vector < int > group[200001];
int cnt = 0, position[200001];
int grp[200001], parent[200001];
LL val[200001], edge[200001];
void hld(int node, int pnt, int pos){
    position[node] = pos;
    parent[node] = pnt;
    grp[node] = cnt;
    group[cnt].push_back(node);
    int maxVal = 0, child = 0;
    REP(i, adj[node].size()){
        if(adj[node][i] == pnt)continue;
        val[ adj[node][i] ] = cost[node][i].xx;
        edge[ cost[node][i].yy ] = adj[node][i];
        if(numChild[ adj[node][i] ] > maxVal){
            maxVal = numChild[ adj[node][i] ];
            child = adj[node][i];
        }
    }
    if(child != 0) hld(child, node, pos + 1);
    REP(i, adj[node].size()){
        if(adj[node][i] == pnt || adj[node][i] == child)continue;
        cnt++; hld(adj[node][i], node, 0);
    }
}
LL vv[200001];
int P[200001][25];
void pre_process(int N){
    memset(P,-1,sizeof P);
    for(int i = 1; i <= N; i++)P[i][0] = parent[i];
    for(int j = 1; (1<<j) <= N; j++){
        for(int i = 1; i <= N; i++){
            if(P[i][j - 1] != -1) P[i][j] = P[ P[i][j - 1] ][j - 1];
        }
    }
}
int LCA(int p, int q){
    if(lvl[p] < lvl[q])swap(p,q);
    int log;
    for(log = 1; (1<<log) <= lvl[p]; log++);
    log--;
    for(int i = log; i >= 0; i--){
        if(lvl[p] - (1<<i) >= lvl[q])p = P[p][i];
    }
    if(p == q)return p;
    for(int i = log; i >= 0; i--){
        if(P[p][i] != -1 && P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    return parent[p];
}
set < pair < int, LL > > seg[200001];
LL queryL(int a, int s, int e, LL v){
    if(s > e) return v;
    set<pair<int,LL> >::iterator it = seg[a].lower_bound(mp(s,0));
    while(it != seg[a].end()){
        if((*it).xx > e) break;
        v /= (*it).yy;
        if(v == 0) return 0;
        it++;
    }
    return v;
}
LL queryR(int a, int s, int e, LL v){
    if(s > e) return v;
    set<pair<int,LL> >::iterator it = seg[a].lower_bound(mp(e+1,0));
    while(it != seg[a].begin()){
        it--;
        if((*it).xx < s) break;
        v /= (*it).yy;
        if(v == 0) return 0;
    }
    return v;
}
LL dfsquL(int node,int pnt,LL v){
    if(v == 0) return 0;
    if(node == parent[pnt])return v;
    int a=grp[node];
    if(grp[pnt] == a)
        return queryL(a,position[pnt] + 1,position[node], v);
    else {
        LL tv = queryL(a,0,position[node], v);
        return dfsquL(parent[ group[a][0] ], pnt, tv);
    }
}
LL dfsquR(int node,int pnt,LL v){
    if(v == 0) return 0;
    if(node == parent[pnt])return v;
    int a=grp[node];
    if(grp[pnt] == a)
        return queryR(a,position[pnt] + 1,position[node], v);
    else {
        LL tv = dfsquR(parent[ group[a][0] ], pnt, v);
        return queryR(a,0,position[node], tv);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    FOR(i, 1, n){
        int x, y; LL v; cin >> x >> y >> v;
        vv[i] = v;
        adj[x].pb(y); cost[x].pb(mp(v, i));
        adj[y].pb(x); cost[y].pb(mp(v, i));
    }

    dfs(1, 0, 1);
    hld(1, 0, 0);

    REP(i, cnt + 1){
        REP(j, group[i].size()){
            if(val[group[i][j]] > 1) seg[i].insert(mp(position[ group[i][j] ], val[ group[i][j] ]));
        }
    }
    pre_process(n);
//    if(n == 500 && m == 500) return 0;

    while(m--){
        LL t, x, y, v; cin >> t >> x >> y;
        if(t == 1){
            cin >> v;
            int p = LCA(x, y);
            LL tv = dfsquL(x, p, v);
            v = dfsquR(y, p, tv);
            cout << v << endl;
        } else {
            int p = edge[x];
            seg[ grp[p] ].erase(mp(position[p], vv[x]));

            vv[x] = y;
            if(y > 1){
                seg[ grp[p] ].insert(mp(position[p], vv[x]));
            }

        }
    }
}
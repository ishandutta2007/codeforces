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


vector < int > adj[100001];
int t = 0, numChild[100001], pre[100001];
int lvl[100001], start[100001], endt[100001];
int dfs(int node, int pnt, int dis){
    int child = 1;
    lvl[node] = dis;
    start[node] = ++t;
    pre[node] = pnt;
    REP(i, adj[node].size()){
        if(adj[node][i] == pnt)continue;
        child += dfs(adj[node][i], node, dis + 1);
    }
    endt[node] = ++t;
    return numChild[node] = child;
}

vector < int > group[100001];
int cnt = 0, position[100001];
int grp[100001], parent[100001];
void hld(int node, int pnt, int pos){
    position[node] = pos;
    parent[node] = pnt;
    grp[node] = cnt;
    group[cnt].push_back(node);
    int maxVal = 0, child = 0;
    REP(i, adj[node].size()){
        if(adj[node][i] == pnt)continue;
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

int P[100001][22];
void pre_process(int N){
    memset(P,-1,sizeof P);
    for(int i = 1; i <= N; i++)P[i][0] = pre[i];
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
    return pre[p];
}



vector< int > seg[100001][12], pref[100001];
void insert(int ii,int idx, int s, int e, int v, int p){
    if(s == e){
        seg[ii][10][idx]=p;
        vector < int > vp;
        REP(i, 11) vp.pb(seg[ii][i][idx]);
        vsort(vp);
        REP(i, 11) seg[ii][i][idx] = vp[i];
        return;
    }
    int mid=(s+e)/2;
    if(v<=mid)insert(ii,idx*2+1,s,mid,v,p);
    else if(v>mid)insert(ii,idx*2+2,mid+1,e,v,p);
    if(v == e){
        vector < int > vp;
        REP(i, 11) vp.pb(seg[ii][i][idx*2+1]);
        REP(i, 11) vp.pb(seg[ii][i][idx*2+2]);
        vsort(vp);
        REP(i, 11) seg[ii][i][idx] = vp[i];
    }
}
vector<int> query(int ii,int idx,int s,int e,int st,int ed){
//    cout << st << " " << ed << " " << s << " " << e << " " << ii << endl;
    vector<int> ret;
    if(st > ed) return ret;
    if(s==st && e==ed){
        REP(i, 11) ret.pb(seg[ii][i][idx]);
        return ret;
    }
    int mid=(s+e)/2;
    if(ed<=mid)return query(ii,idx*2+1,s,mid,st,ed);
    else if(st>mid)return query(ii,idx*2+2,mid+1,e,st,ed);
    else {
        vector<int>vl = query(ii,idx*2+1,s,mid,st,mid);
        vector<int>vr = query(ii,idx*2+2,mid+1,e,mid+1,ed);
        vl.insert(vl.end(), vr.begin(), vr.end());
        vsort(vl);
        if(vl.size() > 11) vl.resize(11);
        return vl;
    }
}
vector < int > dfsqu(int node,int pnt){
    vector < int > ret;
    if(node == parent[pnt])return ret;
    int a=grp[node];
    if(grp[pnt] == a)
        return query(a,0,0,group[a].size()-1,position[pnt],position[node]);
    else {
        vector<int>vl = pref[node];
        vector<int>vr = dfsqu(parent[ group[a][0] ], pnt);
        vl.insert(vl.end(), vr.begin(), vr.end());
        vsort(vl);
        if(vl.size() > 11) vl.resize(11);
        return vl;
    }
}

vector < int > ar[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    REP(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0, 1);
    hld(1, 0, 0);

    pre_process(n);

    FOR(i, 1, n+1) ar[i].pb(inf);

    REP(i, m){
        int x; cin >> x;
        ar[x].pb(i+1);
    }
    FOR(i, 1, n+1) vsort(ar[i]);

    REP(i, cnt + 1){
        REP(j, 11){
            REP(k, 4*group[i].size()) seg[i][j].pb(inf);
        }
        REP(j, group[i].size()) {
            REP(k, ar[group[i][j]].size())
                insert(i, 0, 0, group[i].size() - 1, j, ar[group[i][j]][k]);
            if(j == 0) REP(k, 11) pref[group[i][j]].pb(inf);
            else REP(k, 11) pref[group[i][j]].pb(pref[group[i][j-1]][k]);
            REP(k, ar[group[i][j]].size()){
                pref[group[i][j]][10] = ar[group[i][j]][k];
                vsort(pref[group[i][j]]);
            }
        }
    }

    while(q--){
        int l, r, v; cin >> l >> r >> v;
        int p = LCA(l, r);

        vector < int > vl = dfsqu(l, p);
        vector < int > vr = dfsqu(r, p);
        set < int > ms;
        REP(i, vl.size()) ms.insert(vl[i]);
        REP(i, vr.size()) ms.insert(vr[i]);

//        cout << vl.size() << " " << vr.size() << " " << ms.size() << endl;

        vector < int > vc;

        for(auto &c: ms){
            if(v == 0) break;
            v--;
            if(c > m) break;
            vc.pb(c);
        }

        cout << vc.size();
        REP(i, vc.size()) cout << " " << vc[i];
        cout << endl;
    }

}
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

struct hopcroft_karp {

    int n1, n2, edges, last[200001], pre[500001], head[500001];
    int matching[200001], dist[200001], Q[200001];
    bool used[200001], vis[200001];

    void init(int _n1, int _n2) {
        n1 = _n1;
        n2 = _n2;
        edges = 0;
        fill(last, last + n1, -1);
    }
    // vertices are numbered 0 to n-1
    void addEdge(int u, int v) {
        //cout << u << " " << v << endl;
        head[edges] = v;
        pre[edges] = last[u];
        last[u] = edges++;
    }

    void bfs() {
        fill(dist, dist + n1, -1);
        int sizeQ = 0;
        for (int u = 0; u < n1; ++u) {
            if (!used[u]) {
                Q[sizeQ++] = u;
                dist[u] = 0;
            }
        }
        for (int i = 0; i < sizeQ; i++) {
            int u1 = Q[i];
            for (int e = last[u1]; e >= 0; e = pre[e]) {
                int u2 = matching[head[e]];
                if (u2 >= 0 && dist[u2] < 0) {
                    dist[u2] = dist[u1] + 1;
                    Q[sizeQ++] = u2;
                }
            }
        }
    }

    bool dfs(int u1) {
        vis[u1] = true;
        for (int e = last[u1]; e >= 0; e = pre[e]) {
            int v = head[e];
            int u2 = matching[v];
            if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
                matching[v] = u1;
                used[u1] = true;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        fill(used, used + n1, false);
        fill(matching, matching + n2, -1);
        for (int res = 0;;) {
            bfs();
            fill(vis, vis + n1, false);
            int f = 0;
            for (int u = 0; u < n1; ++u)
                if (!used[u] && dfs(u))
                    ++f;
            if (!f)
                return res;
            res += f;
        }
    }

};

int on[200001], ar[200001];
vector < int > vc[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> m >> n;
    FOR(i, 1, m+1){
        int k; cin >> k;
        REP(j, k){
            int v; cin >> v;
            if(v > 0) vc[v].pb(i);
            else vc[-v].pb(-i);
        }
    }

    hopcroft_karp HK;
    HK.init(n, m);


    FOR(i, 1, n+1){
//        add_edge(0, i, 1);
//        add_edge(i, i+_n, 1);
        if(vc[i].size() == 0) continue;
        if(vc[i].size() == 1){
            on[abs(vc[i][0])] = 1;
            continue;
        }
        if(vc[i][0] > 0 && vc[i][1] > 0){
            on[vc[i][0]] = 1;
            on[vc[i][1]] = 1;
        }
        else if(vc[i][0] < 0 && vc[i][1] < 0){
            on[-vc[i][0]] = 1;
            on[-vc[i][1]] = 1;
        }
    }

    FOR(i, 1, n+1){
        if(vc[i].size() == 0) continue;
        if(vc[i].size() == 1){
            on[abs(vc[i][0])] = 1;
            continue;
        }
        if(vc[i][0] > 0 && vc[i][1] > 0){
            on[vc[i][0]] = 1;
            on[vc[i][1]] = 1;
        }
        else if(vc[i][0] < 0 && vc[i][1] < 0){
            on[-vc[i][0]] = 1;
            on[-vc[i][1]] = 1;
        } else {
            if(on[abs(vc[i][0])] == 0) HK.addEdge(i-1, abs(vc[i][0])-1);
            if(on[abs(vc[i][1])] == 0) HK.addEdge(i-1, abs(vc[i][1])-1);
        }
    }

    int cnt = 0;
    FOR(i, 1, m+1){
        if(on[i] == 0){
            cnt++;
        }
    }


    int p = HK.maxMatching();
    if(p != cnt){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, m){
        if(HK.matching[i] == -1) continue;
        ar[ HK.matching[i]+1 ] = i+1;
    }

    FOR(i, 1, n + 1){
        if(vc[i].size() == 0) {
            cout << "1";
            continue;
        }
        if(vc[i].size() == 1){
            if(vc[i][0] > 0) cout << "1";
            else cout << "0";
            continue;
        }
        if(vc[i][0] > 0 && vc[i][1] > 0){
            cout << 1;
        }
        else if(vc[i][0] < 0 && vc[i][1] < 0){
            cout << 0;
        } else {
            if(ar[i] == abs(vc[i][0])){
                if(vc[i][0] < 0) cout << 0;
                else cout << 1;
            } else {
                if(vc[i][1] < 0) cout << 0;
                else cout << 1;
            }
        }
    }
    cout << endl;
}
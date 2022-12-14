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
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


struct hopcroft_karp {

    int n1, n2, edges, last[1001], pre[4001], head[4001];
    int matching[1001], dist[1001], Q[1001];
    bool used[1001], vis[1001];

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


pair < int, int > pp[1001];
int ar[501][501];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, b){
        cin >> c >> d;
        ar[c][d] = 1;
        pp[i] = mp(c, d);
    }
    d = inf;
    FOR(i, 1, a + 1){
        c = 0;
        FOR(j, 1, a + 1){
            if(j == i)c += 1 - ar[i][j];
            else c += 1 - ar[i][j] + 1 - ar[j][i];
        }
        hopcroft_karp hk;
        hk.init(a, a);
        f = 0;
        REP(j, b){
            if(pp[j].xx == i || pp[j].yy == i)continue;
            f++;
            hk.addEdge(pp[j].xx - 1, pp[j].yy - 1);
        }
        c += f + (a - 1) - 2 * hk.maxMatching();
        d = min(d, c);
    }
    cout << d << endl;
}
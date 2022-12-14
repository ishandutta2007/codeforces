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


vector < int > vc[100001];
vector<pair<int,int> > vp[100001];
LL sz[100001], sum[100001], lvl[100001], pre[100001];
int ST[100001], ED[100001], t;
void dfs(int c, int p, int d){
    sz[c]++;
    ST[c] = ++t;
    lvl[c] = d;
    pre[c] = p;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs(vc[c][i], c, d + 1);
        sz[c] += sz[vc[c][i]];
        sum[c] += sum[vc[c][i]] + sz[vc[c][i]];
        vp[c].pb(mp(ST[vc[c][i]], vc[c][i]));
    }
    ED[c] = t;
}
LL up[100001], down[100001];
void dfs1(int c, int p, pair<LL,LL> pp){
    pp.xx += sum[c];
    pp.yy += sz[c];
    up[c] = pp.xx;
    down[c] = pp.yy;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        pair<LL,LL> q = pp;
        q.yy -= sz[vc[c][i]];
        q.xx -= sum[vc[c][i]] + sz[vc[c][i]];
        q.xx += q.yy;
        dfs1(vc[c][i], c, q);
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



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    dfs(1, 0, 1);
    dfs1(1, 0, mp(0, 0));
    pre_process(n);

//    FOR(i, 1, n+1) cout << sz[i] << " " << sum[i] << " " << up[i] << " " << lvl[i] << endl;

    REP(i, m){
        int x, y; cin >> x >> y;
        int lca = LCA(x, y);
        if(lvl[x] > lvl[y]) swap(x, y);
        LL cnt1 = 0, sum1 = 0;
        if(lca == x){
            int id = upper_bound(vp[x].begin(), vp[x].end(), mp(ST[y], 10000000)) - vp[x].begin();
            id--;
            int p = vp[x][id].yy;
            sum1 = up[x] - sum[p] - sz[p];
            cnt1 = down[x] - sz[p];
        } else {
            sum1 = sum[x];
            cnt1 = sz[x];
        }
        LL sum2 = sum[y], cnt2 = sz[y];

//        cout << sum1 << " " << cnt1 << " " << sum2 << " " << cnt2 << endl;

        LL divide = cnt2 * cnt1;
        LL res1 = lvl[x] + lvl[y] - 2*lvl[lca] + 1;
        LL res2 = (sum1 * cnt2 + sum2 * cnt1) / (cnt1 * cnt2);
        LL md = (sum1 * cnt2 + sum2 * cnt1) % (cnt1 * cnt2);

        long double res = (long double)(md) / (long double)(cnt1 * cnt2);
        res += res1 + res2;

        cout << fixed << setprecision(10) << res << endl;
    }
}
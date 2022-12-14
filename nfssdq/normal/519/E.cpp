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
int pre[100001],lvl[100001];
int sz[100001];
int dfs(int c, int p, int d){
    pre[c] = p;
    lvl[c] = d;
    sz[c] = 1;
    REP(i, vc[c].size()){
        if(vc[c][i] != p) {
            dfs(vc[c][i], c, d + 1);
            sz[c] += sz[ vc[c][i] ];
        }
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

int go(int cur, int dd){
    for(int i = 20; i >= 0; i--){
        if(P[cur][i] == -1) continue;
        if((1<<i) > dd) continue;

        dd -= (1<<i);
        cur = P[cur][i];
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    REP(i, N - 1){
        int a, b;
        cin >> a >> b;
        vc[a].pb(b);
        vc[b].pb(a);
    }

    dfs(1, 0, 1);
    pre_process(N);

    int Q; cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;

        if(a == b){
            cout << N << endl;
            continue;
        }

        int ln = LCA(a, b);

        int dd = lvl[a] + lvl[b] - lvl[ln]*2;
        if(dd % 2 == 1){
            cout << 0 << endl;
            continue;
        }

        if(lvl[a] < lvl[b]) swap(a, b);

        dd /= 2;


        int cur = go(a, dd);

        int curdone = go(a, dd - 1);



        int res = sz[cur];
        res -= sz[ curdone ];

        if(cur == ln){
            res = N;
            res -= sz[ go(a, dd - 1)];
            res -= sz[ go(b, dd - 1)];
        }

        cout << res << endl;


    }


}
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

LL seg[800001][2];
void insert(int idx, int s, int e, int p, int v1, int v2){
    if(s == e){
        seg[idx][0] = v1; seg[idx][1] = v2;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v1, v2);
    else if(p > mid) insert(idx * 2 + 2, mid + 1, e, p, v1, v2);
    seg[idx][0] = max(seg[idx * 2 + 1][0], seg[idx * 2 + 2][0]);
    seg[idx][1] = max(seg[idx * 2 + 1][1], seg[idx * 2 + 2][1]);
}
pair < int, int > query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed){
        return mp(seg[idx][0], seg[idx][1]);
    }
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        pair < int, int > p1 = query(idx * 2 + 1, s, mid, st, mid);
        pair < int, int > p2 = query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        return mp(max(p1.xx, p2.xx), max(p1.yy, p2.yy));
    }
}
LL ar[200011], hi[200011], dp[200011][2];
vector < int > vc[200011], vp[200011];
LL dis[200011], P[200011][22], pre[200011];
void dfs(int c, int p, LL d){
    dis[c] = d;
    pre[c] = p;
    REP(i, vc[c].size()){
        dfs(vc[c][i], c, d + vp[c][i]);
    }
}
void pre_process(int N){
    memset(P,-1,sizeof P);
    for(int i = 1; i <= N; i++)P[i][0] = pre[i];
    for(int j = 1; (1<<j) <= N; j++){
        for(int i = N; i >= 1; i--){
            if(P[i][j - 1] != -1) P[i][j] = P[ P[i][j - 1] ][j - 1];
        }
    }
}
int LCA(int p, int q, int N){
    for(int i = p; i <= N; ){
        int c = P[i][0];
        if(c > q) return i;
        for(int j = 1; j <= 21; j++){
            if(P[i][j] == -1) break;
            if(P[i][j] > q) break;
            c = P[i][j];
        }
        i = c;
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c=0,d,e = 0,f = 0,g = 0,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> ar[i] >> hi[i];
        insert(0, 1, a, i, i, ar[i]+hi[i]);
    }
    ar[a+1] = ar[a];
    for(int i = a; i >= 1; i--){
        b = upper_bound(ar + 1, ar + 1 + a, ar[i] + hi[i]) - ar;
        b--;
        pair < int, int > pp = query(0, 1, a, i, b);
        dp[i][0] = pp.xx; dp[i][1] = max((LL)pp.yy, ar[i]+hi[i]);
        insert(0, 1, a, i, dp[i][0], dp[i][1]);
        vc[ pp.xx+1 ].pb(i);
        vp[ pp.xx +1].pb(ar[pp.xx+1] - pp.yy);
    }
    dfs(a + 1, a + 2, 0);
    pre_process(a + 1);
    cin >> b;
    REP(i, b){
        cin >> c >> d;
        e = LCA(c, d, a + 1);
        cout << dis[c] - dis[e] << endl;
    }
}
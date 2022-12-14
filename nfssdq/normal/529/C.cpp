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
#define mod        1000000009ll
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

int seg[400001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else return min(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}
vector < int > vc[100001], qq[100001], vp[100001];
int qv[200001][4], res[200001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,q; cin >> n >> m >> k >> q;
    REP(i, k){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vp[y].pb(x);
    }
    REP(i, q){
        REP(j, 4) cin >> qv[i][j];
        qq[ qv[i][2] ].pb(i);
    }
    for(int i = 1; i <= n; i++){
        REP(j, vc[i].size()) insert(0, 1, m, vc[i][j], i);
        REP(j, qq[i].size()){
            int c = qq[i][j];
            int x1 = qv[c][0], y1 = qv[c][1], x2 = qv[c][2], y2 = qv[c][3];
            int v = query(0, 1, m, y1, y2);
            if(v >= x1) res[c]++;
        }
        qq[i].clear();
    }
    REP(i, q){
        qq[qv[i][3]].pb(i);
    }
    set0(seg);
    for(int i = 1; i <= m; i++){
        REP(j, vp[i].size()) insert(0, 1, n, vp[i][j], i);
        REP(j, qq[i].size()){
            int c = qq[i][j];
            int x1 = qv[c][0], y1 = qv[c][1], x2 = qv[c][2], y2 = qv[c][3];
            int v = query(0, 1, n, x1, x2);
            if(v >= y1) res[c]++;
        }
    }
    REP(i, q){
        if(res[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
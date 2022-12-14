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

LL seg[400001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
int query(int idx, int s, int e, int st, int ed){
    if(st > ed) return 0;
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        return max(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
    }
}
vector < int > vc[100011], val[100011], vp[100011];
LL ar[100001], res[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1) cin >> ar[i];
    for(int i = a; i >= 1; i--){
        b = query(0, 1, 100000, ar[i] + 1, 100000) + 1;
        vc[b].pb(i);
        insert(0, 1, 100000, ar[i], b);
        f = max(f, b);
    }
    vc[f + 1].pb(0); val[f + 1].pb(0);
    for(int i = f; i >= 1; i--){
        vsort(vc[i]);
        REP(j, vc[i].size()){
            c = lower_bound(vc[i + 1].begin(), vc[i + 1].end(), vc[i][j]) - vc[i + 1].begin();
            if(c == 0) {
                res[ vc[i][j] ] = 1;
                continue;
            }
            c--;
            if(val[i + 1][c] < ar[ vc[i][j] ]) vp[i].pb(vc[i][j]);
            else res[ vc[i][j] ] = 1;
        }
        REP(j, vp[i].size()){
            if(vp[i].size() > 1) res[ vp[i][j] ] = 2;
            else res[ vp[i][j] ] = 3;
            val[i].pb( ar[ vp[i][j] ] );
        }
        vc[i] = vp[i];
        FOR(j, 1, vc[i].size()) val[i][j] = min(val[i][j], val[i][j - 1]);
    }
    FOR(i, 1, a + 1) cout << res[i];
    cout << endl;
}
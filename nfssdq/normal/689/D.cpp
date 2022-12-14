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

pair < LL, LL > seg[2][800001];
void insert(int f, int idx, int s, int e, int p, int v){
    if(s == e){
        seg[f][idx] = mp(v, p);
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(f, idx * 2 + 1, s, mid, p, v);
    else insert(f, idx * 2 + 2, mid + 1, e, p, v);
    if(f) seg[f][idx] = min(seg[f][idx * 2 + 1], seg[f][idx * 2 + 2]);
    else seg[f][idx] = max(seg[f][idx * 2 + 1], seg[f][idx * 2 + 2]);
}
int queryL(int f, int idx, int s, int e, int st, int ed, int v){
    if(seg[f][idx].xx >= v) return st;
    if(s == e) return e + 1;
    int mid = (s + e) / 2;
    if(ed <= mid) return queryL(f, idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) return queryL(f, idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        int p = queryL(f, idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
        if(p == mid + 1) return queryL(f, idx * 2 + 1, s, mid, st, mid, v);
        else return p;
    }
}
int queryR(int f, int idx, int s, int e, int st, int ed, int v){
    if(seg[f][idx].xx >= v) return ed;
    if(s == e) return s - 1;
    int mid = (s + e) / 2;
    if(ed <= mid) return queryR(f, idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) return queryR(f, idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        int p = queryR(f, idx * 2 + 1, s, mid, st, mid, v);
        if(p == mid) return queryR(f, idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
        else return p;
    }
}

pair < LL, LL > query(int f, int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[f][idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(f, idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(f, idx * 2 + 2, mid + 1, e, st, ed);
    else {
        return max(query(f, idx * 2 + 1, s, mid, st, mid),
                   query(f, idx * 2 + 2, mid + 1, e, mid + 1, ed));
    }
}


vector < int > vc[400001];
int ar[2][200001];
map < int, int > mm;


LL out;

void go(int l, int r, int n){
    if(l > r) return;
    pair < LL, LL > p = query(0, 0, 1, n, l, r);
    go(l, p.yy - 1, n);
    go(p.yy + 1, r, n);

    int rv = queryR(1, 0, 1, n, p.yy, r, p.xx);
    int lv = queryL(1, 0, 1, n, l, p.yy, p.xx);
    if(rv < p.yy || lv > p.yy) return;
    rv = min(rv, r);
    lv = max(lv, l);
//    cout << lv << " " << rv << " " << p.yy << endl;

    out += (rv - p.yy + 1) * (p.yy - lv + 1);

    int c = mm[p.xx];
    int lb = lower_bound(vc[c].begin(), vc[c].end(), p.yy) - vc[c].begin();
    if(lb == vc[c].size() || vc[c][lb] > rv);
    else rv = vc[c][lb] - 1;
    lb--;
    if(lb < 0 || vc[c][lb] < lv);
    else lv = vc[c][lb] + 1;
    if(rv < p.yy || lv > p.yy) return;

    out -= (rv - p.yy + 1) * (p.yy - lv + 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, 2) FOR(j, 1, n+1) {
        cin >> ar[i][j];
        mm[ar[i][j]] = 1;
    }
    int cnt = 0;
    for(auto &v: mm){
        v.yy = ++cnt;
    }
    FOR(i, 1, n+1){
        vc[ mm[ar[1][i]] ].pb(i);
        insert(1, 0, 1, n, i, ar[1][i]);
        insert(0, 0, 1, n, i, ar[0][i]);
    }

//    LL res = 0;
//    FOR(i, 1, n+1){
//        LL r = queryR(1, 0, 1, n, i, n, ar[0][i]);
//        LL l = queryL(1, 0, 1, n, 1, i, ar[0][i]);
//        if(r < i || l > i) continue;
//        res += (r-i+1) * (i-l+1);
//
//        cout << l << " " << r << " " << i << endl;
//
//        int c = mm[ar[0][i]];
//        int lb = lower_bound(vc[c].begin(), vc[c].end(), i) - vc[c].begin();
//        if(lb == vc[c].size() || vc[c][lb] > r);
//        else r = vc[c][lb] - 1;
//        lb--;
//        if(lb < 0 || vc[c][lb] < l);
//        else l = vc[c][lb] + 1;
//
//        if(r < i || l > i) continue;
//
//        cout << l << " " << r << " " << i << " 222  " << endl;
//
//        res -= (r-i+1) * (i-l+1);
//    }

    go(1, n, n);
    cout << out << endl;
}
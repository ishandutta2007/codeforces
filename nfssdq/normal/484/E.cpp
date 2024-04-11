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


struct node{
    int mx, lft, rgt, l, r;
    node(){
        mx = lft = rgt = 0;
        l = r = -1;
    };
};
vector < node > seg;
int pos[100011];
int insert(int idx, int s, int e, int p){
    seg.pb(node());
    seg[seg.size() - 1] = seg[idx];
    idx = seg.size() - 1;
    if(s == e){
        seg[idx].mx = seg[idx].lft = seg[idx].rgt = 1;
        return idx;
    }
    int mid = (s + e) / 2;
    if(seg[idx].l == -1){
        seg.pb(node());
        seg[idx].l = seg.size() - 1;
    }
    if(seg[idx].r == -1){
        seg.pb(node());
        seg[idx].r = seg.size() - 1;
    }
    if(p <= mid) {
        int q = insert(seg[idx].l, s, mid, p);
        seg[idx].l = q;
    }
    else {
        int q = insert(seg[idx].r, mid + 1, e, p);
        seg[idx].r = q;
    }
    seg[idx].mx = max(seg[ seg[idx].l ].mx, seg[ seg[idx].r ].mx);
    seg[idx].mx = max(seg[idx].mx, seg[ seg[idx].l ].rgt + seg[ seg[idx].r ].lft);
    seg[idx].lft = seg[ seg[idx].l ].lft;
    if(seg[idx].lft == mid - s + 1) seg[idx].lft += seg[ seg[idx].r ].lft;
    seg[idx].rgt = seg[ seg[idx].r ].rgt;
    if(seg[idx].rgt == e - mid) seg[idx].rgt += seg[ seg[idx].l ].rgt;
    return idx;
}
node query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(seg[idx].l == -1){
        seg.pb(node());
        seg[idx].l = seg.size() - 1;
    }
    if(seg[idx].r == -1){
        seg.pb(node());
        seg[idx].r = seg.size() - 1;
    }
    if(ed <= mid) return query(seg[idx].l, s, mid, st, ed);
    else if(st > mid) return query(seg[idx].r, mid + 1, e, st, ed);
    else {
        node vl = query(seg[idx].l, s, mid, st, mid);
        node vr = query(seg[idx].r, mid + 1, e, mid + 1, ed);
        node ret = node();
        ret.mx = max(vl.mx, vr.mx);
        ret.mx = max(ret.mx, vl.rgt + vr.lft);
        ret.lft = vl.lft;
        if(vl.lft == mid - st + 1) ret.lft += vr.lft;
        ret.rgt = vr.rgt;
        if(vr.rgt == ed - mid) ret.rgt += vl.rgt;
        return ret;
    }
}
pair < int, int > pp[100011];
LL ar[100001];
LL go(int m, int n, int l, int r){
    int c = lower_bound(pp + 1, pp + n + 1, mp(m, 0)) - pp;
    node res = query(pos[c], 1, n, l, r);
    return res.mx;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e = 0,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> ar[i];
        pp[i] = mp(ar[i], i);
    }
    sort(pp + 1, pp + a + 1);
    seg.pb(node());
    for(int i = a; i >= 1; i--){
        pos[i] = insert(pos[i + 1], 1, a, pp[i].yy);
    }
    cin >> b;
    REP(i, b){
        cin >> c >> d >> e;
        int lo = 1, hi = pp[a].xx, mid = (lo + hi) / 2;
        while(lo < mid){
            if(go(mid, a, c, d) >= e) lo = mid;
            else hi = mid - 1;
            mid = (lo + hi) / 2;
        }
        if(go(mid + 1, a, c, d) >= e) mid++;
        cout << mid << "\n";
    }
}
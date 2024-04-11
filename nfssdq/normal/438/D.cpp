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

LL seg[400001], mx[400001], ar[100001];
void build(int idx, int s, int e){
    if(s == e){
        seg[idx] = mx[idx] = ar[s];
        return;
    }
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    mx[idx] = max(mx[idx * 2 + 1], mx[idx * 2 + 2]);
}
void insert(int idx, int s, int e, int st, int ed, LL x){
    if(mx[idx] < x) return;
    if(s == e){
        mx[idx] %= x;
        seg[idx] = mx[idx];
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, x);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, x);
    else{
        insert(idx * 2 + 1, s, mid, st, mid, x);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, x);
    }
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    mx[idx] = max(mx[idx * 2 + 1], mx[idx * 2 + 2]);
}
void insert1(int idx, int s, int e, int p, int v){
    if(s == e){
        mx[idx] = v;
        seg[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert1(idx * 2 + 1, s, mid, p, v);
    else insert1(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    mx[idx] = max(mx[idx * 2 + 1], mx[idx * 2 + 2]);
}
LL query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else{
        return (query(idx * 2 + 1, s, mid, st, mid)+
        query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b = 0,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a >> b;
    FOR(i, 1, a + 1) cin >> ar[i];
    build(0, 1, a);
    REP(i, b){
        cin >> c >> d >> e;
        if(c == 1) cout << query(0, 1, a, d, e) << endl;
        else if(c == 3) insert1(0, 1, a, d, e);
        else {
            cin >> f;
            insert(0, 1, a, d, e, f);
        }
    }
}
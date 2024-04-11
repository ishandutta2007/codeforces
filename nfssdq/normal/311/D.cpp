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
#define ALL(A)     A.begin(), A.end()
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

LL seg[400001], ss[400001][48], ar[100001][48];
void update(int idx, int s, int e){
    if(s == e){
        seg[idx] = 0;
        return;
    }
    seg[idx * 2 + 1] = (seg[idx * 2 + 1] + seg[idx]) % 48;
    seg[idx * 2 + 2] = (seg[idx * 2 + 2] + seg[idx]) % 48;
    int tmp[48];
    REP(i, 48) tmp[i] = ss[idx * 2 + 1][i];
    for(int i = seg[idx]; i < 48 + seg[idx]; i++)
        ss[idx * 2 + 1][i - seg[idx]] = tmp[i%48];
    REP(i, 48) tmp[i] = ss[idx * 2 + 2][i];
    for(int i = seg[idx]; i < 48 + seg[idx]; i++)
        ss[idx * 2 + 2][i - seg[idx]] = tmp[i%48];
    seg[idx] = 0;
}
void insert(int idx, int s, int e, int st, int ed, int v){
    if(seg[idx] > 0) update(idx, s, e);
    if(s == st && e == ed){
        seg[idx] = (seg[idx] + v) % 48;
        int tmp[48];
        REP(i, 48) tmp[i] = ss[idx][i];
        for(int i = seg[idx]; i < 48 + seg[idx]; i++) ss[idx][i - seg[idx]] = tmp[i%48];
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, v);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
    REP(i, 48) ss[idx][i] = (ss[idx * 2 + 1][i] + ss[idx * 2 + 2][i]) % 95542721;
}
LL query(int idx, int s, int e, int st, int ed, int v){
    if(seg[idx]) update(idx, s, e);
    if(s == st && e == ed){
        return ss[idx][0];
    }
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed, v);
    else return (query(idx * 2 + 1, s, mid, st, mid, v) +
                 query(idx * 2 + 2, mid + 1, e, mid + 1, ed, v)) % 95542721;
}
void build(int idx, int s, int e){
    if(s == e){
        REP(i, 48) ss[idx][i] = ar[s][i];
        return;
    }
    int mid = (s + e) / 2;
    build(idx * 2 + 1, s, mid);
    build(idx * 2 + 2, mid + 1, e);
    REP(i, 48) ss[idx][i] = (ss[idx * 2 + 1][i] + ss[idx * 2 + 2][i]) % 95542721;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g,h = 0,x,y,z = 0;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> b;
        ar[i][0] = b;
        FOR(j, 1, 48){
            ar[i][j] = (((ar[i][j-1]*ar[i][j-1])%95542721)*ar[i][j-1])%95542721;
        }
    }
    build(0, 1, a);
    cin >> b;
    REP(i, b){
        cin >> c >> d >> e;
        if(c == 2){
            insert(0, 1, a, d, e, 1);
        } else cout << query(0, 1, a, d, e, 0) << endl;
    }
}
/*
3355543321
1234567890
*/
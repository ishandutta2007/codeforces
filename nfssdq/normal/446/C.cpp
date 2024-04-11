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
#define PI         2.0*acos(0.0)
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

#define MX 3

LL mul_res[MX][MX];
void multiply(LL a[][MX], LL b[][MX]){
    set0(mul_res);
    for(int i = 0; i < MX; i++){
        for(int j = 0; j < MX; j++){
            for(int k = 0; k < MX; k++)
                mul_res[i][j] = (mul_res[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
}


LL mat[300001][3][3], big_res[3][3], init[3][3];

LL lzy[1300001][2], seg[1300001], fib[300001], SUM[300001];
void update(int idx, int s, int e){
    if(s == e){
        lzy[idx][0] = lzy[idx][1] = 0;
        return;
    }

    int mid = (s + e) / 2;

    REP(i, 3) REP(j, 3) big_res[i][j] = mat[mid - s][i][j];

    LL vl1 = (lzy[idx][0] * big_res[2][2] + lzy[idx][1] * big_res[2][1]) % mod;
    vl1 = (vl1 + (lzy[idx][0] + lzy[idx][1]) * big_res[2][0]) % mod;

    LL vl2 = (lzy[idx][0] * big_res[1][2] + lzy[idx][1] * big_res[1][1]) % mod;
    vl2 = (vl2 + (lzy[idx][0] + lzy[idx][1]) * big_res[1][0]) % mod;

    LL s1 = (lzy[idx][0] * big_res[0][2] + lzy[idx][1] * big_res[0][1]) % mod;
    s1 = (s1 + (lzy[idx][0] + lzy[idx][1]) * big_res[0][0]) % mod;

    seg[idx * 2 + 1] = (seg[idx * 2 + 1] + s1 - lzy[idx][0] + mod) % mod;
    lzy[idx * 2 + 1][0] = (lzy[idx * 2 + 1][0] + lzy[idx][0]) % mod;
    lzy[idx * 2 + 1][1] = (lzy[idx * 2 + 1][1] + lzy[idx][1]) % mod;
    lzy[idx * 2 + 2][0] = (lzy[idx * 2 + 2][0] + vl2) % mod;
    lzy[idx * 2 + 2][1] = (lzy[idx * 2 + 2][1] + vl1 + vl2) % mod;

    REP(i, 3) REP(j, 3) big_res[i][j] = mat[e - s][i][j];

    LL s2 = (lzy[idx][0] * big_res[0][2] + lzy[idx][1] * big_res[0][1]) % mod;
    s2 = (s2 + (lzy[idx][0] + lzy[idx][1]) * big_res[0][0]) % mod;
    seg[idx * 2 + 2] = (seg[idx * 2 + 2] + s2 - s1 + mod) % mod;

    lzy[idx][0] = lzy[idx][1] = 0;
}
void insert(int idx, int s, int e, int st, int ed, LL v1, LL v2, LL p){
    if(lzy[idx][0] != 0 || lzy[idx][1] != 0) update(idx, s, e);
    if(s == st && e == ed){
        seg[idx] = (seg[idx] + SUM[p + e - s] - SUM[p - 1] + mod) % mod;
        lzy[idx][0] = v1;
        lzy[idx][1] = v2;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, v1, v2, p);
    else if(st > mid) insert(idx * 2 + 2, mid + 1, e, st, ed, v1, v2, p);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, v1, v2, p);
        p += mid - st + 1;
        v1 = fib[p - 1];
        v2 = fib[p];
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, v1, v2, p);
    }
    seg[idx] = (seg[idx * 2 + 1] + seg[idx * 2 + 2]) % mod;
}
LL query(int idx, int s, int e, int st, int ed){
    if(lzy[idx][0] != 0 || lzy[idx][1] != 0) update(idx, s, e);
    if(s == st && e == ed) return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else return (query(idx * 2 + 1, s, mid, st, mid) +
                 query(idx * 2 + 2, mid + 1, e, mid + 1, ed)) % mod;
}
LL ar[300001], ss[300001];
main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f,g,h = 0,x,y,z;
    init[0][0] = 1; init[0][1] = 1; init[0][2] = 1;
    init[1][0] = 0; init[1][1] = 1; init[1][2] = 1;
    init[2][0] = 0; init[2][1] = 1; init[2][2] = 0;

    REP(i, 3) big_res[i][i] = mat[0][i][i] = 1;

    for(int i = 1; i <= 300000; i++){
        multiply(big_res, init);
        REP(j, 3) REP(k, 3) mat[i][j][k] = mul_res[j][k];
        REP(j, 3) REP(k, 3) big_res[j][k] = mul_res[j][k];
    }

    cin >> a >> b;
    fib[0] = SUM[0] = 0; fib[1] = SUM[1] = 1;
    for(int i = 2; i <= a; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        SUM[i] = (fib[i] + SUM[i - 1]) % mod;
    }
    FOR(i, 1, a + 1){
        cin >> ar[i];
        ss[i] = (ar[i] + ss[i - 1]) % mod;
    }
    REP(i, b){
        cin >> c >> d >> e;
        if(c == 1) insert(0, 1, a, d, e, fib[0], fib[1], 1);
        else cout << (query(0, 1, a, d, e) + ss[e] - ss[d - 1] + mod) % mod << endl;
    }
}
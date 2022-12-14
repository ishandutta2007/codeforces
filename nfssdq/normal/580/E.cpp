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


LL base1 = 11, base2 = 17;
LL mod1 = mod, mod2 = mod + 2;
LL p1[100001], p2[100001];
LL s1[100001], s2[100001];
string S;
LL seg[400001][2], lzy[400001];
void update(int idx, int s, int e){
    if(s == e){
        lzy[idx] = 0;
        return;
    }
    lzy[idx]--;
    int mid = (s + e) / 2;
    seg[idx * 2 + 1][0] = (lzy[idx] * s1[mid - s]) % mod1;
    seg[idx * 2 + 1][1] = (lzy[idx] * s2[mid - s]) % mod2;

    seg[idx * 2 + 2][0] = (lzy[idx] * s1[e - mid - 1]) % mod1;
    seg[idx * 2 + 2][1] = (lzy[idx] * s2[e - mid - 1]) % mod2;

    lzy[idx * 2 + 1] = lzy[idx] + 1;
    lzy[idx * 2 + 2] = lzy[idx] + 1;

    lzy[idx] = 0;
}
void insert(int idx, int s, int e, int st, int ed, LL v){
    if(lzy[idx]) update(idx, s, e);
    if(s == st && e == ed){
        seg[idx][0] = (v * s1[e-s]) % mod1;
        seg[idx][1] = (v * s2[e-s]) % mod2;
        lzy[idx] = v + 1;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid) insert(idx * 2 + 1, s, mid, st, ed, v);
    else if(st > mid)insert(idx * 2 + 2, mid + 1, e, st, ed, v);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, v);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
    }
    seg[idx][0] = (seg[idx * 2 + 1][0] + seg[idx * 2 + 2][0] * p1[mid - s + 1]) % mod1;
    seg[idx][1] = (seg[idx * 2 + 1][1] + seg[idx * 2 + 2][1] * p2[mid - s + 1]) % mod2;
}
pair < LL, LL > query(int idx, int s, int e, int st, int ed){
    if(lzy[idx]) update(idx, s, e);
    if(s == st && e == ed) return mp(seg[idx][0], seg[idx][1]);
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        pair < LL, LL > vl = query(idx * 2 + 1, s, mid, st, mid);
        pair < LL, LL > vr = query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        pair < LL, LL > ret;
        ret.xx = vl.xx + vr.xx * p1[mid - st + 1];
        ret.yy = vl.yy + vr.yy * p2[mid - st + 1];
        ret.xx %= mod1; ret.yy %= mod2;
        return ret;
    }
}
int n;
int go(int l, int r, int d){
    int p = (r - l + 1) / d;
    int rem = r-l+1 - p*d;
    if(rem){
        if(query(0, 0, n-1, l, l + rem - 1) != query(0, 0, n-1, r - rem + 1, r))
            return 0;
        return go(l, r - rem, d);
    }
    if(p % 2 == 1){
        if(p == 1) return 1;
        rem = d;
        if(query(0, 0, n-1, l, l + rem - 1) != query(0, 0, n-1, r - rem + 1, r))
            return 0;
        return go(l, r - rem, d);
    }
    int mid = (l + r) / 2;
    if(query(0, 0, n-1, l, mid) != query(0, 0, n-1, mid + 1, r)) return 0;
    return go(l, mid, d);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    base1 = rand() % 101;
    base2 = rand() % 103;

    p1[0] = p2[0] = 1;
    s1[0] = s2[0] = 1;
    FOR(i, 1, 100001){
        p1[i] = (p1[i-1] * base1) % mod1;
        p2[i] = (p2[i-1] * base2) % mod2;
        s1[i] = (p1[i] + s1[i-1]) % mod1;
        s2[i] = (p2[i] + s2[i-1]) % mod2;
    }


    int m, k; cin >> n >> m >> k;
    cin >> S;
    REP(i, n){
        insert(0, 0, n-1, i, i, S[i] - '0');
    }
    REP(i, m+k){
        int t, l, r, v; cin >> t >> l >> r >> v;
        if(t == 1){
            insert(0, 0, n-1, l-1, r-1, v);
        } else {
            if(go(l-1, r-1, v)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

}
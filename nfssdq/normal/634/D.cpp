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

LL seg[900001], pos[900001];
void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx] = v;
        pos[idx] = s;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid) insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    if(seg[idx * 2 + 1] <= seg[idx * 2 + 2]){
        seg[idx] = seg[idx * 2 + 1];
        pos[idx] = pos[idx * 2 + 1];
    } else {
        seg[idx] = seg[idx * 2 + 2];
        pos[idx] = pos[idx * 2 + 2];
    }
}
pair < LL, LL > query(int idx, int s, int e, int st, int ed){
    if(st > ed) return mp(mod, -1);
    if(s == st && e == ed) return mp(seg[idx], pos[idx]);
    int mid = (s + e) / 2;
    if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        pair < LL, LL > pl = query(idx * 2 + 1, s, mid, st, mid);
        pair < LL, LL > pr = query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        if(pl.xx <= pr.xx) return pl;
        return pr;
    }
}

pair < LL, LL > pp[200021];
LL n,m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL d; cin >> d >> n >> m;
    REP(i, m) cin >> pp[i].xx >> pp[i].yy;
    pp[m++] = mp(0, 0);
    pp[m++] = mp(d, 0);
    sort(pp, pp + m);

    REP(i, m) insert(0, 0, m-1, i, pp[i].yy);

    FOR(i, 1, m) if(pp[i].xx - pp[i-1].xx > n){
        cout << -1 << endl;
        return 0;
    }


    LL res = 0, carry = n;
    int lft = 0, rgt = 2;
    while(rgt < m){
        while(rgt < m && pp[rgt].xx-pp[lft].xx <= carry) rgt++;

        pair < LL, LL > p = query(0, 0, m-1, lft+1, rgt-1);
        carry -= pp[p.yy].xx - pp[lft].xx;

        while(rgt < m){
            if(pp[rgt].xx-pp[p.yy].xx > n) break;

            if(pp[rgt].yy <= pp[p.yy].yy){
                res += (pp[rgt].xx-pp[p.yy].xx-carry) * pp[p.yy].yy;
                p = mp(pp[rgt].yy, rgt);
                carry = 0;
            }
            rgt++;
        }

        lft = p.yy;
        if(rgt >= m) break;
        res += (n - carry) * pp[p.yy].yy;
        carry = n;
    }

    cout << res << endl;
}
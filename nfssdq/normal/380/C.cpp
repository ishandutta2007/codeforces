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
#define mod        100000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

struct node {
    int sum, lc, rc;
} seg[4000001];

void insert(int idx, int s, int e, int p, int v){
    if(s == e){
        seg[idx].sum = seg[idx].lc = seg[idx].rc = 0;
        if(v == 0)seg[idx].lc++;
        else seg[idx].rc++;
        return;
    }
    int mid = (s + e) / 2;
    if(p <= mid)insert(idx * 2 + 1, s, mid, p, v);
    else insert(idx * 2 + 2, mid + 1, e, p, v);
    seg[idx].sum = seg[idx * 2 + 1].sum + seg[idx * 2 + 2].sum;
    int pp = min(seg[idx * 2 + 1].lc, seg[idx * 2 + 2].rc);
    seg[idx].sum += pp;
    seg[idx].lc = seg[idx * 2 + 1].lc + seg[idx * 2 + 2].lc - pp;
    seg[idx].rc = seg[idx * 2 + 1].rc + seg[idx * 2 + 2].rc - pp;
}
node query(int idx, int s, int e, int st, int ed){
    if(s == st && e == ed)return seg[idx];
    int mid = (s + e) / 2;
    if(ed <= mid)return query(idx * 2 + 1, s, mid, st, ed);
    else if(st > mid)return query(idx * 2 + 2, mid + 1, e, st, ed);
    else {
        node l = query(idx * 2 + 1, s, mid, st, mid);
        node r = query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
        node ret;
        int pp = min(l.lc, r.rc);
        ret.sum = l.sum + r.sum + pp;
        ret.lc = l.lc + r.lc - pp;
        ret.rc = l.rc + r.rc - pp;
        return ret;
    }
}
char pp[1000001];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 1,x,y,z;
    cin >> pp;
    a = strlen(pp);
    REP(i, a){
        if(pp[i] == '(')insert(0, 1, a, i + 1, 0);
        else insert(0, 1, a, i + 1, 1);
    }
    cin >> b;
    REP(i, b){
        cin >> c >> d;
        node tmp = query(0, 1, a, c, d);
        cout << tmp.sum * 2 << endl;
    }
}
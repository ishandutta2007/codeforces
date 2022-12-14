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
#define PI         2.0*acos(0.0)
#define linf       (1ll<<62)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)(((LL)bigmod(p,e-1,M)*(LL)(p))%M);
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL seg[1200001], ar[300001];
void insert(int idx, int s, int e, int st, int ed, int p){
    if(st > ed)return;
    if(seg[idx] != 0)return;
    if(s == st && e == ed){
        seg[idx] = p;
        return;
    }
    int mid = (s + e) / 2;
    if(ed <= mid)insert(idx * 2 + 1, s, mid, st, ed, p);
    else if(st > mid)insert(idx * 2 + 2, mid + 1, e, st, ed, p);
    else {
        insert(idx * 2 + 1, s, mid, st, mid, p);
        insert(idx * 2 + 2, mid + 1, e, mid + 1, ed, p);
    }
}
int query(int idx, int s, int e, int p, int v){
    if(s == e){
        if(seg[idx] != 0)return seg[idx];
        return v;
    }
    int mid = (s + e) / 2;
    if(seg[idx] != 0)v = seg[idx];
    if(p <= mid)return query(idx * 2 + 1, s, mid, p, v);
    else return query(idx * 2 + 2, mid + 1, e, p, v);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, b){
        cin >> c >> d >> e;
        insert(0, 1, a, c, e - 1, e);
        insert(0, 1, a, e + 1, d, e);
    }
    for(int i = 1; i <= a; i++)cout << query(0, 1, a, i, 0) << " ";
}
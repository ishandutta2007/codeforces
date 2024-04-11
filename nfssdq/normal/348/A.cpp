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
#define linf       (1ll<<60)-1
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

LL ar[100001];
LL tmp[100001], cst[100001];
LL go(LL a, LL  b){
    set0(tmp);
    set0(cst);
    LL cur = 0;
    for(int i = b - 1; i >= 0; i--){
        LL d = ar[i] - cur;
        if(d < 0)d = 0;
        cst[i] = d;
        LL c = a - d;
        if(c < 0)c = 0;
        tmp[i] = c;
        a -= c;
        cur += c;
    }
    cur = 0;
    REP(i, b){
        if(cst[i] > cur)return 0;
        cur += tmp[i];
    }
    return 1;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e,f,g,h = 1,x,y,z;
    cin >> a;
    REP(i, a)cin >> ar[i];
    sort(ar, ar + a);
    b = 0; c = mod * 10000000ll;
    d = (b + c) / 2;
    while(b < d){
        e = go(d, a);
        if(e == 1)c = d;
        else b = d + 1;
        d = (b + c) / 2;
    }
    if(go(d, a) == 0)d++;
    cout << d << endl;
}
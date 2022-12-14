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

#include<bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define ui         unsigned int
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

template <class T> inline T bigmod(T p,T e) {
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2);return (T)(t*t);}
    return (T)(((LL)bigmod(p,e-1)*(LL)(p)));
}
template <class T> inline T gcd(T a,T b) {if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M) {return bigmod(a,M-2,M);}


main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d,e = 0,f,g,h = 1,x = 99999999,y,z = 1;
    cin >> a >> b >> c >> d >> e >> f;
    if((c - 1) % e == 0 && (d - 1) % f == 0){
        y = (c - 1) / e;
        z = (d - 1) / f;
        if(y == 0 && z > 0 && e >= a)goto pp;
        if(z == 0 && y > 0 && f >= b)goto pp;
        if(y % 2 == z % 2)x = min(x, max(y, z));
    }
    if((c - 1) % e == 0 && (b - d) % f == 0){
        y = (c - 1) / e;
        z = (b - d) / f;
        if(y == 0 && z > 0 && e >= a)goto pp;
        if(z == 0 && y > 0 && f >= b)goto pp;
        if(y % 2 == z % 2)x = min(x, max(y, z));
    }
    if((a - c) % e == 0 && (d - 1) % f == 0){
        y = (a - c) / e;
        z = (d - 1) / f;
        if(y == 0 && z > 0 && e >= a)goto pp;
        if(z == 0 && y > 0 && f >= b)goto pp;
        if(y % 2 == z % 2)x = min(x, max(y, z));
    }
    if((a - c) % e == 0 && (b - d) % f == 0){
        y = (a - c) / e;
        z = (b - d) / f;
        if(y == 0 && z > 0 && e >= a)goto pp;
        if(z == 0 && y > 0 && f >= b)goto pp;
        if(y % 2 == z % 2)x = min(x, max(y, z));
    }
    pp:if(x == 99999999)cout << "Poor Inna and pony!" << endl;
    else cout << x << endl;
}
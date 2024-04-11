/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
*********************************************************************************/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3;
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<56)-1
#define FOR(I,A,B) for(int  I = (A); I < (B); ++I )
#define REP(I,N)   FOR( I, 0, N)
#define ALL(A)     ( (A).begin(), (A).end() )
#define set0(ar)   memset( ar, 0, sizeof ar )
#define vsort(v)   sort( ALL(v) )
#define SET(ar,v)  memset( ar, v, sizeof ar )
#define setinf(a)  SET(a,126)


template <class T> inline T bigmod(T p,T e,T M)//p^e%M
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (LL)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
char pp[105];
main()
{
    LL a,b=0,c,d,e,f,g,h,x,y,z;
    cin>>pp;
    b=strlen(pp);
    reverse(pp,pp+b);
    a=1;
    c=bigmod(2ll,b-1,mod);
    d=0;
    REP(i,b)
    {
        e=bigmod(2ll,(LL)i,mod);
        if(pp[i]=='0')continue;
        d=(d+e*c)%mod;
    }
    cout<<d<<endl;

}
/*


*/
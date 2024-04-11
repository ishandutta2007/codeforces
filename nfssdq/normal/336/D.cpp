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
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M){
    LL md=M;
    if( e==0 )return 1;
    if( e%2==0 ){
        LL t = bigmod( p, e/2, M );
        return (T)( ( t*t ) % md );
    }
    LL bm = bigmod( p, e-1, M );
    bm = ( bm * (LL)p )%md;
    return (T)bm;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[ 300001 ];

LL get( LL a, LL b, LL c ){
    if( a+b ==2 ){
        if( a==2 )return c == 1 ? 1 : 0;
        if( b==2 )return c == 0 ? 1 : 0;
        return c == 0 ? 2 : 0;
    }
    LL ret = 0;
    if( c == 0 ){
        if( a > 0 ){
            ret = get( a-1, b, 1 );
        }
        if( b > 0 ){
            LL v = ( ar[ a+b-1 ] * modinverse( ar[ a ], mod ) ) % mod;
            v = ( v * modinverse( ar[ b-1 ], mod ) ) % mod;
            ret = ( ret + v ) % mod;
        }

    }
    else {
        if( a > 0 ){
            ret = get( a-1, b, 0 );
        }
    }
    return ret;
}

main(){

    LL a,b=1,c=1,d=1,e,f,g,h,x,y,z;
    cin >> a >> b >> c;
    ar[ 0 ] = 1;
    for( int i = 1; i <= 300000; i++ )ar[ i ] = ( (LL)i * ar[ i-1 ] )% mod;
    LL res = get( a, b, c );
    if( a+b == 1 ){
        res = 0;
        if( a == 1 && c == 0 )res = 1;
        if( b == 1 && c == 1 )res = 1;
    }
    cout << res << endl;
}
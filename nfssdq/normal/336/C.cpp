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

LL ar[ 100001 ];
LL on[ 100001 ];
main(){

    LL a,b=1,c=1,d=1,e,f,g,h,x,y,z;
    cin >> a ;
    REP( i, a ){
        cin >> ar[ i ];
    }
    c = 0;
    for( int i=0; i < 31; i++ ){
        b = 1ll << i;
        b--;
        REP( j, a ){
            if( ( ar[ j ] & 1ll<<i ) == 0 )continue;
            b &= ar[ j ];
        }
        if( b == 0 ) c = i;
    }
    set0( on );
    b = 1ll << c;
    b--;
    d = 0;
    REP( i, a ){
        if( ( ar[ i ] & 1ll<<c ) == 0 )continue;
        on[ i ] = 1;
        d++;
    }
    cout << d << endl;
    REP( i, a )if( on[ i ]==1 )cout << ar[ i ] << " ";

}
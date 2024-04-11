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
#define INF        INT_MAX/3;
#define mod        1000000007
#define PI         2.0*acos(0.0)
#define linf       (1ll<<56)-1
#define FOR(I,A,B) for(int  I = (A); I < (B); ++I )
#define REP(I,N)   FOR( I, 0, N)
#define ALL(A)     ( (A).begin(), (A).end() )
#define set0(ar)   memset( ar, 0, sizeof ar )
#define vsort(v)   sort( ALL(v) )
#define SET(ar,v)  memset( ar, v, sizeof ar )
#define setinf(a)  SET(a,126)


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (LL)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

char p1[101],p2[101];
LL mark[101],ar[101];

main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    cin>>p1>>p2;
    c=strlen(p1);
    d=strlen(p2);
    e=0;
    x=0;
    y=0;
    z=0;
    int fl=0;
    while(1)
    {
        if(e>a)break;
        if(x==0)e++;
        if(p1[x]==p2[y])
        {
            fl=1;
            if(y==0)
            {
                z++;
                if(mark[x]!=0)break;
                mark[x]=e;
                ar[x]=z;
            }
            x=(x+1)%c;
            y=(y+1)%d;
        }
        else x=(x+1)%c;
        if(x==0 && fl==0)
        {
            e=a+5;
            break;
        }
    }
    if(e>a)
    {
       d=0;
       if(z==b+1)d=1;
       cout<<d<<endl;
       return 0;
    }
    int cnt=ar[x]-1;
    f=e-mark[x];
    g=a-mark[x];
    h=(g/f)*(z-ar[x]);
    e=g%f;
    cnt+=h;
    while(e>=0)
    {
        if(p1[x]==p2[y])
        {
            if(y==d-1)cnt++;
            y=(y+1)%d;
        }
        if(x==c-1)e--;
        x=(x+1)%c;
    }
    cout<<cnt/b<<endl;;
}
/*
6557487 3
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaa
*/
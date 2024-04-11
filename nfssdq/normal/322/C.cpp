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

char ar[101];
int nxt[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
map<char,int>mm;
int a,b;
pair<int,int> go(int c,int d)
{
    int e=strlen(ar);
    REP(i,e)
    {
        c+=nxt[mm[ar[i]]][0],d+=nxt[mm[ar[i]]][1];
        if(c==a && d==b){cout<<"Yes";return mp(-2000000000,-2000000000);}
    }
    return mp(c,d);
}
main()
{
    int c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    cin>>ar;
    c=0;
    d=0;
    e=strlen(ar);
    mm['U']=0;
    mm['D']=1;
    mm['L']=2;
    mm['R']=3;
    if(a==0 && b==0){cout<<"Yes";return 0;}
    pair<int,int>p1=go(0,0);
    if(p1.xx==-2000000000)return 0;
    pair<int,int>p2=p1;
    if(abs(a)<=500 && abs(b)<=500)
    {
        REP(i,2000)
        {
            p2=go(p2.xx,p2.yy);
            if(p2.xx==-2000000000)return 0;

        }
        cout<<"No";return 0;
    }
    else
    {

        REP(i,2000)
        {
            p2=go(p2.xx,p2.yy);
            if(p2.xx==-200000000)return 0;
        }
        if(p1.xx==0 && p1.yy==0){cout<<"No";return 0;}
        if(p1.xx==0)e=b/p1.yy;
        else e=a/p1.xx;
        if(e<0){cout<<"No";return 0;}
        e=max(0,e-200);
        p1.yy*=e;
        p1.xx*=e;
        REP(i,2000)
        {
            p1=go(p1.xx,p1.yy);
            if(p1.xx==-2000000000)return 0;
        }
        cout<<"No";return 0;
    }

}
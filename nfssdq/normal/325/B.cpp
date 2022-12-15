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



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL calc(LL c,LL v,LL m)
{
    LL p=v/c;
    if(p<m)return 1;
    p=m*c;
    LL r=m*(m-1)/2ll;
    if(v-p==r)return 2;
    if(v-p<r)return 1;
    return 0;
}
LL bs(LL c,LL v)
{
    LL s=0,e=2000000100ll,m=(s+e)/2;
    while(s<m)
    {
        LL d=calc(c,v,m);
        if(d==2 && m%2==1)return m*(c+1);
        if(d>=1)e=m;
        else s=m+1;
        m=(s+e)/2;
    }
    LL d=calc(c,v,m);
    if(d==2 && m%2==1)return m*(c+1);
    m++;
    d=calc(c,v,m);
    if(d==2 && m%2==1)return m*(c+1);
    return 0;
}
set<LL>ss,s1;
main()
{
    LL a,b=0,c,d,e,f,g,h,x,y,z;
//    REP(j,1000)
//    {
//        ss.clear();
//        a=j+1;
//    FOR(i,1,1001)
//    {
//        d=0;
//        e=i;
//        while(e%2==0 && e>1)
//        {
//            d+=e/2;
//            e/=2;
//        }
//        d+=e*(e-1)/2;
//        if(d==a)cout<<i<<endl;
//    }
//    cout<<"000000000000"<<endl;
cin>>a;
    c=0;
    e=(1+8*a);
    d=sqrt(e);
    if(d*d==e && (d+1)%2==0 && ((d+1)/2)%2!=0)
    {
        ss.insert((d+1)/2ll);
        b++;
    }
    REP(i,62)
    {
        f=1ll<<i;
        if(a-c<f)break;
        c+=f;
        d=bs(c,a);
        if(d>0)
        {
            ss.insert(d);
            b++;
        }
    }
    if(b==0)cout<<-1<<endl;
    if(b==0)return 0;
    for(set<LL>::iterator it=ss.begin();it!=ss.end();it++)
    {
        cout<<*it<<endl;
    }

}
//999999998765257141
//2828427122
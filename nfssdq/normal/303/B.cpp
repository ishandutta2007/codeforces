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

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)
#define PI 3.141592653589793238462643383279502884197169399375



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    LL n,m;
    cin>>n>>m>>c>>d>>a>>b;
    e=gcd(a,b);
    a/=e;
    b/=e;
    LL lo=1,hi=n,mid=(lo+hi)/2;
    while(lo<mid)
    {
        e=mid*a;
        f=mid*b;
        if(e<=n && f<=m)lo=mid;
        else hi=mid-1;
        mid=(hi+lo)/2;
    }
    e=mid*a+a;
    f=mid*b+b;
    if(e<=n && f<=m)mid++;
    e=mid*a;
    f=mid*b;
    LL x1,y1,x2,y2;
    g=c;
    h=n-c;
    LL p1,p2;
    if(e%2==1)
    {
        p1=(e+1)/2;
        p2=(e-p1);
    }
    else p1=p2=e/2;
    if(g>=p1 && h>=p2)
    {
        x1=c-p1;
        x2=c+p2;
    }
    else if(g<p1)
    {
        int ff=(p1-g);
        p2+=ff;
        p1=g;
        x1=c-p1;
        x2=c+p2;
    }
    else if(h<p2)
    {
        int ff=(p2-h);
        p1+=ff;
        p2=h;
        x1=c-p1;
        x2=c+p2;
    }
    g=d;
    h=m-d;
    if(f%2==1)
    {
        p1=(f+1)/2;
        p2=(f-p1);
    }
    else p1=p2=f/2;
    if(g>=p1 && h>=p2)
    {
        y1=d-p1;
        y2=d+p2;
    }
    else if(g<p1)
    {
        int ff=(p1-g);
        p2+=ff;
        p1=g;
        y1=d-p1;
        y2=d+p2;
    }
    else if(h<p2)
    {
        int ff=(p2-h);
        p1+=ff;
        p2=h;
        y1=d-p1;
        y2=d+p2;
    }
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

}
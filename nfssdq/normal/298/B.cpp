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
#define PI 2.0*acos(0.0)
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

//char pp[1001];
//
//main()
//{
//    int a,b,c,d,e,f,g,h,x,y,z;
//    cin>>a;
//    cin>>pp;
//    b=0;
//    c=0;
//    for(x=0;x<a;x++)
//    {
//        if(b==0 && pp[x]!='.' && (x==a-1 || pp[x+1]=='.'))b=x+1;
//        if(c==0 && pp[x]=='L' && ( pp[x-1]!='L' ))c=x+1;
//    }
//    if(pp[c-1]=='L')c--;
//    cout<<b<<" "<<c<<endl;
//}

char pp[100001];
map<char,int>mm;
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b>>c>>d>>e;
    cin>>pp;
    mm['E']=0;
    mm['S']=1;
    mm['W']=2;
    mm['N']=3;
    d=d-b;
    e=e-c;
    f=0;
    g=0;
    if(d>0)f=0;
    else f=2;
    if(e>0)g=3;
    else g=1;
    h=-1;
    d=abs(d);
    e=abs(e);
    for(x=0;x<a;x++)
    {
        if(d>0 && mm[pp[x]]==f)d--;
        if(e>0 && mm[pp[x]]==g)e--;
        if(d==0 && e==0){h=x+1;break;}
    }
    cout<<h<<endl;
}
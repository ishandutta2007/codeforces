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
    if(e%2==0){T t=bigmod(p,e/2,M);return (t*t)%M;}
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

char pp[1000001];

main()
{

    int a,b,c,d,e,f,g,h,x,y,z;
    gets(pp);
    a=strlen(pp);
    b=0;
    c=0;
    char t='"';
    for(x=0;x<a;x++)
    {
        if(b==0 && pp[x]==t)
        {
            c=x;
            b=2;
        }
        else if(b==2 && pp[x]==t)
        {
            cout<<'<';
            for(y=c+1;y<x;y++)cout<<pp[y];
            cout<<'>'<<endl;
            b=0;
        }
        else if(b==0 && pp[x]!=' ')
        {
            c=x;
            b=1;
        }
        else if(b==1 && (pp[x]==' ' || pp[x]==t))
        {
            cout<<'<';
            for(y=c;y<x;y++)cout<<pp[y];
            cout<<'>'<<endl;
            b=0;
            if(pp[x]==t)
            {
                c=x;
                b=2;
            }
        }
    }
    if(b==1 && x==a)
    {
        cout<<'<';
        for(y=c;y<x;y++)cout<<pp[y];
        cout<<'>'<<endl;
        b=0;
    }
}
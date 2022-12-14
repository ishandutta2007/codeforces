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
#define vsort(v) sort(v.begin(),v.end())


main()
{
    long double a,b,c,d=0,e,f,g,h,x,y,z;
    cin>>a>>b>>c>>d>>e>>f;
    e=c/(-1.0*e);
    g=a/2.0;
    h=g+e*d;
    if(h<0.0)
    {
        while(h<-2.0*a)h+=2.0*a;
        //cout<<h<<endl;
        if(h<-a)z=2.0*a+h;
        else z=h*-1.0;
    }
    else
    {
        //cout<<h<<" "<<e<<endl;
        while(h>2.0*a)h-=2.0*a;
        if(h>a)z=2.0*a-h;
        else z=h;
    }
    g=0.0;
    h=g+e*f;
    if(h<0.0)
    {
        while(h<-2.0*b)h+=2*b;
        if(h<-b)y=2.0*b+h;
        else y=h*-1.0;
    }
    else
    {
        while(h>2.0*b)h-=2*b;
        if(h>b)y=2.0*b-h;
        else y=h;
    }
    double p=z,q=y;
    printf("%.12lf %.12lf",p,q);

}
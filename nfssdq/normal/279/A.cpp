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
    int a,b,c=0,d,e,f,g,h,x,y,z;
    scanf("%d %d",&a,&b);
    if(a>=0 && b>=0)
    {
        if(a<=1 && b==0)
        {
            cout<<0<<endl;
            return 0;
        }
        c=max(a,b);
        if(a>=b)cout<<(c-1)*4+1;
        else cout<<(c-1)*4+2;
    }
    else if(a<0 && b>=0)
    {
        a=abs(a);
        c=max(a,b);
        if(a<=b)cout<<(c-1)*4+2;
        else cout<<(c-1)*4+3;
    }
    else if(a<0 && b<0)
    {
        a=abs(a);
        b=abs(b);
        c=max(a,b);
        if(a>=b)cout<<(c-1)*4+3<<endl;
        else cout<<(c)*4<<endl;
    }
    else if(a>=0 && b<0)
    {
        b=abs(b);
        c=max(a-1,b);
        if(a-1<=b)cout<<c*4<<endl;
        else cout<<c*4+1<<endl;
    }
    //main();

}
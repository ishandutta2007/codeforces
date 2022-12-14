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
**********************************************************************************/

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
#define mod 1000000009
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())

using namespace std;
pair<int,int> ar[100001];
int on[100001];
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)
    {
        cin>>ar[x].xx>>ar[x].yy;

    }
    sort(ar,ar+a);
    for(x=1;x<a;x++)
    {
        b=ar[x].xx-ar[x-1].xx;
        c=1;
        for(y=1;y<=b;y++)
        {
            c*=4;
            if(c>=ar[x-1].yy)break;
        }
        b=ceil((double)ar[x-1].yy/(double)c);
        ar[x].yy=max(b,(LL)ar[x].yy);
    }
    c=4;
    b=1;
    while(c<ar[a-1].yy)
    {
        b++;
        c*=4;
    }
    cout<<ar[a-1].xx+b<<endl;
}
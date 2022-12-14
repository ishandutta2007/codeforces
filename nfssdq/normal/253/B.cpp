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

int ar[100001];
int on[5001];
main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)
    {
        cin>>ar[x];
        on[ar[x]]++;
    }
    b=a+1;
    for(x=1;x<=5000;x++)on[x]+=on[x-1];
    for(x=1;x<=5000;x++)
    {
        for(y=x;y<=min(5000,2*x);y++)
        {
            c=on[y]-on[x-1];
            b=min(b,a-c);
        }
    }
    cout<<b<<endl;
}
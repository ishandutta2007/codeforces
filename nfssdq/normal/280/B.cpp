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
int ar[100001];
int tmp[100001];

main()
{
    int a,b,c=0,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)
    {
        cin>>ar[x];
    }
    b=0;
    for(x=0;x<a;x++)
    {
        while(b>0 && tmp[b-1]<ar[x])b--;
        tmp[b++]=ar[x];
        if(x>0)
        {
            if(b>1)c=max(c,tmp[b-1]^tmp[b-2]);
        }
    }
    b=0;
    for(x=a-1;x>=0;x--)
    {
        while(b>0 && tmp[b-1]<ar[x])b--;
        tmp[b++]=ar[x];
        if(x<a-1)
        {
            if(b>1)c=max(c,tmp[b-1]^tmp[b-2]);
        }
    }
    cout<<c<<endl;
}
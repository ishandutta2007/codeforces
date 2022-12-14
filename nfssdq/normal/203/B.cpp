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

int ar[1001][1001];
int aa;
int fb(int a,int b)
{
    for(int x=a;x<=a+2;x++)
    {
        for(int y=b;y<=b+2;y++)
        {
            if(x>aa || x<1 || y>aa || y<1 || ar[x][y]==0)return 0;
        }
    }
    return 1;
}
main()
{
    int a,b,c,d=0,e,f,g,h,x,y,z;
    cin>>aa>>b;
    for(x=0;x<b;x++)
    {
        cin>>c>>d;
        ar[c][d]=1;
        e=fb(c,d)+fb(c-1,d)+fb(c-2,d)+fb(c,d-1)+fb(c-1,d-1)+fb(c-2,d-1)+fb(c,d-2)+fb(c-1,d-2)+fb(c-2,d-2);
        if(e>0)
        {
            cout<<x+1;
            return 0;
        }
    }
    cout<<-1;
}
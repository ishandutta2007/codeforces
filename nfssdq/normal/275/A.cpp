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
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
int on[3][3],ar[3][3];
int nxt[5][2]={{-1,0},{0,-1},{1,0},{0,1},{0.0}};
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            cin>>ar[x][y];
            on[x][y]=1;
        }
    }
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            for(z=0;z<5;z++)
            {
                a=x+nxt[z][0];
                b=y+nxt[z][1];
                c=ar[x][y]%2;
                if(a>=0 && a<3 && b>=0 && b<3)on[a][b]^=c;
            }
        }
    }
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)cout<<on[x][y];
        cout<<endl;
    }
}
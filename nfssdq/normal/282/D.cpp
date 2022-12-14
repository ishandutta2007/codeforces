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


int dp[301][301][301],ar[3];
int on[301][301][301];
int go1(int a)
{
    int b,c,d,x,y,z;
    return a;
}
int go2(int a,int b)
{
    int c,d,x,y,z;
    if(on[0][a][b]==1)return dp[0][a][b];
    on[0][a][b]=1;
    for(x=1;x<=a;x++)
    {
        c=go2(a-x,b);
        if(c==0)return dp[0][a][b]=1;
    }
    for(x=1;x<=b;x++)
    {
        c=go2(a,b-x);
        if(c==0)return dp[0][a][b]=1;
    }
    for(x=1;x<=min(a,b);x++)
    {
        c=go2(a-x,b-x);
        if(c==0)return dp[0][a][b]=1;
    }
    return dp[0][a][b]=0;
}
int go3(int a,int b,int c)
{
    int d,x,y,z;
    return a^b^c;
}
main()
{
    int a,b,c,d=0,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)cin>>ar[x];

    if(a==1)
    {
        b=go1(ar[0]);
    }
    else if(a==2)b=go2(ar[0],ar[1]);
    else b=go3(ar[0],ar[1],ar[2]);
    if(b>0)cout<<"BitLGM";
    else cout<<"BitAryo";

}
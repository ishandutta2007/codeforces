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
pair<double,pair<int,int> >pp[100001];
double dp[100001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)
    {
        cin>>pp[x].yy.yy>>pp[x].yy.xx;
        pp[x].xx=(double)(pp[x].yy.yy*pp[x].yy.xx)/(100.0-pp[x].yy.xx);
    }
    sort(pp,pp+a);
    reverse(pp,pp+a);
    double ret=0.0;
    for(x=1;x<=a;x++)
    {
        ret+=(double)pp[x-1].yy.yy+(1.0-(double)pp[x-1].yy.xx/100.0)*dp[x-1];
        dp[x]=dp[x-1]+((double)pp[x-1].yy.xx/100.0)*(double)pp[x-1].yy.yy;
        //cout<<dp[x]<<" "<<pp[x-1].yy.xx<<" "<<pp[x-1].yy.yy<<endl;
    }
    printf("%.10lf\n",ret);
}
/*75
162.5
160
*/
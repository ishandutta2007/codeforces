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
int vis[200001][2];
LL ar[200001];
LL sum[200001][2];
int aa;
LL dfs(int p,int v)
{
    if(p<=0 || p>aa)return 0ll;
    if(p==1)return -1ll;
    if(vis[p][v]!=0)return sum[p][v];
    vis[p][v]=1;
    sum[p][v]=-1;
    if(v==0)
    {
        LL r=dfs(p-ar[p],1-v);
        if(r==-1)return sum[p][v]=-1;
        else return sum[p][v]=ar[p]+r;
    }
    else
    {
        LL r=dfs(p+ar[p],1-v);
        if(r==-1)return sum[p][v]=-1;
        else return sum[p][v]=ar[p]+r;
    }
}
main()
{
    LL a,b,c,d=0,e,f,g,h,x,y,z;
    cin>>aa;
    for(x=2;x<=aa;x++)
    {
        cin>>ar[x];
    }
    for(x=2;x<=aa;x++)
    {
        dfs(x,0);
        dfs(x,1);
    }
    for(x=1;x<aa;x++)
    {
        if(sum[1+x][0]==-1)cout<<-1<<endl;
        else cout<<x+sum[1+x][0]<<endl;
    }
}
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
#include <string>
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
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){T t=bigmod(p,e/2,M);return (t*t)%M;}
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
int k;
int ar[10];
int cnt=0;
int vis[10],val[10];
int dfs2(int v)
{
    if(v==1)return val[v]=1;
    if(vis[v]==1)return val[v];
    vis[v]=1;
    val[v]=dfs2(ar[v]);
}
void dfs(int l)
{
    if(l>k)
    {
        int x,f=0;
        set0(vis);set0(val);
        for(x=2;x<=k;x++)dfs2(x);
        dfs2(ar[1]);
        for(x=1;x<=k;x++)if(val[x]==0)f++;
        if(f==0)cnt++;
        return;
    }
    for(int x=1;x<=k;x++)
    {
        ar[l]=x;
        dfs(l+1);
    }
}
LL arr[10]={1ll,2ll,9ll,64ll,625ll,7776ll,117649ll,2097152ll};
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;

    cin>>a>>b;
    a=a-b;
    LL ret=1;
    for(x=1;x<=a;x++)ret=(ret*a)%mod;
    ret=(ret*arr[b-1])%mod;
    cout<<ret<<endl;
}
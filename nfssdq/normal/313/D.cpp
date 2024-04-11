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

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007
#define PI         2.0*acos(0.0)
#define linf       (1ll<<56)-1
#define FOR(I,A,B) for( I = (A); I < (B); ++I )
#define REP(I,N)   FOR( I, 0, N)
#define ALL(A)     ( (A).begin(), (A).end() )
#define set0(ar)   memset( ar, 0, sizeof ar )
#define vsort(v)   sort( ALL(v) )
#define SET(ar,v)  memset( ar, v, sizeof ar )
#define setinf(a)  SET(a,126)


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (LL)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL dp[301][301];
LL pp[301];
LL pr[301][301];
LL rr=0;
LL go(int n,int k)
{
    if(k<=0)return 0;
    if(dp[n][k]!=-1)return dp[n][k];
    dp[n][k]=linf;
    if(n<k)return dp[n][k];
    for(int i=n;i>=1;i--)
    {
        if(pr[i][n]==rr)break;
        int a=n-i+1;
        dp[n][k]=min(dp[n][k],go(i-1,k-a)+pr[i][n]);
    }
    return dp[n][k]=min(dp[n][k],go(n-1,k));
}
pair<pair<int,int> ,int>ps[100001];
main()
{
    LL a=0,b,c,d,e,f,g,h,i,j,k,l,x,y,z;
    cin>>a>>b>>c;
    for(x=0;x<b;x++)cin>>ps[x].xx.xx>>ps[x].xx.yy>>ps[x].yy;
    memset(dp,-1,sizeof dp);
    setinf(pr);
    rr=pr[0][0];
    for(x=1;x<=a;x++)
    {
        for(y=0;y<b;y++)
        {
            if(ps[y].xx.xx<=x)pr[x][ps[y].xx.yy]=min(pr[x][ps[y].xx.yy],(LL)ps[y].yy);
        }
        for(y=a-1;y>=x;y--)pr[x][y]=min(pr[x][y],pr[x][y+1]);
    }
    go(a,c);
    if(dp[a][c]==linf)dp[a][c]=-1;
    cout<<dp[a][c]<<endl;
}
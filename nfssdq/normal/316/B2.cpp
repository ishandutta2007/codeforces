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
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
LL ar[1001];
LL vis[1001],len[1001];
LL dp[1001][1001],vv[1001];
LL bb,b,c,d;
LL val[1001];
LL dfs(int a)
{
    if(vis[ar[a]])return len[a];
    vis[ar[a]]=1;
    if(ar[a]==0)return len[a];
    LL c=dfs(ar[a]);
    if(a==b)d=c+1;
    len[a]=c+1;
    val[a]=c+1;
    val[ar[a]]=0;
    if(ar[a]==bb)bb=a;
    return len[a];
}
LL tm[1001];
main()
{
    LL a,e,f,g,h,x,y,z;
    cin>>a>>b;
    FOR(i,1,a+1)cin>>ar[i];
    FOR(i,1,a+1)len[i]=1,val[i]=1;
    d=1;
    bb=b;
    FOR(i,1,a+1)
    {
        if(ar[i]==0)continue;
        if(vis[i]==1)continue;
        len[i]=dfs(i);
    }
    c=1;
    FOR(i,1,a+1)if(val[i]>0 && i!=bb)vv[c++]=val[i];
    cout<<d<<endl;
    REP(i,1001)dp[0][i]=1;
    FOR(i,1,a+1)
    {
        f=0;
        FOR(j,1,c){
            dp[i][j]=dp[i][j-1];
            if(vv[j]<=i)dp[i][j]=max(dp[i][j],dp[i-vv[j]][j-1]);
            f=max(f,dp[i][j]);
        }
        if(f==1)cout<<i+d<<endl;
    }
}
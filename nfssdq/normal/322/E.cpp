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
#define inf        INT_MAX/3;
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<56)-1
#define FOR(I,A,B) for(int  I = (A); I < (B); ++I )
#define REP(I,N)   FOR( I, 0, N)
#define ALL(A)     ( (A).begin(), (A).end() )
#define set0(ar)   memset( ar, 0, sizeof ar )
#define vsort(v)   sort( ALL(v) )
#define SET(ar,v)  memset( ar, v, sizeof ar )
#define setinf(a)  SET(a,126)


template <class T> inline T bigmod(T p,T e,T M)//p^e%M
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (LL)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
vector<int>vc[100001];
char ar[100001];
int dfs(int ii,int p)
{
    vector<int>tmp;
    REP(i,vc[ii].size())
    {
        if(vc[ii][i]!=p)tmp.push_back(dfs(vc[ii][i],ii));
    }
    int d=-1,ret=0;
    REP(i,26)
    {
        int c=0;
        REP(j,tmp.size())
        {
            if(tmp[j]==-1)return -1;
            c+=(tmp[j] & 1<<i)>0?1:0;
        }
        if(c>1)break;
        if(c==0)d=i;
    }
    if(d==-1)return d;
    REP(i,d)
    {
        int c=0;
        REP(j,tmp.size())
        {
            c+=(tmp[j] & 1<<i)>0?1:0;
        }
        if(c==1)ret|=1<<i;
    }

    ret|=1<<d;
    ar[ii]='A'+d;
    return ret;

}

main()
{
    int a,b,c,d=0,e,f,g,h,x,y,z;
    cin>>a;
    REP(i,a-1)
    {
        cin>>b>>c;
        vc[c].push_back(b);
        vc[b].push_back(c);
    }
    b=dfs(1,0);
    if(b==-1)cout<<"Impossible";
    else
    {
        REP(i,a)cout<<ar[i+1]<<" ";
    }
}
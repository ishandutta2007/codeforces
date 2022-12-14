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
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M){
    if(e==0)return 1;
    if(e%2==0){ LL t = bigmod(p,e/2,M) ; return (T)((t*t)%M); }
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

char ar[1011][1011];
int dis[1011][1011];
int nxt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,pair<int,int> > >Q;
void flood(int ii,int jj,int r,int c,int v)
{
    Q.push(mp(0,mp(ii,jj)));
    while(!Q.empty())
    {
        pair<int,pair<int,int> >pp=Q.front();
        Q.pop();
        if(dis[pp.yy.xx][pp.yy.yy]<=pp.xx)continue;
        dis[pp.yy.xx][pp.yy.yy]=pp.xx;
        REP(i,4)
        {
            int a=pp.yy.xx+nxt[i][0];
            int b=pp.yy.yy+nxt[i][1];
            if(a>=0 && a<r && b>=0 && b<c && ar[a][b]!='T')Q.push(mp(pp.xx+1,mp(a,b)));
        }
    }

}
main()
{
    LL a,b=0,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    REP(i,a)
    {
        cin>>ar[i];
        REP(j,b)
        {
            if(ar[i][j]=='E')c=i,d=j;
            if(ar[i][j]=='S')e=i,f=j;
        }
    }
    setinf(dis);
    flood(c,d,a,b,0);
    c=dis[e][f];
    d=0;
    REP(i,a)
    {
        REP(j,b)
        {
            if(ar[i][j]!='T' && dis[i][j]<=c && ar[i][j]!='S' && ar[i][j]!='E')d+=ar[i][j]-'0';
        }
    }
    cout<<d<<endl;
}
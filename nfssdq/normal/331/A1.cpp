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



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[400001];
LL sum[400001];
map<LL,LL>mm;
vector<LL>vc[400001];
vector<LL>vp;
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    b=0;
    FOR(i,1,a+1)
    {
        cin>>ar[i];
        if(mm[ar[i]]==0)
        {
            vp.push_back(ar[i]);
            b++;
            mm[ar[i]]=b;
        }
        vc[mm[ar[i]]].push_back(i);
        d=ar[i];
        if(d<0)d=0;
        sum[i]=sum[i-1]+d;
    }
    c=d=h=-2100000000ll;
    REP(i,vp.size())
    {
        b=mm[vp[i]];
        if(vc[b].size()<2)continue;
        e=vc[b][0];
        f=vc[b][vc[b].size()-1];
        g=sum[f]-sum[e-1];
        if(vp[i]<0)g+=vp[i]*2ll;
        if(g>d)
        {
            d=g;
            c=b;
        }
    }
    e=vc[c][0],f=vc[c][vc[c].size()-1];
        h=a-f+e-1;
    FOR(i,e+1,f)if(ar[i]<0)h++;
    cout<<d<<" "<<h<<endl;
    FOR(i,1,e)cout<<i<<" ";
    FOR(i,e+1,f)if(ar[i]<0)cout<<i<<" ";
    FOR(i,f+1,a+1)cout<<i<<" ";
}
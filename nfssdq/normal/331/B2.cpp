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
int pr[400001];
int ar[400001];
int bit[400001];
int nxt[400001];
map<LL,LL>mm;
set<LL>st;
void insert(int ii,int v)
{
    while(ii<=400000)
    {
        bit[ii]+=v;
        ii+=ii & -ii;
    }
}
int query(int ii)
{
    int ret=0;
    while(ii>0)
    {
        ret+=bit[ii];
        ii-=ii & -ii;
    }
    return ret;
}
main()
{
    LL a,b=0,c,d,e,f,g,h,x,y,z;
    cin>>a;
    FOR(i,1,a+1)
    {
        cin>>ar[i];
        mm[ar[i]]=i;
    }
    insert(1,1);
    FOR(i,2,a+1)
    {
        if(mm[i]>mm[i-1])pr[i]=i-1,nxt[i-1]=i;
        else insert(i,1);
    }
    cin>>b;
    REP(i,b)
    {
//        FOR(i,1,a+1)cout<<query(i)-query(i-1)<<" ";
        cin>>c>>d>>e;
        if(c==1)
        {
            if(d>e)swap(d,e);
            cout<<query(e)-query(d)+1<<endl;
        }
        else
        {
            mm[ar[d]]=e;
            mm[ar[e]]=d;
            if(d>e)swap(d,e);
//            cout<<ar[d]<<" "<<nxt[ar[d]]<<" "<<pr[ar[d]]<<" "<<mm[ar[d]]<<endl;
//            cout<<ar[e]<<" "<<nxt[ar[e]]<<" "<<pr[ar[e]]<<" "<<mm[ar[e]]<<endl;

            if(nxt[ar[d]]!=0 && mm[nxt[ar[d]]]<mm[ar[d]])
            {
                insert(nxt[ar[d]],1);
                pr[nxt[ar[d]]]=0;
                nxt[ar[d]]=0;
            }
            if(pr[ar[d]]==0 && ar[d]!=1 && mm[ar[d]-1]<mm[ar[d]])
            {
                insert(ar[d],-1);
                pr[ar[d]]=ar[d]-1;
                nxt[ar[d]-1]=ar[d];
            }
            if(pr[ar[e]]!=0 && mm[pr[ar[e]]]>mm[ar[e]])
            {
                insert(ar[e],1);
                nxt[pr[ar[e]]]=0;
                pr[ar[e]]=0;
            }
            if(nxt[ar[e]]==0 && ar[e]!=a && mm[ar[e]+1]>mm[ar[e]])
            {
                insert(ar[e]+1,-1);
                nxt[ar[e]]=ar[e]+1;
                pr[ar[e]+1]=ar[e];
            }
            swap(ar[d],ar[e]);
        }
    }
}
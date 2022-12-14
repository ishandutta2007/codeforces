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
#define mod        1000000000ll
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

char pp[2001],ps[2001];
LL dp[2005][2005],cnt[2005][2005];
LL sum[2005];
set<string>ss;
main()
{
    LL a,b,c,d,e,f,x,y,z;
    cin>>pp>>a;
    LL h=0;
    REP(ccc,a)
    {
        cin>>ps>>b>>c;
        d=strlen(ps);
        e=strlen(pp);
        set0(dp);
        for(int i=e-1;i>=0;i--)
        {
            set0(sum);
            for(int j=d-1;j>=0;j--)
            {
                if(pp[i]==ps[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                    sum[dp[i][j]]++;
                }
            }
            sum[e-i+1]=0;
            for(int j=e-i;j>=1;j--)sum[j]+=sum[j+1];
            for(int j=e-i;j>=1;j--)if(sum[j]>=b && sum[j]<=c)cnt[i][j]++;
        }
//        REP(i,e)
//    {
//        REP(j,e-i+1)cout<<cnt[i][j]<<" ";
//        cout<<endl;
//    }
    }
    d=strlen(pp);
    REP(i,d)
    {
        string s="";
        FOR(j,1,d-i+1)
        {
            s+=pp[i+j-1];
            if(cnt[i][j]==a)ss.insert(s);
        }
    }
    h=ss.size();
    cout<<h<<endl;

}
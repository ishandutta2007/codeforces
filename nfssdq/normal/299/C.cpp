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
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

char p1[2000001],p2[2000001];
pair<int,int>pp1[2000001],pp2[2000001];
set<int>st;
int ps1[1000001],ps2[1000001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    a*=2;
    cin>>p1>>p2;
    for(x=0;x<a;x++)
    {
        pp1[x].xx=p1[x]-'0';
        pp1[x].yy=p2[x]-'0';
        pp2[x].xx=p2[x]-'0';
        pp2[x].yy=p1[x]-'0';
    }
    sort(pp1,pp1+a);
    sort(pp2,pp2+a);
    b=c=d=e=0;
    for(x=0;x<a;x++)
    {
        if(pp1[x].xx==0 && pp1[x].yy==0)b++;
        else if(pp1[x].xx==1 && pp1[x].yy==0)c++;
        else if(pp1[x].xx==0 && pp1[x].yy==1)d++;
        else e++;
    }
    f=0;
    e=e%2;
    if(c+e>d)f=1;
    else if(c+e<d-1)f=-1;
    if(f==0)cout<<"Draw";
    else if(f==1)cout<<"First";
    else cout<<"Second";
}
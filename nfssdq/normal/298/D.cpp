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

//char pp[1001];
//
//main()
//{
//    int a,b,c,d,e,f,g,h,x,y,z;
//    cin>>a;
//    cin>>pp;
//    b=0;
//    c=0;
//    for(x=1;x<=a;x++)
//    {
//        if(b==0 && pp[x-1]!='.' && ( pp[x]=='.'))b=x;
//        if(c==0 && pp[x-1]=='L' && ( pp[x-2]!='L' ))c=x;
//    }
//    if(pp[c-1]=='L' && pp[c-2]=='.')c--;
//    cout<<b<<" "<<c<<endl;
//}

int ar[500001];
map<int,int>mm;
int ar1[100001],ar2[100001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b>>c;
    for(x=0;x<a;x++)
    {
        cin>>ar1[x];
        mm[ar1[x]]=1;
    }
    for(x=0;x<b;x++)
    {
        cin>>ar2[x];
        mm[ar2[x]]=1;
    }
    d=0;
    for(map<int,int>::iterator it=mm.begin();it!=mm.end();it++)
    {
        d++;
        (*it).yy=d;
    }
    c=d;
    for(x=0;x<a;x++)ar1[x]=mm[ar1[x]];
    for(x=0;x<b;x++)ar2[x]=mm[ar2[x]];
    for(x=0;x<a;x++)
    {
        ar[ar1[x]]++;
    }
    for(x=0;x<b;x++)
    {
        ar[ar2[x]]--;
    }
    d=0;
    e=0;
    for(x=1;x<=c;x++)
    {
        if(ar[x]>0)d+=ar[x];
        else e+=ar[x]*-1;
    }
    f=0;
    g=0;
    h=0;
    for(x=0;x<=c;x++)
    {
        if(ar[x]>0)f+=ar[x];
        else g+=ar[x]*-1;
        if(d-f>e-g)h++;
    }
    if(h>0)cout<<"YES";
    else cout<<"NO";
}
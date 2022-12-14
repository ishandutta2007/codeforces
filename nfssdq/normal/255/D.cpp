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
    Everything happens after running this code is solely your responsibilty.     |
                                                                                 |
**********************************************************************************/


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
#define vi vector<int>
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define mdd map<int,int>
#define pii pair<int,int>
#define ULL unsigned long long
#define pll pair<long long,long long>
#define vsort(v) sort(v.begin(),v.end())
LL go(LL x,LL y,LL t)
{
    if(x==0 || y==0)return 0;
    if(x==1 || y==1)return min(t,max(x,y));
    LL res=0;
    if(t>=x+y-1)return x*y;
    LL a=min(x,y);
    LL b=max(x,y);
    if(t<=a)return t*(t+1)/2;
    res+=a*(a+1)/2;
    if(t<=b)return res+(t-a)*a;
    res+=(b-a)*a;
    a--;
    t-=b;
    b=(a-t);
    res+=(a*(a+1))/2-(b*(b+1))/2;
    return res;
}
LL get(LL x,LL y,LL t,LL n)
{
    if(t==0)return 1;
    LL res=0;
    if(t>1)res+=go(n-x,n-y,t-1)+go(n-x,y-1,t-1)+go(x-1,n-y,t-1)+go(x-1,y-1,t-1);
    res+=go(n-x,1,t)+go(n-y,1,t)+go(x-1,1,t)+go(y-1,1,t);
    return res+1;
}
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b>>c>>d;
    e=0;
    f=a*a;
    g=(e+f)/2;
    while(e<f)
    {
        h=get(b,c,g,a);
        if(h<d)e=g+1;
        else f=g;
        g=(e+f)/2;
    }
    if(get(b,c,g,a)<d)g++;
    cout<<g<<endl;
}
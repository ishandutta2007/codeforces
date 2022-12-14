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
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)
#define PI 3.141592653589793238462643383279502884197169399375


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){T t=bigmod(p,e/2,M);return (t*t)%M;}
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL bit[100001][33];
map<LL,bool>mm;
LL subnet[33];
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    int p,q,r,s;
    for(x=0;x<a;x++)
    {
        scanf("%d.%d.%d.%d",&p,&q,&r,&s);
        c=0;
        c=c*256ll+(LL)p;
        c=c*256ll+(LL)q;
        c=c*256ll+(LL)r;
        c=c*256ll+(LL)s;
        for(y=0;y<32;y++)
        {
            bit[x][y]=c%2;
            c/=2;
        }
        reverse(bit[x],bit[x]+32);
    }
    for(x=0;x<31;x++)subnet[x]=1;
    d=35;
    for(x=30;x>=0;x--)
    {
        mm.clear();
        for(y=0;y<a;y++)
        {
            c=0;
            for(z=0;z<32;z++)
            {
                c=c*2+(bit[y][z]&subnet[z]);
            }
            mm[c]=1;
        }
        if(mm.size()==b)d=x;
        subnet[x]=0;
    }
    if(d==35)cout<<-1<<endl;
    else
    {
        set0(subnet);
        for(x=0;x<=d;x++)subnet[x]=1;
        for(x=0;x<4;x++)
        {
            c=0;
            for(y=x*8;y<x*8+8;y++)
            {
                c=c*2+subnet[y];
            }
            if(x!=0)cout<<'.';
            cout<<c;
        }
        cout<<endl;
    }
}
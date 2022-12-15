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
//#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
int ar[100001],on[100001];
map<LL,int>mp;
map<LL,bool>mb;
main()
{
    int a,b,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    for(x=0;x<a;x++)cin>>ar[x];
    sort(ar,ar+a);
    for(x=0;x<a;x++)
    {
        mp[(LL)ar[x]]+=1;
    }
    g=0;
    for(x=0;x<a;x++)
    {
        if(b==1)break;
        if(mb[ar[x]]==true)continue;
        mb[ar[x]]=true;
        d=mp[ar[x]];
        e=0;
        f=0;
        LL c=ar[x];
        while(1)
        {
            f++;
            c=c*(LL)b;
            if(f%2==0)d+=mp[c];
            else e+=mp[c];
            if(mp[c]==0)break;
            mb[c]=true;
        }
        g+=max(d,e);
    }
    if(b==1)
    {
        g=0;
        mb.clear();
        for(x=0;x<a;x++)
        {
            if(mb[ar[x]]==true)continue;
            mb[ar[x]]=true;
            g++;
        }
    }
    cout<<g<<endl;
}
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
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000009
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())

using namespace std;

LL seg[400001][5][15];
LL val[7][15];
void insert(int idx,int s,int e,int p,LL v)
{
    int x,y;
    if(s==e)
    {
        for(x=2;x<=6;x++)
            for(y=1;y<2*x-1;y++)seg[idx][x-2][y]=val[x][y]*v;
        return;
    }
    int mid=(s+e)/2;
    if(p<=mid)insert(idx*2+1,s,mid,p,v);
    else insert(idx*2+2,mid+1,e,p,v);
    for(x=2;x<=6;x++)
    {
        for(y=1;y<2*x-1;y++)
        {
            seg[idx][x-2][y]=seg[idx*2+1][x-2][y];
            int a=(mid-s+y)%(2*(x-1));
            seg[idx][x-2][y]+=seg[idx*2+2][x-2][a+1];
        }
    }
}
LL query(int idx,int s,int e,int st,int ed,int z,int ss)
{
    if(s==st && e==ed)return seg[idx][z-2][ss];
    int mid=(s+e)/2;
    if(ed<=mid)return query(idx*2+1,s,mid,st,ed,z,ss);
    else if(st>mid)return query(idx*2+2,mid+1,e,st,ed,z,ss);
    int a=(mid-st+ss)%(2*(z-1));
    return query(idx*2+1,s,mid,st,mid,z,ss)+query(idx*2+2,mid+1,e,mid+1,ed,z,a+1);
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    for(x=2;x<=6;x++)
    {
        a=2*(x-1);
        for(y=1;y<2*x-1;y++)
        {
            if(y%a==0)val[x][y]=2;
            else if(y%a<=x)val[x][y]=y%a;
            else val[x][y]=2*x-(y%a);
            //cout<<val[x][y]<<" ";
        }
        //cout<<endl;
    }
    cin>>a;
    for(x=1;x<=a;x++)
    {
        cin>>b;
        insert(0,1,a,x,b);
    }
    cin>>b;
    for(x=0;x<b;x++)
    {
        cin>>c;
        if(c==1)
        {
            cin>>d>>e;
            insert(0,1,a,d,(LL)e);
        }
        else
        {
            cin>>d>>e>>f;
            cout<<query(0,1,a,d,e,f,1)<<endl;
        }
    }
}
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
#define vsort(v) sort(v.begin(),v.end())
int seg[800001];
void insert(int idx,int s,int e,int st,int ed)
{
    if(s==st && e==ed)
    {
        seg[idx]++;
        return ;
    }
    int mid=(s+e)/2;
    if(ed<=mid)insert(idx*2+1,s,mid,st,ed);
    else if(st>mid)insert(idx*2+2,mid+1,e,st,ed);
    else
    {
        insert(idx*2+1,s,mid,st,mid);
        insert(idx*2+2,mid+1,e,mid+1,ed);
    }
}
int query(int idx,int s,int e,int p)
{
    if(s==e)return seg[idx];
    int mid=(s+e)/2;
    if(p<=mid)return seg[idx]+query(idx*2+1,s,mid,p);
    else return seg[idx]+query(idx*2+2,mid+1,e,p);
}
int ar1[200001],ar2[200001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    for(x=0;x<a;x++)cin>>ar1[x];
    for(x=0;x<b;x++)
    {
        cin>>c>>d;
        insert(0,0,a-1,c-1,d-1);
    }
    for(x=0;x<a;x++)ar2[x]=query(0,0,a-1,x);
    sort(ar1,ar1+a);
    sort(ar2,ar2+a);
    LL sum=0;
    for(x=a-1;x>=0;x--)sum+=(LL)ar2[x]*(LL)ar1[x];
    cout<<sum<<endl;
}
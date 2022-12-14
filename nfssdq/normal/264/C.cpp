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
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())

LL ar[100001],br[100001];
LL seg[400001];
LL mv[100001];
int on[100001];
int cnt[100001];
LL mval[100001];
void insert(int idx,int s,int e,int p,LL v)
{
    if(s==e)
    {
        seg[idx]=max(v,seg[idx]);
        return;
    }
    int mid=(s+e)/2;
    if(p<=mid)insert(idx*2+1,s,mid,p,v);
    else insert(idx*2+2,mid+1,e,p,v);
    seg[idx]=max(seg[idx],v);
}
LL query(int idx,int s,int e,int st,int ed)
{
    if(st>ed)return 0ll;
    if(s==st && e==ed)return seg[idx];
    int mid=(s+e)/2;
    if(ed<=mid)return query(idx*2+1,s,mid,st,ed);
    else if(st>mid)return query(idx*2+2,mid+1,e,st,ed);
    else
    {
        return max(query(idx*2+1,s,mid,st,mid),query(idx*2+2,mid+1,e,mid+1,ed));
    }
}
main()
{
    int a,b,e,f,g,h,x,y,z;
    cin>>a>>b;
    for(x=0;x<a;x++)cin>>ar[x];
    for(x=0;x<a;x++)cin>>br[x];
    for(z=0;z<b;z++)
    {
        LL c,d;
        cin>>c>>d;
        LL m1=0,m2=0;
        int v1=0,v2=0;
        LL ret=0;
        //memset(seg,0,sizeof seg);
        memset(mval,0,sizeof mval);
        memset(cnt,0,sizeof cnt);
        for(x=0;x<a;x++)
        {
            LL tmp=0;
            if(cnt[br[x]]!=0)tmp=mval[br[x]]+c*ar[x];
            //tmp=max(tmp,mval[br[x]]+c*ar[x]);
            //LL pr=max(query(0,1,100000,1,br[x]-1),query(0,1,100000,br[x]+1,100000));
            LL pr=0;
            if((v1==0 || v1==br[x]))pr=m2;
            else pr=m1;
            if(cnt[br[x]]!=0)tmp=max(tmp,pr+d*ar[x]);
            else tmp=pr+d*ar[x];
            if(cnt[br[x]]==0)mval[br[x]]=tmp;
            else mval[br[x]]=max(mval[br[x]],tmp);
            cnt[br[x]]++;
            ret=max(ret,tmp);
            //insert(0,1,100000,br[x],tmp);
            if(mval[br[x]]>m1)
            {
                if(v1==br[x])
                {
                    m1=mval[br[x]];
                    continue;
                }
                m2=m1;
                v2=v1;
                m1=mval[br[x]];
                v1=br[x];
            }
            else if(mval[br[x]]>m2)
            {
                if(v1==br[x])continue;
                m2=mval[br[x]];
                v2=br[x];
            }
        }
        cout<<ret<<endl;
    }
}
/*
5 1
100000 100000 100000 100000 100000
1 1 1 1 1
100000 100000
*/
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
vector<int>vc[100001];
int pr[100001];
vector<int>tr[100001];
pair<int,int> pp[100001];
int cnt=0;
int bit[100001];
int oz=0;
void bin(int i,int l)
{
    while(i<=100000)
    {
        bit[i]+=l;
        i+=i & -i;
    }
}
int ret(int i)
{
    int a=0;
    while(i>0)
    {
        a+=bit[i];
        i-=i & -i;
    }
    return a;
}
void dfs(int id)
{
    int a,b,c,d,e,f,g,h,x,y,z;
    for(x=0;x<vc[id].size();x++)
    {
        if(id==1)cnt++;
        if(vc[id][x]==pr[id])continue;
        tr[cnt].push_back(vc[id][x]);
        pr[vc[id][x]]=id;
        pp[vc[id][x]].xx=cnt;
        pp[vc[id][x]].yy=tr[cnt].size()-1;
        dfs(vc[id][x]);
    }
}
vector<int>seg[100001];
void insert(int l,int i,int v)
{
    while(i<=tr[l].size())
    {
        seg[l][i]+=v;
        i+=i & -i;
    }
}
int query(int l,int i)
{
    int a=0;
    while(i>0)
    {
        a+=seg[l][i];
        i-=i & -i;
    }
    return a;
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    for(x=0;x<a-1;x++)
    {
        cin>>c>>d;
        vc[c].push_back(d);
        vc[d].push_back(c);
    }
    dfs(1);
    for(x=1;x<=cnt;x++)
    {
        seg[x].resize(tr[x].size()+1,0);
    }
    for(x=0;x<b;x++)
    {
        scanf("%d",&c);
        if(c==0)
        {
            scanf("%d %d %d",&d,&e,&f);
            if(d!=1)
            {
            g=max(0,pp[d].yy-f);
            h=min((int)tr[pp[d].xx].size()-1,pp[d].yy+f);
            if(pp[d].yy-f<0)
            {
                int r=f-pp[d].yy;
                r--;
                oz+=e;
                if(r>0)bin(r,e);
                //cout<<r<<endl;
                if(r>=0)
                {
                    insert(pp[d].xx,1,e*-1);
                    insert(pp[d].xx,r+1,e);
                }
            }
            insert(pp[d].xx,g+1,e);
            insert(pp[d].xx,h+2,e*-1);
            //cout<<g+1<<" p "<<h+2<<" "<<x<<endl;
            }
            else
            {
                oz+=e;
                bin(f,e);
            }
        }
        else
        {
            scanf("%d",&d);
            if(d!=1)
            {
                e=query(pp[d].xx,pp[d].yy+1);
                f=ret(100000)-ret(pp[d].yy);
                //cout<<e<<" "<<f<<endl;
            }
            else
            {
                e=oz;
                f=0;
            }
            printf("%d\n",e+f);
        }
    }
}
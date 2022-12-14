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

#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
using namespace std;

#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())


vector<int>vv[100001];
int pr[100001];
int p;
int dfs(int id)
{
    int a,b,c,d,e,f,g,h,x,y,z;
    p++;
    pr[p]=id;
    if(vv[id].size()!=4)return -1;
    for(x=0;x<4;x++)
    {
        if(p!=1 && pr[p-1]==vv[id][x])continue;
        a=0;
        for(y=0;y<4;y++)
        {
            if(y==x)continue;
            b=vv[id][y];
            if(vv[b].size()!=4)return -1;
            for(z=0;z<4;z++)if(vv[b][z]==vv[id][x])a++;
        }
        if(a==2)
        {
            if(vv[id][x]==pr[1])return 0;
            return dfs(vv[id][x]);
        }
    }
    return -1;
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a*2;x++)
    {
        cin>>b>>c;
        vv[b].push_back(c);
        vv[c].push_back(b);
    }
    if(a>7)
    {
        p=0;
        b=dfs(1);
        if(b==0 && p==a)
        {
            for(x=1;x<=a;x++)
            {
                if(x!=1)cout<<" ";
                cout<<pr[x];
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
        return 0;
    }
    int r=0;
    for(x=1;x<=a;x++)pr[x]=x;
    do
    {
        b=0;
        for(x=1;x<=a;x++)
        {
            c=x+1;
            if(c==a+1)c=1;
            d=x+2;
            if(d==a+1)d=1;
            if(d==a+2)d=2;
            e=x-1;
            if(e==0)e=a;
            f=x-2;
            if(f==-1)f=a-1;
            if(f==0)f=a;
            if(vv[pr[x]].size()!=4)
            {
                cout<<-1<<endl;
                return 0;
            }
            int on[4]={0,0,0,0};
            for(y=0;y<4;y++)
            {
                if(vv[pr[x]][y]==pr[c])on[0]=1;
                else if(vv[pr[x]][y]==pr[d])on[1]=1;
                else if(vv[pr[x]][y]==pr[e])on[2]=1;
                else if(vv[pr[x]][y]==pr[f])on[3]=1;
            }
            for(y=0;y<4;y++)if(on[y]==0)b++;
        }
        if(b==0)
        {
            for(x=1;x<=a;x++)
            {
                if(x!=1)cout<<" ";
                cout<<pr[x];
            }
            return 0;
        }
    }while(next_permutation(pr+1,pr+1+a));
    cout<<-1<<endl;
}
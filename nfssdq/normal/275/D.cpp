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
vector<int>vc[100001];
LL sum=0;
int pnt[100001],on[100001],ar[100001],cnt[100001];
pair<LL,LL> dfs1(int id)
{
    int a,b=0,c,d,e,f,x,y,z;
    pair<LL,LL>rt,fin;
    fin.xx=fin.yy=0;
    for(x=0;x<vc[id].size();x++)
    {
        if(pnt[id]!=vc[id][x])
        {
            pnt[vc[id][x]]=id;
            rt=dfs1(vc[id][x]);
            fin.xx=max(fin.xx,rt.xx);
            fin.yy=max(fin.yy,rt.yy);
        }
    }

    ar[id]+=fin.xx-fin.yy;
    if(ar[id]<=0)fin.xx+=(LL)(ar[id]*-1);
    else fin.yy+=(LL)ar[id];
    return fin;
}

main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=1;x<a;x++)
    {
        cin>>b>>c;
        vc[b].push_back(c);
        vc[c].push_back(b);
    }
    for(x=1;x<=a;x++)cin>>ar[x];
    pair<LL,LL>pp=dfs1(1);
    cout<<pp.xx+pp.yy<<endl;
}
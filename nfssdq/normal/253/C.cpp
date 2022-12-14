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

int ar[100001];
int gr[101][100001];
int aa;
void bfs(int x1,int y1)
{
    int a,b,c,d,x,y,z;
    pair<int,pair<int,int> >st,ed;
    queue<pair<int,pair<int,int> > >q;
    st.xx=0;st.yy.xx=x1;st.yy.yy=y1;
    q.push(st);
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        if(gr[st.yy.xx][st.yy.yy]<=st.xx)continue;
        //cout<<st.xx<<" "<<st.yy.xx<<" "<<st.yy.yy<<endl;
        gr[st.yy.xx][st.yy.yy]=st.xx;
        if(st.yy.xx>1)
        {
            a=min(st.yy.yy,ar[st.yy.xx-1]+1);
            ed.xx=st.xx+1;
            ed.yy.xx=st.yy.xx-1;
            ed.yy.yy=a;
            q.push(ed);
        }
        if(st.yy.xx<aa)
        {
            a=min(st.yy.yy,ar[st.yy.xx+1]+1);
            ed.xx=st.xx+1;
            ed.yy.xx=st.yy.xx+1;
            ed.yy.yy=a;
            q.push(ed);
        }
        if(st.yy.yy>1)
        {
            ed.xx=st.xx+1;
            ed.yy.xx=st.yy.xx;
            ed.yy.yy=st.yy.yy-1;
            q.push(ed);
        }
        if(st.yy.yy<=ar[st.yy.xx])
        {
            ed.xx=st.xx+1;
            ed.yy.xx=st.yy.xx;
            ed.yy.yy=st.yy.yy+1;
            q.push(ed);
        }
    }
}
main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>aa;
    for(x=1;x<=aa;x++)
    {
        cin>>ar[x];
    }
    b=0;
    cin>>c>>e>>d>>f;
    memset(gr,126,sizeof gr);
    bfs(c,e);
    cout<<gr[d][f]<<endl;
}
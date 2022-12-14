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
int ar[51][51],on[51][51],cst[51][51];
int nxt[5][2]={{-1,0},{0,-1},{1,0},{0,1}};
struct data
{
    int xi,yi,dir,co;
};

int a,b;
int go(int xi,int yi)
{
    int c,d,e,f,g,h,x,y,z;
    data st,ed;
    queue<data>q;
    st.xi=xi;st.yi=yi;st.dir=-1;st.co=0;
    q.push(st);
    memset(on,0,sizeof on);

    while(!q.empty())
    {
        st=q.front();
        q.pop();
        on[st.xi][st.yi]=1;
        for(x=0;x<4;x++)
        {
            c=st.xi+nxt[x][0];
            d=st.yi+nxt[x][1];
            if(c>=0 && c<a && d>=0 && d<b && on[c][d]==0 && ar[c][d]==1)
            {
                e=st.co;
                if(x!=st.dir && st.dir!=-1)e++;
                if(e>1)continue;
                ed.xi=c;ed.yi=d;ed.dir=x;ed.co=e;
                //cout<<c<<" "<<d<<endl;
                q.push(ed);
            }
        }
    }
    for(x=0;x<a;x++)
    {
        for(y=0;y<b;y++)if(on[x][y]==0 && ar[x][y]==1)return 0;
    }
    return 1;
}
main()
{
    int c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    char pp[50];
    for(x=0;x<a;x++)
    {
        cin>>pp;
        for(y=0;y<b;y++)
        {
            if(pp[y]=='W')ar[x][y]=0;
            else ar[x][y]=1;
        }
    }
    c=0;
    for(x=0;x<a;x++)
    {
        for(y=0;y<b;y++)
        {
            if(ar[x][y]==1)
            {
                c=go(x,y);
                if(c==0)
                {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl;
}
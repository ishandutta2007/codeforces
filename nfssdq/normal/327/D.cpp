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

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3;
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<56)-1
#define FOR(I,A,B) for(int  I = (A); I < (B); ++I )
#define REP(I,N)   FOR( I, 0, N)
#define ALL(A)     ( (A).begin(), (A).end() )
#define set0(ar)   memset( ar, 0, sizeof ar )
#define vsort(v)   sort( ALL(v) )
#define SET(ar,v)  memset( ar, v, sizeof ar )
#define setinf(a)  SET(a,126)


template <class T> inline T bigmod(T p,T e,T M)//p^e%M
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (LL)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


#define pdd pair<int,pair<int,int> >
priority_queue<pdd>pq;
char pp[501][501];
int vis[501][501],done[501][501];
int cur[501][501];
int a,b;
int nxt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
vector<string>out;
void dfs(int xi,int yi,int v)
{
    char pos[20];
    sprintf(pos,"B %d %d",xi+1,yi+1);
    string s="";
    REP(i,strlen(pos))s+=pos[i];
    out.push_back(s);
    vis[xi][yi]=v;
    pdd ps;
    REP(i,4)
    {
        int c,d;
        c=xi+nxt[i][0];
        d=yi+nxt[i][1];
        if(c>=0 && c<a && d>=0 && d<b && pp[c][d]!='#')
        {
            cur[c][d]++;
            if(vis[c][d]==0)dfs(c,d,v);
        }
    }
    ps.xx=10-cur[xi][yi];
    ps.yy.xx=xi;
    ps.yy.yy=yi;
    pq.push(ps);
}
void dfs2(int xi,int yi,int v)
{
    done[xi][yi]=v;
    REP(i,4)
    {
        int c,d;
        c=xi+nxt[i][0];
        d=yi+nxt[i][1];
        if(c>=0 && c<a && d>=0 && d<b && pp[c][d]!='#')
        {
            if(done[c][d]==0)dfs2(c,d,v);
        }
    }
    char ps[20];
    sprintf(ps,"D %d %d",xi+1,yi+1);
    string s="";
    REP(i,strlen(ps))s+=ps[i];
    out.push_back(s);
    sprintf(ps,"R %d %d",xi+1,yi+1);
    s="";
    REP(i,strlen(ps))s+=ps[i];
    out.push_back(s);
}
main()
{
    int c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    REP(i,a)
    {
        cin>>pp[i];
    }
    e=0;
    REP(i,a)
    {
        REP(j,b)
        {
            if(vis[i][j]==0 && pp[i][j]!='#')
            {
                while(!pq.empty())pq.pop();
                e++;
                dfs(i,j,e);
                f=0;
                pdd p2=pq.top();
                pq.pop();
                done[p2.yy.xx][p2.yy.yy]=e;
                while(!pq.empty())pq.pop();
                REP(k,4)
                {
                    c=p2.yy.xx+nxt[k][0];
                    d=p2.yy.yy+nxt[k][1];
                    if(c>=0 && c<a && d>=0 && d<b && pp[c][d]!='#')
                    {
                        dfs2(c,d,e);
                        break;
                    }
                }
            }
        }
    }
    cout<<out.size()<<endl;
    REP(i,out.size())cout<<out[i]<<endl;
}
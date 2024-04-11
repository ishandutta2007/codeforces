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

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)
#define PI 3.141592653589793238462643383279502884197169399375


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){T t=bigmod(p,e/2,M);return (t*t)%M;}
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
LL ar[501][501];
LL ff[501][501];
int n;
int off[1000];
struct node
{
    int name;
    LL value;
};

bool operator< (node e1, node e2) {
    return e1.value > e2.value;
}
priority_queue<node> pq;
LL dijk(int s)
{
    if(off[s]==1)return 0;
    LL a,b,c,d=0,e,f,g,h,x,y,z;
    for(x=1;x<=n;x++)
    {
        for(y=1;y<=n;y++)
        {
            ar[x][y]=linf;
            if(x==y)ar[x][y]=0;
        }
    }
    node st,ed;
    st.name=s;
    st.value=0;
    pq.push(st);
    while(!pq.empty())
    {
        st=pq.top();
        pq.pop();
        for(x=1;x<=n;x++)
        {
            if(off[x]==1)continue;
            ed.name=x;
            ed.value=ff[st.name][x];
            if(ar[s][x]>ar[s][st.name]+ed.value)
            {
                ar[s][x]=ar[s][st.name]+ed.value;
                pq.push(ed);
            }
        }

    }
    for(x=1;x<=n;x++)
    {
        if(off[x]==1)continue;
        d+=ar[s][x];
    }
    return d;
}
LL arr[1001];
LL ret[1001];
main()
{
    LL a,b,c,d,e,f,x,y,z;
    cin>>n;
    for(x=1;x<=n;x++)
    {
        for(y=1;y<=n;y++)cin>>ff[x][y];
    }
    for(x=1;x<=n;x++)
    {
        cin>>arr[x];
        off[x]=1;
    }
    for(x=n;x>=1;x--)
    {
        for(y=1;y<=n;y++)
        {
            ar[arr[x]][y]=ff[arr[x]][y];
            for(z=x+1;z<=n;z++)
            {
                ar[arr[x]][y]=min(ar[arr[x]][arr[z]]+ar[arr[z]][y],ar[arr[x]][y]);
            }
            ar[y][arr[x]]=ff[y][arr[x]];
            for(z=x+1;z<=n;z++)
            {
                ar[y][arr[x]]=min(ar[y][arr[z]]+ar[arr[z]][arr[x]],ar[y][arr[x]]);
            }
        }

        a=0;
        off[arr[x]]=0;
        for(y=1;y<=n;y++)
        {
            for(z=1;z<=n;z++)
            {
                if(off[y]==1 || off[z]==1)continue;
                if(ar[y][z]>ar[y][arr[x]]+ar[arr[x]][z])ar[y][z]=ar[y][arr[x]]+ar[arr[x]][z];
                a+=ar[y][z];
            }
        }
        ret[x]=a;
    }
    for(x=1;x<=n;x++)cout<<ret[x]<<" ";
}
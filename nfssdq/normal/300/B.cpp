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
#define PI 2.0*acos(0.0)
#define linf (1ll<<63)-1
#define all(v) (v.begin(),v.end())
#define set0(ar) memset(ar,0,sizeof ar)
#define vsort(v) sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)



template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return ((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
int pr[50];
vector<int> ar[50];
int find(int p)
{
    if(pr[p]==p)return p;
    return pr[p]=find(pr[p]);
}
void uni(int a,int b)
{
    if(find(a)==find(b))return;
    pr[pr[b]]=a;
}
vector<int>np[2];
vector<vector<int> >prnt;
main()
{
    int a,b,c,d,e,f,x,y,z;
    cin>>a>>b;
    for(x=1;x<=a;x++)pr[x]=x;
    for(x=0;x<b;x++)
    {
        cin>>c>>d;
        uni(c,d);
    }
    for(x=1;x<=a;x++)
    {
        c=find(x);
        ar[c].push_back(x);
    }
    for(x=1;x<=a;x++)
    {
        if(ar[x].size()==1)np[0].push_back(x);
        else if(ar[x].size()==2)np[1].push_back(x);
        else if(ar[x].size()==3)prnt.push_back(ar[x]);
        else if(ar[x].size()>3)
        {
            cout<<-1;
            return 0;
        }
    }
    if(np[1].size()>np[0].size())
    {
        cout<<-1;
        return 0;
    }
    for(x=0;x<np[1].size();x++)
    {
        ar[np[1][x]].push_back(np[0][x]);
        prnt.push_back(ar[np[1][x]]);
    }
    if((np[0].size()-np[1].size())%3!=0)
    {
        cout<<-1;
        return 0;
    }
    for(x=np[1].size();x<np[0].size();x+=3)
    {
        vector<int>vr;
        for(y=x;y<x+3;y++)vr.push_back(np[0][y]);
        prnt.push_back(vr);
    }
    for(x=0;x<prnt.size();x++)
    {
        for(y=0;y<3;y++)
        {
            cout<<prnt[x][y]<<" ";
        }
        cout<<endl;
    }
}
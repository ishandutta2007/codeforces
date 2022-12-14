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

int ar[1000001],gt[1000001];
priority_queue<pair<int,int> >pq;
char p1[1000001],p2[1000001];
main()
{
    int a,b,c,d=0,e,f,g,h,x,y,z;
    /*cin>>a;
    for(x=0;x<a;x++)
    {
        cin>>b>>c;
        d+=b;
        pq.push(make_pair(c,x));
        gt[x]=b;
    }
    e=0;
    while(!pq.empty())
    {
        pair<int,int>pp=pq.top();
        pq.pop();
        e+=pp.xx;
        d-=gt[pp.yy];
        ar[pp.yy]=1;
        if(abs(d-e)<=500)break;
        if(abs(d-e)>500)
        {
            d+=gt[pp.yy];
            e-=pp.xx;
            ar[pp.yy]=0;
        }
    }
    if(abs(d-e)>500)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(x=0;x<a;x++)
    {
        if(ar[x]==0)cout<<"A";
        else cout<<"G";
    }
    cout<<endl;*/

    cin>>p1>>p2;
    a=strlen(p1);
    b=strlen(p2);
    if(a!=b)
    {
        cout<<"NO";
        return 0;
    }
    b=0;
    c=0;
    for(x=0;x<a;x++)
    {
        b+=p1[x]-'0';
        c+=p2[x]-'0';
    }
    if(b==0 && c>0)cout<<"NO";
    else if(c==0 && b>0)cout<<"NO";
    else cout<<"YES";

}
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
LL ar[100001],ar2[100001];
LL fact[300001];
pair<LL,LL>fin[300001];
LL calc(LL a, LL b,LL c)
{
    LL d=1;
    for(int x=1;x<=a;x++)
    {
        LL p=x;
        while(b>0 && p%2==0)
        {
            p/=2;
            b--;
        }
        d=(d*p)%c;
    }
    return d;
}
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;

    for(x=0;x<a;x++)
    {
        cin>>ar[x];
    }
    for(x=0;x<a;x++)
    {
        cin>>ar2[x];
    }

    LL m;
    cin>>m;
    e=0;
    for(x=0;x<a;x++){fin[e].xx=ar[x];fin[e++].yy=x;}
    for(x=0;x<a;x++){fin[e].xx=ar2[x];fin[e++].yy=x;}
    sort(fin,fin+e);
    f=1;
    b=0;
    x=0;
    while(x<e)
    {
        LL p=fin[x].xx;
        while(x<e && fin[x].xx==p)x++;
        while(fin[b].xx<p && b<x)b++;
        c=0;
        for(y=b;y<x-1;y++)if(fin[y].yy==fin[y+1].yy)c++;
        f=(f*calc(x-b,c,m))%m;
        //cout<<f<<" "<<p<<" "<<x-b<<" "<<fact[x-b]<<" "<<modInverse((LL)c,m)<<endl;
    }
    cout<<f<<endl;
}
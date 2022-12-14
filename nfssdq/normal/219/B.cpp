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
int ar[26],ar2[26];
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    c=0;
    a-=b;
    d=a+b;
    e=0;
    while(a>0)
    {
        ar[c++]=a%10;
        a/=10;
    }
    while(d>0)
    {
        ar2[e++]=d%10;
        d/=10;
    }
    for(x=max(e-1,c-1);x>=0;x--)
    {
        if(ar[x]==ar2[x])continue;
        ar[x]=ar2[x]-1;
        f=0;
        for(y=x-1;y>=0;y--)if(ar2[y]!=9)f++;
        if(f==0)ar[x]=ar2[x];
        for(y=x-1;y>=0;y--)ar[y]=9;
        break;
    }
    d=0;
    for(x=max(e-1,c-1);x>=0;x--)d=(d*10)+ar[x];
    cout<<d<<endl;
}
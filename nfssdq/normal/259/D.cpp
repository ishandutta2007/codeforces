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
#define LL long long
int get[12];
int val[12];
int cnt(int lft,int on,int has)
{
    int a,b,c,d,e,f,g,h,x,y,z;
    a=0;
    if(lft==0 && has==0)return 1;
    else if(lft==0)return 0;
    if(on==0)
    {
        if(lft>has)a+=8*cnt(lft-1,on,has);
        if(has>0)a+=2*cnt(lft-1,on,has-1);
    }
    else
    {
        if(lft>has)
        {
            if(val[lft]>7)a+=(val[lft]-2)*cnt(lft-1,0,has);
            else if(val[lft]>4)a+=(val[lft]-1)*cnt(lft-1,0,has);
            else a+=(val[lft])*cnt(lft-1,0,has);
            if(val[lft]!=7 && val[lft]!=4)a+=cnt(lft-1,1,has);
        }
        if(val[lft]>7 && has>0)a+=2*cnt(lft-1,0,has-1);
        else if(val[lft]==7 && has>0)a+=cnt(lft-1,1,has-1)+cnt(lft-1,0,has-1);
        else if(val[lft]>4 && has>0)a+=cnt(lft-1,0,has-1);
        else if(val[lft]==4 && has>0)a+=cnt(lft-1,1,has-1);
    }
    return a;
}
int ar[12];
int mod=1000000007;
LL go(int lft,int hm,int pre)
{
    int a,b,c=0,d,e,f,g,h,x,y,z;
    LL p=0;
    if(lft==0)return 1;
    for(x=0;x<=hm;x++)
    {
        get[x]--;
        if(get[x]>=0)
        {
            p=(p+((LL)(get[x]+1)*go(lft-1,hm-x,x)%mod)%mod)%mod;
            c++;
        }
        get[x]++;
    }
    return p%mod;
}
//361467798
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    b=a;
    c=0;
    while(b>0)
    {
        c++;
        val[c]=b%10;
        b/=10;
    }
    for(x=0;x<10;x++)get[x]=cnt(c,1,x);
    LL p=0;
    get[0]--;
    for(x=1;x<10;x++)
    {
        p=(p+((LL)get[x]*go(6,x-1,x-1)%mod)%mod)%mod;
    }
    cout<<p<<endl;
}
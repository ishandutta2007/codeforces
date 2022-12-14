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

int ar[100001],val[100001];
int get(int id)
{
    if(id==0)return 0;
    return id%2+get(id/2);
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)
    {
        cin>>ar[x];
        b=ar[x];
        val[x]=get(ar[x]);
    }
    sort(val,val+a);
    b=0;
    LL res=0;
    for(x=0;x<a;x++)
    {
        while(val[b]<val[x] && b<x)
        {
            b++;
        }
        d=(x-b+1);
        res+=(LL)(x-b);
    }
    cout<<res<<endl;
}
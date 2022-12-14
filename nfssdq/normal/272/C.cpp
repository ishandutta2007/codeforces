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

LL ar[100001],val[100001];
LL bit[100001];
void insert(int id)
{
    int p=id;
    while(id<=100000)
    {
        bit[id]=max(bit[id],ar[p]);
        //cout<<id<<" "<<bit[id]<<endl;
        id+=(id & -id);
    }
}
LL query(LL id)
{
    LL a=0;
    while(id>0)
    {
        a=max(a,bit[id]);
        id-=(id & -id);
    }
    return a;
}
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=1;x<=a;x++)
    {
        cin>>ar[x];
        insert(x);
    }
    cin>>b;
    for(x=1;x<=b;x++)
    {
        cin>>c>>d;
        LL p=query(c);
        cout<<p<<endl;
        ar[1]=p+(LL)d;
        insert(1);
    }
}
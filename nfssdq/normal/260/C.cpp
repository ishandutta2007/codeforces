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
LL ar[100001];
main()
{
    LL a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    c=9999999LL*9999999LL;
    d=0;
    for(x=1;x<=a;x++)
    {
        cin>>ar[x];
        if(ar[x]<c)
        {
            c=ar[x];
            d=x;
        }
        else if(ar[x]==c && (b>=x || b<d))
        {
            d=x;
        }
    }
    e=0;
    for(x=1;x<=a;x++)
    {
        e+=c;
        ar[x]-=c;
    }
    if(b<d)
    {
        for(x=1;x<=b;x++)
        {
            e+=1;
            ar[x]--;
        }
        for(x=d+1;x<=a;x++)
        {
            e++;
            ar[x]--;
        }
    }
    else
    {
        for(x=d+1;x<=b;x++)
        {
            e++;
            ar[x]--;
        }
    }
    ar[d]=e;
    for(x=1;x<=a;x++)
    {
        if(x!=1)cout<<" ";
        cout<<ar[x];
    }
    cout<<endl;
}
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

main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d %d %d",&a,&b,&c);
    c--;
    d=-1;
    f=0;
    for(x=0;x<10;x++)
    {
        d=a*10+x;
        if(d%b==0)
        {
            f=x;
            d=a*10+x;
            break;
        }
        d=-1;
    }
    if(d==-1)cout<<-1<<endl;
    else
    {
        cout<<d;
        for(x=1;x<=c;x++)cout<<0;
        cout<<endl;
    }
}
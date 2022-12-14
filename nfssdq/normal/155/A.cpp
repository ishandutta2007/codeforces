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
int main()
{
    long a,b,c,d,e,f,x,y,z;
    scanf("%ld %ld",&a,&b);
    c=b;
    d=0;
    for(x=2;x<=a;x++)
    {
        scanf("%ld",&e);
        if(e>c)
        {
            c=e;
            d++;
        }
        if(e<b)
        {
            b=e;
            d++;
        }
    }
    printf("%ld\n",d);
    return 0;
}
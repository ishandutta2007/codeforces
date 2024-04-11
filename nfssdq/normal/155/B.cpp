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
    long m[1000],n[1000];
    scanf("%ld",&a);
    for(x=0;x<a;x++)
    {
        scanf("%ld %ld",&m[x],&n[x]);
    }
    for(x=0;x<a-1;x++)
    {
        for(y=x+1;y<a;y++)
        {
            if(n[x]<n[y])
            {
                b=n[x];
                n[x]=n[y];
                n[y]=b;
                b=m[x];
                m[x]=m[y];
                m[y]=b;
            }
            else if(n[x]==n[y] && m[x]<m[y])
            {
                b=m[x];
                m[x]=m[y];
                m[y]=b;
            }
        }
    }
    b=1;
    c=0;
    d=0;
    while(b>0)
    {
        b--;
        if(d==a)
        {
            break;
        }
        b+=n[d];
        c+=m[d];
        d++;
    }
    printf("%ld\n",c);
    return 0;
}
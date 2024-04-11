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
int on[1001],of[1001];
main()
{

    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d %d",&a,&b);
    for(x=0;x<b;x++)
    {
        scanf("%d",&of[x]);
        on[of[x]]=1;
    }
    for(x=0;x<b;x++)
    {
        c=1;
        cout<<of[x];
        for(y=1;y<=b*a;y++)
        {
            if(c==a)break;
            if(on[y]==0)
            {
                cout<<" "<<y;
                on[y]=1;
                c++;
            }
        }
        cout<<endl;
    }
}
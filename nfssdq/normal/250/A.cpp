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
#define LL long long

vector<int>vc;
int main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    b=0;
    d=0;
    for(x=0;x<a;x++)
    {
        scanf("%d",&c);
        b++;
        if(c<0)d++;
        if(d>2)
        {
            vc.push_back(b-1);
            b=1;
            if(d>0)d=1;
        }
    }
    vc.push_back(b);
    cout<<vc.size()<<endl;
    for(x=0;x<vc.size();x++)
    {
        if(x!=0)cout<<" ";
        cout<<vc[x];
    }
    cout<<endl;
    return 0;
}
//1000000000
//999999999
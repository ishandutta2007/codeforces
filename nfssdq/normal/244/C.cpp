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

int ar[100001];
int bit[35];
set<int>st;
vector<int>vv;
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    for(x=1;x<=a;x++)
    {
        scanf("%d",&b);
        st.insert(b);
        vv.clear();
        for(y=0;y<30;y++)vv.push_back(bit[y]);
        sort(vv.begin(),vv.end());
        c=b;
        for(y=30-1;y>=0;y--)
        {
            c|=ar[vv[y]];
            st.insert(c);
        }
        for(y=0;y<30;y++)
        {
            if((b & (1<<y))>0)bit[y]=x;
        }
        ar[x]=b;
    }
    cout<<st.size()<<endl;
}
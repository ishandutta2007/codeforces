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

int ar[100001];
vector<int>vc[100001];
int main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d %d",&a,&b);
    for(int r=0;r<a;r++)
    {
        scanf("%d",&ar[r]);
        vc[ar[r]].push_back(r);
    }
    d=0;
    h=0;
    for(x=1;x<=b;x++)
    {
        e=0;
        f=0;
        g=0;
        for(y=0;y<vc[x].size();y++)
        {
            f=vc[x][y];
            if(y==0)e=vc[x][y];
            if(y!=vc[x].size()-1 && vc[x][y+1]==vc[x][y]+1)continue;
            g++;
            if(e!=0 && f!=a-1 && ar[e-1]==ar[f+1])g++;
            if(y!=vc[x].size()-1)e=vc[x][y+1];
        }
        if(g>d)
        {
            d=g;
            h=x;
        }
    }
    cout<<h<<endl;
    return 0;
}
//1000000000
//999999999
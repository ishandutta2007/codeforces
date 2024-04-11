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
vector<pair<int,pair<int,int> > >vv;
int main()
{
    //freopen("a.out","w",stdout);
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    for(x=1;x<=a;x++)
    {
        scanf("%d %d",&b,&c);
        vv.push_back(make_pair(c,make_pair(b*-1,x)));
    }
    sort(vv.begin(),vv.end());
    a=0;
    b=vv.size()-1;
    for(x=0;x<vv.size()-1;x++)
    {
        if(vv[x].first>vv[b].first || vv[x].second.first*-1<vv[b].second.first*-1)a++;
    }
    if(a==0)cout<<vv[x].second.second<<endl;
    else cout<<-1<<endl;
}
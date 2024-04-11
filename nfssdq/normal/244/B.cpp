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
int v;
set<int>st;
int cnt=0;
void go(int x,int y,int dg,long long val)
{
    //cout<<val<<" "<<dg<<endl;
    if(val>v)return;
    if(val!=0 && val<=v)st.insert((int)val);
    if(dg==0)
        return;

    go(x,y,dg-1,val*10+x);
    go(x,y,dg-1,val*10+y);
}
char pp[12];
main()
{

    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%s",pp);
    b=strlen(pp);
    a=0;
    for(x=0;x<b;x++)a=(a*10)+pp[x]-'0';
    v=a;
    for(x=0;x<10;x++)
    {
        for(y=x;y<10;y++)go(x,y,b,0);
    }
    cout<<st.size()<<endl;
}
//1000000000
//999999999
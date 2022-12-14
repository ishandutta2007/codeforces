
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
char pp[8][8];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    for(x=0;x<8;x++)scanf("%s",pp[x]);
    a=0;
    for(x=0;x<8;x++)
    {
        for(y=0;y<8;y++)if(y>0 &&pp[x][y-1]==pp[x][y])a++;
    }
    if(a==0)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
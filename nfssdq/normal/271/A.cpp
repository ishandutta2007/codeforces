#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
int ar[11];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=a+1;x<=12345;x++)
    {
        b=x;
        memset(ar,0,sizeof ar);
        while(b>0)
        {
            ar[b%10]++;
            b/=10;
        }
        c=0;
        //cout<<x<<endl;
        for(y=0;y<10;y++)if(ar[y]>1)c++;
        if(c==0)
        {
            cout<<x<<endl;
            return 0;
        }
    }
}
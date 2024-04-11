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
int ar[2][1000001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    if(a<b*3)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(x=0;x<b;x++)ar[0][x]=x+1;
    for(x=0;x<b;x++)
    {
        c=b-x;
        ar[1][x]=c;
    }
    c=b/2;
    if(b%2==1)
    {
        swap(ar[1][0],ar[1][c]);
    }
    for(x=0;x<a;x++)
    {
        c=x/b;
        if(x!=0)cout<<" ";
        if(c%2==0)
        {
            d=x%b;
            cout<<ar[0][d];
        }
        else
        {
            d=x%b;
            cout<<ar[1][d];
        }
    }
    cout<<endl;
}
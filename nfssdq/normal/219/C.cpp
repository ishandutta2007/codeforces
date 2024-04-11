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
int dp[500001][26];
char pp[500001];
char pr[500001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    cin>>pp;
    for(x=1;x<=a;x++)
    {
        for(y=0;y<b;y++)
        {
            dp[x][y]=99999999;
            if(pp[x-1]==y+'A')c=0;
            else c=1;
            for(z=0;z<b;z++)
            {
                if(z==y)continue;
                dp[x][y]=min(dp[x][y],c+dp[x-1][z]);
            }
        }
    }
    c=0;
    d=99999999;
    for(x=0;x<b;x++)
    {
        if(dp[a][x]<d)
        {
            d=dp[a][x];
            c=x;
        }
    }
    cout<<d<<endl;
    pr[a-1]=c+'A';
    for(x=a-2;x>=0;x--)
    {
        e=d-1;
        if(pp[x+1]==c+'A')e++;
        for(y=0;y<b;y++)
        {
            if(y!= c && dp[x+1][y]==e)
            {
                d=dp[x+1][y];
                c=y;
                pr[x]=y+'A';
                break;
            }
        }
    }
    cout<<pr<<endl;
}
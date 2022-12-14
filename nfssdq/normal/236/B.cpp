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
#include <climits>

using namespace std;

#define ULL unsigned long long
#define LL long long
#define inf INT_MAX
#define PI 2.0*acos(0.0)
#define vi vector<int>
#define vl vector<long long>
#define pdd pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define mdd map<int,int>
#define mod 1000000007
#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define cas(a) printf("Case %d:\n",a)
#define pb push_back

int pp[1000001];
vector<int>pr;
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    pp[1]=1;
    for(x=2;x<=1000;x++)
    {
        a=0;
        for(y=2;y<=sqrt(x);y++)
        {
            if(x%y==0)a++;
        }
        if(a==0)pr.push_back(x);
    }
    for(x=2;x<=1000000;x++)
    {
        pp[x]=1;
        for(y=0;y<pr.size();y++)
        {
            a=0;
            b=pr[y];
            while(x%b==0)
            {
                a++;
                b*=pr[y];
            }
            pp[x]*=(a+1);
        }
    }
    a=1<<30;
    scanf("%d %d %d",&b,&c,&d);
    e=0;
    for(x=1;x<=b;x++)
    {
        for(y=1;y<=c;y++)
        {
            for(z=1;z<=d;z++)
            {
                e=(e+pp[x*y*z])%a;
            }
        }
    }
    cout<<e<<endl;
}
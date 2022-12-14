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
int pr[1000001];
vector<int>vv;
void sieve()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    pr[1]=1;
    for(x=2;x<=1000000;x++)
    {
        if(pr[x]==0)
        {
            vv.push_back(x);
            for(y=x*2;y<=1000000;y+=x)pr[y]=1;
        }
    }
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d %d %d",&a,&b,&c);
    sieve();
    e=0;
    d=0;
    f=b+1;
    for(x=b;x>=a;x--)
    {
        for(y=f-1;y>=a;y--)
        {
            if(d==c)break;
            if(pr[y]==0)d++;
            if(d==c){f=y;break;}
        }
        if(f<a)break;
        if(d!=c)
        {
            g=0;
            h=0;
            for(y=a;y<=b;y++)
            {
                if(pr[y]==0)g++;
                if(g==c){h=y;break;}
            }
            if(h!=0)e=max(e,h-a+1);
            else e=-1;
            break;
        }
        e=max(e,x-f+1);
        if(pr[x]==0)d--;
    }
    cout<<e<<endl;
}
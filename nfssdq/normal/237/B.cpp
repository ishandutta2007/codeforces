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
int ar[2551][2];
int get[2551];
vector<pair<pair<int,int>,pair<int,int> > >pp;
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    b=0;
    for(x=0;x<a;x++){scanf("%d",&get[x]);b+=get[x];};
    for(x=0;x<a;x++)
    {
        for(y=0;y<get[x];y++)
        {
            scanf("%d",&c);
            ar[c][0]=x;
            ar[c][1]=y;
        }
    }
    c=0;
    for(x=0;x<a;x++)
    {
        for(y=0;y<get[x];y++)
        {
            c++;
            if(ar[c][0]!=x || ar[c][1]!=y)
            {
                pp.push_back(make_pair(make_pair(x+1,y+1),make_pair(ar[c][0]+1,ar[c][1]+1)));
                d=0;
                for(z=1;z<=b;z++)if(ar[z][0]==x && ar[z][1]==y)d=z;
                swap(ar[d][0],ar[c][0]);
                swap(ar[d][1],ar[c][1]);
            }
        }
    }
    cout<<pp.size()<<endl;
    for(x=0;x<pp.size();x++)cout<<pp[x].xx.xx<<" "<<pp[x].xx.yy<<" "<<pp[x].yy.xx<<" "<<pp[x].yy.yy<<endl;

}
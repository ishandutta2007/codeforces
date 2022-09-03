/*
    Name: The Greatest Code of All Time
    Copyright: HaoBa IT Junior One
    Author: OhWeOnFire
    Date: Today and Forever
    Description: This code is amazing, as you can see, right?
*/


#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <unordered_set>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)

using namespace std;
typedef long long LL;
typedef long double LF;
const int maxn=200005;
const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const LL mod=1000000007;
const double EPS=1e-10;
using namespace std;

const int dx[]={-1,-1,1,1};
const int dy[]={-1,1,-1,1};

int n,m,k,xs,ys,ds;
set<pair<int,int> > a[maxn],b[maxn];
unordered_set<int> f[maxn];
inline void insert(int x,int y)
{
    b[x+y].insert(mp(x,y));
    a[x-y+m+1].insert(mp(x,y));
    f[x].insert(y);
}
int py;
bool aa,bb;
void find(int x,int y,int d,int &xx,int &yy,int &dd,int &px)
{
    if(d==0)
    {
        auto t=a[x-y+m+1].lower_bound(mp(x,y));
        t--;
        px=t->first;
        py=t->second;
        aa=f[px+1].count(py);
        bb=f[px].count(py+1);
        if(!aa&&bb)
        {
            xx=px+1;
            yy=py;
            dd=2;
        }
        else if(aa&&!bb)
        {
            xx=px;
            yy=py+1;
            dd=1;
        }
        else
        {
            xx=px+1;
            yy=py+1;
            dd=3;
        }
    }
    else if(d==1)
    {
        auto t=b[x+y].lower_bound(mp(x,y));
        t--;
        px=t->first;
        py=t->second;
        aa=f[px+1].count(py);
        bb=f[px].count(py-1);
        if(!aa&&bb)
        {
            xx=px+1;
            yy=py;
            dd=3;
        }
        else if(aa&&!bb)
        {
            xx=px;
            yy=py-1;
            dd=0;
        }
        else
        {
            xx=px+1;
            yy=py-1;
            dd=2;
        }
    }
    else if(d==2)
    {
        auto t=b[x+y].upper_bound(mp(x,y));
        px=t->first;
        py=t->second;
        aa=f[px-1].count(py);
        bb=f[px].count(py+1);
        if(!aa&&bb)
        {
            xx=px-1;
            yy=py;
            dd=0;
        }
        else if(aa&&!bb)
        {
            xx=px;
            yy=py+1;
            dd=3;
        }
        else
        {
            xx=px-1;
            yy=py+1;
            dd=1;
        }
    }
    else
    {
        auto t=a[x-y+m+1].upper_bound(mp(x,y));
        px=t->first;
        py=t->second;
        aa=f[px-1].count(py);
        bb=f[px].count(py-1);
        if(!aa&&bb)
        {
            xx=px-1;
            yy=py;
            dd=1;
        }
        else if(aa&&!bb)
        {
            xx=px;
            yy=py-1;
            dd=2;
        }
        else
        {
            xx=px-1;
            yy=py-1;
            dd=0;
        }
    }
}
int main(){
    char s[22];
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,x,y;i<=k;++i)
    {
        scanf("%d%d",&x,&y);
        insert(x,y);
    }
    for(int i=0;i<=n+1;i++)
    {
        insert(i,0);
        insert(i,m+1);
    }
    for(int i=0;i<=m+1;++i)
    {
        insert(0,i);
        insert(n+1,i);
    }
    scanf("%d%d%s",&xs,&ys,s);
    ds=(s[1]=='E')|((s[0]=='S')<<1);
    LL ans=0;
    bool flag=false;
    int x,y,d,xx,yy,dd,px;
    find(xs,ys,ds,xs,ys,ds,px);
    x=xs;
    y=ys;
    d=ds;
    for(int x=xs,y=ys,d=ds;;x=xx,y=yy,d=dd)
    {
        find(x,y,d,xx,yy,dd,px);
        ans+=abs(x-px);
        if(xx==xs&&yy==ys&&dd==ds)
            break;
        if(d+dd==3)
            flag|=true;
    }
    if(flag)
        ans>>=1;
    printf("%I64d\n",ans);
    return 0;
}
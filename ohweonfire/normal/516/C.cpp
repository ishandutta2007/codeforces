/*
    Name: You Guess
    Copyright: You Guess
    Author: You Guess
    Date: 20-02-15 20:15
    Description: You Guess
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
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)
#define LOCAL

using namespace std;
typedef long long LL;
typedef long double LF;
const int inf=1000000000;
const LL Linf=1000000000000000ll;
const LL mod=1000000007;
const double EPS=1e-10;
const int maxn=200005;
struct data{
    LL maxs,mx,my;
};
data calmax(const data &tmp1,const data &tmp2)
{
    data res;
    res.mx=max(tmp1.mx,tmp2.mx);
    res.my=max(tmp1.my,tmp2.my);
    res.maxs=max(tmp1.mx+tmp2.my,max(tmp1.maxs,tmp2.maxs));
    return res;
}
LL s[maxn],x[maxn],y[maxn];
int h[maxn],d[maxn],n;
data t[maxn*3];
void Build(int x,int l,int r)
{
    if(l==r)
        t[x]=(data){-Linf,::x[l],y[l]};
    else
    {
        int mid=l+r>>1;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        t[x]=calmax(t[x<<1],t[x<<1|1]);
    }
    //printf("%d %d %d %I64d %I64d %I64d\n",l,r,x,t[x].maxs,t[x].mx,t[x].my);
}
bool flag;
int l1,r1;
data ans;
data Query(int x,int l,int r)
{
    if(l1<=l&&r<=r1)
    {
        return t[x];
    }
    else
    {
        int mid=l+r>>1;
        if(r1<=mid)
            return Query(x<<1,l,mid);
        if(l1>mid)
            return Query(x<<1|1,mid+1,r);
        return calmax(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
    }
}
int main()
{
    int Q;
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",d+i);
        s[i+1]=s[i]+d[i];
    }
    for(int i=n+1;i<=(n<<1);i++)s[i+1]=s[n+1]+s[i-n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",h+i);
        h[i+n]=h[i];
    }
    for(int i=1;i<=n+n;i++)
    {
        x[i]=2*h[i]-s[i];
        y[i]=2*h[i]+s[i];
    }
    Build(1,1,n+n);
    //system("pause");
    while(Q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l<=r)l+=n;l--,r++;if(r<l)swap(l,r);
        l1=l;
        r1=r;
        ans=Query(1,1,n+n);
        printf("%I64d\n",ans.maxs);
    }
    return 0;
}
/*
10 10
8477 33103 38654 6582 27496 1106 15985 3644 29818 8849
88745 72099 87767 85285 73517 94562 87214 63194 83791 77619
2 8
1 5
9 5
7 8
6 9
8 1
6 1
4 9
8 10
5 10
*/
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcountll(i)
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
#define size fuck
using namespace std;
struct node
{
    int p,x,y;
}a[210000];
int n,m;
map<pair<int,int>,int> dic;
map<int,int> legal[210000];
int father[210000],size[210000];
int getfather(int x)
{
    if (father[x]==x)return x;
    return getfather(father[x]);
}
vector<pair<int,int> > st[810000];
void insert(int t,int l,int r,int a,int b,int x,int y)
{
    if (a<=l && r<=b)
    {
        st[t].pb(mp(x,y));
        return;
    }
    int mid=(l+r)/2;
    if (a<=mid)insert(2*t,l,mid,a,b,x,y);
    if (b>mid)insert(2*t+1,mid+1,r,a,b,x,y);
}
int last=0;
void work(int t,int l,int r)
{
    vector<pair<int,int> > q; q.clear();
    for(auto p:st[t])
    {
        int x=p.first,y=p.second;
        if (!legal[x][y])continue;
        int t1=getfather(x);
        int t2=getfather(y);
        if (t1==t2)continue;
        if (size[t1]>size[t2])swap(t1,t2);
        q.pb(mp(t1,t2));
        father[t1]=t2; 
        size[t2]+=size[t1];
    }
    if (l==r)
    {
        if (a[l].p==2)
        {
            int t1=getfather(a[l].x);
            int t2=getfather(a[l].y);
            if (t1==t2)last=1; else last=0;
            putchar('0'+last);
        }
        a[l+1].x=(a[l+1].x+last-1)%n+1;
        a[l+1].y=(a[l+1].y+last-1)%n+1;
        if (a[l+1].x>a[l+1].y)swap(a[l+1].x,a[l+1].y);
        if (a[l+1].p==1)legal[a[l+1].x][a[l+1].y]^=1;
    }
    else
    {
        int mid=(l+r)/2;
        work(2*t,l,mid);
        work(2*t+1,mid+1,r);
    }
    for(auto p:q)
    {
        int x=p.first,y=p.second;
        size[y]-=size[x];
        father[x]=x;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].p,&a[i].x,&a[i].y);
        if (a[i].x>a[i].y)swap(a[i].x,a[i].y);
    }
    dic.clear();
    for(int i=1;i<=m;i++)
    if (a[i].p==1)
    {
        int x1=a[i].x,y1=a[i].y; if (x1>y1)swap(x1,y1);
        int x2=x1%n+1,y2=y1%n+1; if (x2>y2)swap(x2,y2);
        if (dic.find(mp(x1,y1))!=dic.end())insert(1,1,m,dic[mp(x1,y1)],i-1,x1,y1);
        if (dic.find(mp(x2,y2))!=dic.end())insert(1,1,m,dic[mp(x2,y2)],i-1,x2,y2);
        dic[mp(x1,y1)]=i;
        dic[mp(x2,y2)]=i;
    }
    for(auto p:dic)insert(1,1,m,p.second,m,p.first.first,p.first.second);
    for(int i=1;i<=n;i++)father[i]=i,size[i]=1;
    if (a[1].p==1)legal[a[1].x][a[1].y]=1;
    work(1,1,m);
    puts("");
    return 0;
}
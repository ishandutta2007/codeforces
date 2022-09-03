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
class DSU
    {
        int sz;
        int f[maxn],cnt[maxn];
        public:
            int mx;
            void init(int &SZ)
            {
                sz=SZ;
                for(int i=1;i<=SZ;++i)
                    f[i]=i,cnt[i]=1;
                mx=1;
            }
            int greatest_father(int x)
            {
                if(f[x]==x)
                    return x;
                else
                    return f[x]=greatest_father(f[x]);
            }
            bool same(int x,int y)
            {
                x=greatest_father(x);
                y=greatest_father(y);
                return x==y;
            }
            void unionset(int x,int y)
            {
                x=greatest_father(x);
                y=greatest_father(y);
                if(x==y)
                    return ;
                f[x]=y;
                cnt[y]+=cnt[x];
                mx=max(mx,cnt[y]);
            }
};
DSU t[2];
int opr[maxn],pos[maxn],ans[maxn][2];
int n,w,h;
bool occur[maxn][2];
int main()
{
    scanf("%d%d%d",&w,&h,&n);
    t[0].init(w);
    t[1].init(h);
    char s[4];
    for(int i=0,x,tt;i<n;i++)
    {
        scanf("%s%d",s,&x);
        tt=s[0]=='H';
        opr[i]=tt;
        pos[i]=x;
        occur[x][tt]=true;
    }
    for(int i=1;i<w;i++)
        if(!occur[i][0])
            t[0].unionset(i,i+1);
    for(int i=1;i<h;i++)
        if(!occur[i][1])
            t[1].unionset(i,i+1);
    for(int i=n-1;i>=0;i--)
    {
        ans[i][0]=t[0].mx;
        ans[i][1]=t[1].mx;
        //printf("%d %d\n",ans[i][0],ans[i][1]);
        t[opr[i]].unionset(pos[i],pos[i]+1);
    }
    for(int i=0;i<n;i++)
        printf("%I64d\n",ans[i][0]*1ll*ans[i][1]);
    return 0;
}
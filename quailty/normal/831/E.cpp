#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=100005;
int a[MAXN];
set<int> st[MAXN];
struct BIT
{
    int n,c[MAXN];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]=0;
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)
            c[i]+=v;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)
            res+=c[i];
        return res;
    }
}bit;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),st[a[i]].insert(i);
    bit.init(n);
    for(int i=1;i<=n;i++)
        bit.update(i,1);
    int cnt=n,now=1,mi=0;
    long long res=0;
    while(cnt>0)
    {
        while(st[mi].empty())mi++;
        if(st[mi].lower_bound(now)!=st[mi].end())
        {
            int la=now;
            now=*st[mi].lower_bound(now);
            res+=bit.query(now)-bit.query(la-1);
        }
        else
        {
            int la=now;
            now=*st[mi].lower_bound(1);
            res+=bit.query(n)-bit.query(la-1)+bit.query(now);
        }
        bit.update(now,-1);
        st[mi].erase(now);
        cnt--;
    }
    return 0*printf("%lld",res);
}
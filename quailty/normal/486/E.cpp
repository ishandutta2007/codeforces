#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct BIT
{
    int n,c[MAXN];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    void update(int p,int v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]=max(c[i],v);
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)res=max(res,c[i]);
        return res;
    }
}bit;
int a[MAXN],pre[MAXN],suf[MAXN],cnt[MAXN];
char res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bit.init(100000);
    for(int i=1;i<=n;i++)
    {
        pre[i]=bit.query(a[i]-1)+1;
        bit.update(a[i],pre[i]);
    }
    bit.init(100000);
    for(int i=1;i<=n;i++)
        a[i]=100001-a[i];
    for(int i=n;i>=1;i--)
    {
        suf[i]=bit.query(a[i]-1)+1;
        bit.update(a[i],suf[i]);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,pre[i]);
    for(int i=1;i<=n;i++)
    {
        if(pre[i]+suf[i]<mx+1)res[i]='1';
        else cnt[pre[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(pre[i]+suf[i]==mx+1)
            res[i]='2'+(cnt[pre[i]]==1);
    return 0*printf("%s",res+1);
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
struct Fenwick_Tree
{
    int sz,c[305];
    void init(int n)
    {
        sz=n;
        for(int i=1;i<=n;i++)c[i]=0;
    }
    int lowbit(int x)
    {
        return x&(-x);
    }
    void update(int p,int v)
    {
        for(int i=p;i<=sz;i+=lowbit(i))c[i]=max(c[i],v);
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=lowbit(i))res=max(res,c[i]);
        return res;
    }
}BIT;
int b[200005],cnt[305];
int pre[305],suf[305];
int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(T<=2000)
    {
        for(int i=0;i<T;i++)
            for(int j=1;j<=n;j++)
                b[i*n+j]=a[j];
        int ans=0;
        BIT.init(300);
        for(int i=1;i<=n*T;i++)
        {
            int len=BIT.query(b[i])+1;
            BIT.update(b[i],len);
            ans=max(ans,len);
        }
        printf("%d\n",ans);
    }
    else
    {
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;
        for(int i=0;i<2000;i++)
            for(int j=1;j<=n;j++)
                b[i*n+j]=a[j];
        BIT.init(300);
        for(int i=1;i<=1000*n;i++)
        {
            pre[b[i]]=BIT.query(b[i])+1;
            BIT.update(b[i],pre[b[i]]);
        }
        BIT.init(300);
        for(int i=2000*n;i>1000*n;i--)
        {
            suf[b[i]]=BIT.query(301-b[i])+1;
            BIT.update(301-b[i],suf[b[i]]);
        }
        int ans=0;
        for(int i=1;i<=300;i++)
            ans=max(ans,pre[i]+suf[i]+cnt[i]*(T-2000));
        printf("%d\n",ans);
    }
    return 0;
}
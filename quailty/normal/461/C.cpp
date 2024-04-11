#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
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
        for(int i=p;i<=n;i+=i&-i)c[i]+=v;
    }
    int query(int p)
    {
        int res=0;
        for(int i=p;i>0;i-=i&-i)res+=c[i];
        return res;
    }
}bit;
int a[MAXN];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    bit.init(n);
    for(int i=1;i<=n;i++)
        bit.update(i,a[i]=1);
    int pl=1,pr=n,rev=0;
    for(int i=1;i<=q;i++)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            int p;
            scanf("%d",&p);
            if(p>(pr-pl+1)/2)
            {
                p=(pr-pl+1)-p;
                rev^=1;
            }
            if(!rev)
            {
                for(int i=pl+p-1,j=pl+p;i>=pl;i--,j++)
                {
                    bit.update(i,-a[i]);
                    bit.update(j,a[i]);
                    a[j]+=a[i],a[i]=0;
                }
                pl=pl+p;
            }
            else
            {
                for(int i=pr-p,j=pr-p+1;j<=pr;i--,j++)
                {
                    bit.update(i,a[j]);
                    bit.update(j,-a[j]);
                    a[i]+=a[j],a[j]=0;
                }
                pr=pr-p;
            }
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(!rev)l=pl+l,r=pl+r-1;
            else l=pr-l,r=pr-r+1,swap(l,r);
            printf("%d\n",bit.query(r)-bit.query(l-1));
        }
    }
    return 0;
}
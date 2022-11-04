#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,w;
int a[200005],b[200005];
int da[200005],db[200005];
int next[200005];
void kmp()
{
    next[1]=0;
    for(int i=1;i<w-1;i++)
    {
        int k=next[i];
        while(k!=0)
        {
            if(db[i+1]==db[k+1])
            {
                next[i+1]=k+1;
                break;
            }
            k=next[k];
        }
        if(k==0)
        {
            next[i+1] = (db[i+1]==db[1] ? 1 : 0);
        }
    }
}
int query()
{
    int p=0,res=0;
    for(int i=1;i<n;i++)
    {
        while(da[i]!=db[p+1] && p!=0)
        {
            p=next[p];
        }
        if(da[i]==db[p+1])
        {
            p++;
        }
        if(p==w-1)
        {
            res++;
            p=next[p];
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=w;i++)
    {
        scanf("%d",&b[i]);
    }
    if(w==1)printf("%d\n",n);
    else
    {
        for(int i=1;i<n;i++)
        {
            da[i]=a[i+1]-a[i];
        }
        for(int i=1;i<w;i++)
        {
            db[i]=b[i+1]-b[i];
        }
        kmp();
        printf("%d\n",query());
    }
    return 0;
}
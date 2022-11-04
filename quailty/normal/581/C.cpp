#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN];
struct dd
{
    int r,b;
    bool operator < (const dd &t)const
    {
        return b>t.b;
    }
}p[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        p[i].r=a[i]/10;
        p[i].b=a[i]%10;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
        if(p[i].b==0)break;
        if(k>10-p[i].b)
        {
            k-=10-p[i].b;
            p[i].b=10;
        }
        else p[i].b+=k;
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i].b==10)
        {
            p[i].r++;
            p[i].b=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=p[i].r;
    }
    ans+=k/10;
    printf("%d\n",min(ans,10*n));
    return 0;
}